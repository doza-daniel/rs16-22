#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QObject>
#include <QRectF>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include "map.h"
#include "enemy.h"
#include "tower.h"
#include "towertile.h"
#include <QPointF>

extern const int WAVE_SPAWN_TIME;

class Game : public QGraphicsScene
{
public:
    Game(const QRectF & sceneRect, int waveSpawnTime = WAVE_SPAWN_TIME, QObject * parent = 0);
    Game(qreal x, qreal y, qreal width, qreal height, int waveSpawnTime = WAVE_SPAWN_TIME, QObject * parent = 0);

    Map getMap() const;
    void showMap();
    void show();
    void setWaveSpawnTime(int n);
    int getWaveSpawnTime() const;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    void initView();
    QGraphicsView mView;
    Map mMap;
    int mWaveSpawnTime;
};

#endif // GAME_H
