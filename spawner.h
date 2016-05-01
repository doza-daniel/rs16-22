#ifndef SPAWNER_H
#define SPAWNER_H

#include <QGraphicsScene>
#include "enemy.h"

extern const int SPAWN_TIME;

class Game;

class Spawner : public QObject
{
      Q_OBJECT
public:
    Spawner(Game *game);
public slots:
    void spawnEnemy();
private:
    Game *mGame;
};

#endif // SPAWNER_H
