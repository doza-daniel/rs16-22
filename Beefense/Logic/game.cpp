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

const int WAVE_SPAWN_TIME = 10000;
QVector<Level *> levelList;

Game::Game(const QRectF &sceneRect, int level, QObject *parent)
    : QGraphicsScene(sceneRect, parent),
      mView(this)
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
    initView();
    showMap();

    Spawner *intervalSpawner = new Spawner(this);
    intervalSpawner->intervalSpawn();
    QTimer *spawnInterval = new QTimer();
    QObject::connect(spawnInterval, SIGNAL(timeout()), intervalSpawner, SLOT(intervalSpawn()));
    spawnInterval->start(mWaveSpawnTime);

    QTimer *moveTimer = new QTimer();
    QObject::connect(moveTimer, SIGNAL(timeout()), this, SLOT(advance()));
    moveTimer->start(MOVEMENT_SPEED);
}


Game::Game(qreal x, qreal y, qreal width, qreal height, int level, QObject *parent)
    : QGraphicsScene(x, y, width, height, parent),
      mView(this)
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
    initView();
    showMap();

    Spawner *intervalSpawner = new Spawner(this);
    intervalSpawner->intervalSpawn();
    QTimer *spawnInterval = new QTimer();
    QObject::connect(spawnInterval, SIGNAL(timeout()), intervalSpawner, SLOT(intervalSpawn()));
    spawnInterval->start(mWaveSpawnTime);

    QTimer *moveTimer = new QTimer();
    QObject::connect(moveTimer, SIGNAL(timeout()), this, SLOT(advance()));
    moveTimer->start(MOVEMENT_SPEED);
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
    mWaveSpawnTime = n;
}

int Game::getWaveSpawnTime() const
{
    return mWaveSpawnTime;
}

int Game::getGold()
{
    return mGold;
}
void Game::setGold(int gold){
    mGold = gold;
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
    // mView.setRenderHint(QPainter::Antialiasing);
    mView.setFixedHeight(this->height());
    mView.setFixedWidth(this->width());
    mView.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mView.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
