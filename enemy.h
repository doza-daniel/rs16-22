#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsItem>
#include <QRectF>
#include "tile.h"

extern const int MOVEMENT_SPEED;

class Enemy : public QGraphicsItem
{
public:
    Enemy(qreal x, qreal y, QVector<QPointF *> path, int dim = TILE_DIM);
    ~Enemy();


    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
    QPointF getCenter() const;
    QPainterPath shape() const Q_DECL_OVERRIDE;

protected slots:
    void advance(int phase) Q_DECL_OVERRIDE;

private:
    QVector<QPointF *> mPath;
    int mWaypoint;
    int mDimension;
    QPointF mCenter;
};

#endif // ENEMY_H
