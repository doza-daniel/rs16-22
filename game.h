#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QObject>
#include <QRectF>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include "map.h"
#include "enemy.h"


class Game : public QGraphicsScene
{
public:
    Game(const QRectF & sceneRect, QObject * parent = 0);
    Game(qreal x, qreal y, qreal width, qreal height, QObject * parent = 0);

    Map getMap() const;
    void showMap();
    void show();

    /*Pavle's test*/
    void mousePressEvent(QGraphicsSceneMouseEvent* e) Q_DECL_OVERRIDE;

private:
    void initView();
    QGraphicsView mView;
    Map mMap;
};

#endif // GAME_H
