#include "enemy.h"

#include <QtMath>
#include <QLineF>
#include <QDebug>

const int MOVEMENT_SPEED = 50;

Enemy::Enemy(qreal x, qreal y, QVector<QPointF *> path, int dim)
    : mPath(path),
      mWaypoint(0),
      mDimension(dim)
{
    setPos(x, y);
    setPixmap(QPixmap(":/images/enemy/bee.png").scaled(dim - 13, dim - 13));
}

 Enemy::Enemy(EnemyType type,qreal x, qreal y, QVector<QPointF *> path, int dim)
    : mPath(path),
      mWaypoint(0),
      mDimension(dim)
{
    setPos(x, y);
    setOffset(0, 10);
    type == EnemyType::bee?
        setPixmap(QPixmap(":/images/enemy/bee.png").scaled(dim - 13, dim - 13))
              :
        setPixmap(QPixmap(":/images/enemy/angry_bee.png").scaled(dim - 13, dim - 13));
        setWorth(10);
        setHealth(8);
        setMaxHealth(8);
}

Enemy::~Enemy()
{

}

QRectF Enemy::boundingRect() const
{
    return QRectF(0, 0, mDimension, mDimension);
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

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w)
{
    QGraphicsPixmapItem::paint(painter, option, w);
    QGraphicsLineItem line;
    line.setLine(10, 5, 30, 5);
    line.setPen(QPen(QBrush(Qt::black), 5));
    line.paint(painter, option);

    QGraphicsLineItem healthLine;
    if(mMaxHealth == mHealth) {
        healthLine.setLine(10, 5, 30, 5);
        healthLine.setPen(QPen(QBrush(Qt::red), 2));
        healthLine.paint(painter, option);
    } else {
        healthLine.setLine(10, 5, mHealth*20/mMaxHealth + 10, 5);
        healthLine.setPen(QPen(QBrush(Qt::red), 2));
        healthLine.paint(painter, option);
    }
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

void Enemy::setWorth(int worth)
{
    mWorth = worth;
}

void Enemy::setMovementSpeed(int ms)
{
    mMs = ms;
}
int Enemy::getMovementSpeed(){
    return mMs;
}

void Enemy::setMaxHealth(int health)
{
    mMaxHealth = health;
}

int Enemy::getMaxHealth()
{
    return mMaxHealth;
}

int Enemy::getWorth(){
    return mWorth;
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
