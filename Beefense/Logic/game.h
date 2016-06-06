#ifndef GAME_H
#define GAME_H

#include "Logic/map.h"
#include "Logic/enemy.h"
#include "Tiles/Towers/toweractive.h"
#include "Tiles/Towers/towertile.h"
#include "Logic/level.h"
#include "spawner.h"

#include <QGraphicsScene>
#include <QObject>
#include <QRectF>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QVector>
#include <QGraphicsSimpleTextItem>

class Game : public QGraphicsScene
{
    Q_OBJECT
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
public slots:
    void calculateGold();

private:
    void initView();
    void initLevel(int level);
    void initGoldCalculator();
    QGraphicsView mView;
    Level mLevel;
    Spawner *mSpawner;
    QGraphicsSimpleTextItem *mGoldItem;
    QTimer *mAdvanceTimer;
};

#endif // GAME_H
