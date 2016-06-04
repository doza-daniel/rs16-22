#include "spawner.h"
#include "game.h"

#include <QDebug>
#include <QTimer>

const int SPAWN_TIME = 500;
const int SPAWN_N = 5;

Spawner::Spawner(Game *game, int spawnTime, int numWaves)
    :mGame(game), mEnemiesSpawned(0), mWaveTimer(nullptr), mNumWaves(numWaves), mWaves(0)

{
    this->intervalSpawn();
    QTimer *spawnInterval = new QTimer();
    QObject::connect(spawnInterval, SIGNAL(timeout()), this, SLOT(intervalSpawn()));
    spawnInterval->start(spawnTime*1000);
}

void Spawner::spawnEnemy()
{
    if(mEnemiesSpawned == SPAWN_N) {
        if(mWaveTimer != nullptr)
            delete mWaveTimer;
        mEnemiesSpawned = 0;
    }
    Enemy *enemy;
    if(mWaves <= mNumWaves / 2 + 1) {
        enemy = new Enemy(EnemyType::Bee, mGame->getMap().getStart()->x(), mGame->getMap().getStart()->y(), mGame->getMap().getPath());
    } else {
        enemy = new Enemy(EnemyType::AngryBee, mGame->getMap().getStart()->x(), mGame->getMap().getStart()->y(), mGame->getMap().getPath());
    }
    mGame->addItem(enemy);
    mEnemiesSpawned++;
}

void Spawner::intervalSpawn()
{
    if(mWaves != mNumWaves) {
        mWaveTimer = new QTimer();
        QObject::connect(mWaveTimer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
        mWaveTimer->start(SPAWN_TIME);
        mWaves++;
    }
}


