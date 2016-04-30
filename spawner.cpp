#include "spawner.h"
#include "game.h"
#include <QDebug>

const int SPAWN_TIME = 1000;

Spawner::Spawner(Game *game)
    :mGame(game)
{
}

void Spawner::spawnEnemy()
{
    Enemy *enemy = new Enemy(mGame->getMap().getStart()->x(), mGame->getMap().getStart()->y(), mGame->getMap().getPath());
    mGame->addItem(enemy);
}


