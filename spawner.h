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
    void intervalSpawn();
private:
    Game *mGame;
    int mEnemiesSpawned;
    QTimer *mWaveTimer;
};

#endif // SPAWNER_H
