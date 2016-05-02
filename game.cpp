#include "game.h"
#include "spawner.h"
#include <QTimer>
#include <QPainter>
#include <iostream>
#include "projectile.h"

const int WAVE_SPAWN_TIME = 5000;

Game::Game(const QRectF &sceneRect, int waveSpawnTime, QObject *parent)
    : QGraphicsScene(sceneRect, parent),
      mView(this),
      mMap(this->height() / TILE_DIM, this->width() / TILE_DIM),
      mWaveSpawnTime(waveSpawnTime)
{
    initView();
    showMap();

    Spawner *intervalSpawner = new Spawner(this);
    QTimer *spawnInterval = new QTimer();
    QObject::connect(spawnInterval, SIGNAL(timeout()), intervalSpawner, SLOT(intervalSpawn()));
    spawnInterval->start(mWaveSpawnTime);

    QTimer *moveTimer = new QTimer();
    QObject::connect(moveTimer, SIGNAL(timeout()), this, SLOT(advance()));
    moveTimer->start(MOVEMENT_SPEED);
}

Game::Game(qreal x, qreal y, qreal width, qreal height, int waveSpawnTime, QObject *parent)
    : QGraphicsScene(x, y, width, height, parent),
      mView(this),
      mMap(this->height() / TILE_DIM, this->width() / TILE_DIM),
      mWaveSpawnTime(waveSpawnTime)
{
    initView();
    showMap();

    Spawner *intervalSpawner = new Spawner(this);
    QTimer *spawnInterval = new QTimer();
    QObject::connect(spawnInterval, SIGNAL(timeout()), intervalSpawner, SLOT(intervalSpawn()));
    spawnInterval->start(mWaveSpawnTime);

    QTimer *moveTimer = new QTimer();
    QObject::connect(moveTimer, SIGNAL(timeout()), this, SLOT(advance()));
    moveTimer->start(MOVEMENT_SPEED);
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

void Game::initView()
{
    // mView.setRenderHint(QPainter::Antialiasing);
    mView.setFixedHeight(this->height());
    mView.setFixedWidth(this->width());
    mView.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mView.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
