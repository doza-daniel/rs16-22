#include "enemy.h"
#include <QtMath>
#include <QLineF>

const int MOVEMENT_SPEED = 50;

Enemy::Enemy(qreal x, qreal y, QVector<QPointF *> path, int dim)
    : mPath(path),
      mWaypoint(0),
      mDimension(dim)
{
    setPos(x, y);
}

Enemy::~Enemy()
{

}

QRectF Enemy::boundingRect() const
{
    return QRectF(0, 0, mDimension, mDimension);
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(getCenter().x() - 10, getCenter().y() - 5, 20, 10);
}

QPointF Enemy::getCenter() const
{
    return QPointF(boundingRect().center().x(), boundingRect().center().y());
}

QPainterPath Enemy::shape() const
{
    QPainterPath path;
    path.addEllipse(getCenter(), 8, 5);
    return path;
}

/*Sets the health of the enemy*/
void Enemy::setHealth(int health)
{
    mHealth = health;
}
/*Gets the health of the enemy*/
int Enemy::getHealth()
{
    return mHealth;
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
