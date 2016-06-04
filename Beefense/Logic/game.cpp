#include "game.h"
#include "spawner.h"
#include "Tiles/Towers/projectile.h"
#include "Tiles/Towers/greaterattacktower.h"
#include "Tiles/Towers/greaterrangetower.h"

#include <QTimer>
#include <QPainter>
#include <iostream>
#include <QGraphicsItem>
#include <QTransform>
#include <QDebug>
#include "Menu/destroytower.h"
#include "Menu/createtower.h"

QVector<Level *> levelList;

Game::Game(int level)
{
    initLevel(level);
    initView();
    showMap();

    Spawner *spawner = new Spawner(this, mLevel.getWaveSpawnTime(), mLevel.getWaves());
}

Game::~Game()
{

}

Map Game::getMap() const
{
    return *(mLevel.getMap());
}

void Game::showMap()
{
    QVector< QVector<Tile *> > m = mLevel.getMap()->getMap();
    for(int i = 0; i < m.size(); ++i) {
        for(int j = 0; j < m[i].size(); ++j) {
            addItem(m[i][j]);
        }
    }
}

void Game::show()
{
    mView.show();
}

void Game::setWaveSpawnTime(int n)
{
    mLevel.setWaveSpawnTime(n);
}

int Game::getWaveSpawnTime() const
{
    return mLevel.getWaveSpawnTime();
}

int Game::getGold()
{
    return mLevel.getGold();
}
void Game::setGold(int gold){
    mLevel.setGold(gold);
}

void Game::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem *tmp = itemAt(event->scenePos().x(), event->scenePos().y(), QTransform());
    if(tmp) {
        TowerTile *pasive = dynamic_cast<TowerTile*>(tmp);
        TowerActive *active = dynamic_cast<TowerActive*>(tmp);
        if(pasive){
            QPointF pos = pasive->pos();


            CreateTower interface;
            interface.setParameters(pos,this,pasive);
            interface.exec();

        } else if(active) {
            QPointF pos = active->pos();

            DestroyTower interface;
            interface.setParameters(pos,this,active);
            interface.exec();
        }
    }
}

void Game::initView()
{
    mView.setScene(this);
    setSceneRect(0, 0, TILE_DIM * mLevel.getMap()->getCols(),
                 mLevel.getMap()->getRows() * TILE_DIM);
    mView.setRenderHint(QPainter::Antialiasing);
    mView.setFixedHeight(this->height());
    mView.setFixedWidth(this->width());
    mView.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mView.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Game::initLevel(int level)
{
    levelList = Level::getLevels(":/levels/levels.xml");
    bool levelSet = false;
    for(Level *l : levelList) {
        if(l->getNumber() == level) {
            mLevel = *(l);
            levelSet = true;
        }
    }
    if(!levelSet) {
        qDebug() << "Level " << level << " does not exist!";
        exit(EXIT_FAILURE);
    }
}
