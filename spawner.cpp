#include "spawner.h"
#include "game.h"
#include <QDebug>
#include <QTimer>

const int SPAWN_TIME = 500;
const int SPAWN_N = 4;

Spawner::Spawner(Game *game)
    :mGame(game), mEnemiesSpawned(0), mWaveTimer(nullptr)
{
}

void Spawner::spawnEnemy()
{
    if(mEnemiesSpawned == SPAWN_N) {
        if(mWaveTimer != nullptr)
            delete mWaveTimer;
        mEnemiesSpawned = 0;
    }
    Enemy *enemy = new Enemy(mGame->getMap().getStart()->x(), mGame->getMap().getStart()->y(), mGame->getMap().getPath());
    mGame->addItem(enemy);
    mEnemiesSpawned++;
}

void Spawner::intervalSpawn()
{
    mWaveTimer = new QTimer();
    QObject::connect(mWaveTimer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    mWaveTimer->start(SPAWN_TIME);
}


