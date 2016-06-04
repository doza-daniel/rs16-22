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

class Game : public QGraphicsScene
{
public:
    Game(int level);
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
    void initLevel(int level);
    QGraphicsView mView;
    Level mLevel;
};

#endif // GAME_H
