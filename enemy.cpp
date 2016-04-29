#include "enemy.h"
#include <QtMath>
#include <QLineF>

Enemy::Enemy(qreal x, qreal y, QVector<QPointF *> path, int dim)
    : mPath(path),
      mWaypoint(0),
      mDimension(dim)
{
    setPos(x, y);
}

QRectF Enemy::boundingRect() const
{
    return QRectF(0, 0, mDimension, mDimension);
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect().center().x() - 10, boundingRect().center().y() - 5, 20, 10);
}

void Enemy::advance(int)
{
    if(mWaypoint >= mPath.size())
        return;
    QRectF tmp = mapRectToScene(boundingRect());
    QLineF line(tmp.center(), *(mPath[mWaypoint]));

    if(line.length() < 2)
        mWaypoint++;

    QTransform m;
    m.translate(TILE_DIM / 2, TILE_DIM / 2);
    m.rotate(-line.angle());
    m.translate(-TILE_DIM / 2, -TILE_DIM / 2);
    setTransform(m);

    moveBy(2 * qCos(qDegreesToRadians(-1 * line.angle())), 2 * qSin(qDegreesToRadians(-1 * line.angle())));
}
