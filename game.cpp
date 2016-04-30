#include "game.h"
#include "spawner.h"
#include <QTimer>
#include <QPainter>
#include <iostream>
#include "projectile.h"


Game::Game(const QRectF &sceneRect, QObject *parent)
    : QGraphicsScene(sceneRect, parent),
      mView(this),
      mMap(this->height() / TILE_DIM, this->width() / TILE_DIM)
{
    initView();
    showMap();

    Spawner *enemySpawner = new Spawner(this);
    QTimer *spawnTimer = new QTimer();
    QObject::connect(spawnTimer, SIGNAL(timeout()), enemySpawner, SLOT(spawnEnemy()));
    spawnTimer->start(2000);

    QTimer *moveTimer = new QTimer();
    QObject::connect(moveTimer, SIGNAL(timeout()), this, SLOT(advance()));
    moveTimer->start(50);
}

Game::Game(qreal x, qreal y, qreal width, qreal height, QObject *parent)
    : QGraphicsScene(x, y, width, height, parent),
      mView(this),
      mMap(this->height() / TILE_DIM, this->width() / TILE_DIM)
{
    initView();
    showMap();

    Spawner *enemySpawner = new Spawner(this);
    QTimer *spawnTimer = new QTimer();
    QObject::connect(spawnTimer, SIGNAL(timeout()), enemySpawner, SLOT(spawnEnemy()));
    spawnTimer->start(2000);

    QTimer *moveTimer = new QTimer();
    QObject::connect(moveTimer, SIGNAL(timeout()), this, SLOT(advance()));
    moveTimer->start(50);
}

Map Game::getMap() const
{
    return mMap;
}

void Game::showMap()
{
    QVector< QVector<Tile *> > m = mMap.getMap();
    for(int i = 0; i < m.size(); ++i) {
        for(int j = 0; j < m[i].size(); ++j) {
            addItem(m[i][j]);
        }
    }
}

/*Pavle's test*/
void Game::mousePressEvent(QGraphicsSceneMouseEvent* e)
{
    Projectile* bullet = new Projectile();
    bullet->setPos(bullet->mapToScene(e->pos()));
    this->addItem(bullet);
}

void Game::show()
{
    mView.show();
}

void Game::initView()
{
    // mView.setRenderHint(QPainter::Antialiasing);
    mView.setFixedHeight(this->height());
    mView.setFixedWidth(this->width());
    mView.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mView.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
