#ifndef SPAWNER_H
#define SPAWNER_H

#include "enemy.h"
#include "enumhead.h"

#include <QGraphicsScene>

extern const int SPAWN_TIME;

class Game;

class Spawner : public QObject
{
      Q_OBJECT
public:
    Spawner(Game *game, int spawnTime, int numWaves);
public slots:
    void spawnEnemy();
    void intervalSpawn();
private:
    Game *mGame;
    QTimer *mWaveTimer;
    int mSpawnTime;
    int mEnemiesSpawned;
    int mNumWaves;
    int mWaves;
};

#endif // SPAWNER_H
