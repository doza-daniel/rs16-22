#ifndef GAME_H
#define GAME_H

#include "Logic/map.h"
#include "Logic/enemy.h"
#include "Tiles/Towers/toweractive.h"
#include "Tiles/Towers/towertile.h"
#include "Logic/level.h"

#include <QGraphicsScene>
#include <QObject>
#include <QRectF>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QVector>



extern const int WAVE_SPAWN_TIME;

class Game : public QGraphicsScene
{
public:
    Game(const QRectF & sceneRect, int level = 1, QObject * parent = 0);
    Game(qreal x, qreal y, qreal width, qreal height, int level = 1, QObject * parent = 0);
    ~Game();

    Map getMap() const;
    void showMap();
    void show();
    void setWaveSpawnTime(int n);
    int getWaveSpawnTime() const;
    void setGold(int gold);
    int getGold();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    void initView();
    QGraphicsView mView;
    int mWaveSpawnTime = WAVE_SPAWN_TIME;
    int mGold = 100;
    Level mLevel;
};

#endif // GAME_H
