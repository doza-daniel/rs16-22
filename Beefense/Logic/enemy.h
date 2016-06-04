#ifndef ENEMY_H
#define ENEMY_H

#include "Tiles/tile.h"
#include "enumhead.h"

#include <QGraphicsPixmapItem>
#include <QRectF>
#include <QObject>
#include <QPixmap>


extern const int MOVEMENT_SPEED;


class Enemy : public QObject, public QGraphicsPixmapItem
{

public:
    Enemy(qreal x, qreal y, QVector<QPointF *> path, int dim = TILE_DIM);
    Enemy(EnemyType type,qreal x, qreal y, QVector<QPointF *> path, int dim = TILE_DIM);
    ~Enemy();
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPointF getCenter() const;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void setHealth(int health);
    int getHealth();
    int getWorth();
    void setWorth(int worth);
    void setMovementSpeed(int ms);
    int getMovementSpeed();

protected slots:
    void advance(int phase) Q_DECL_OVERRIDE;

private:
    QVector<QPointF *> mPath;
    QPointF mCenter;
    int mWaypoint;
    int mDimension;
    int mHealth = 3;
    int mWorth = 5;
    int mMs = MOVEMENT_SPEED;
};

#endif // ENEMY_H
