#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsPolygonItem>
#include <QLineF>
#include <QList>
#include <QDebug>

#include "projectile.h"
#include "enemy.h"
#include "toweractive.h"

const int ATTACK_SPEED = 1000;
const int ATTACK_POWER = 1;

TowerActive::TowerActive(int x, int y, QGraphicsScene *game)
    : QObject(),
      Tile(QPixmap(":/map/images/tower/tower_active.jpg"), TILE_DIM, x, y),
      mAttackArea(this, game),
      mGame(game),
      mAttackTimer(),
      mTargetAcquired(false)
{
    connect(&mAttackTimer, SIGNAL(timeout()), this, SLOT(acquireTarget()));
    mAttackTimer.start(mAttackSpeed);
    setAttackPower(5);
}

TowerActive::~TowerActive()
{
}

/*Paints the tower tile according to this function*/
void TowerActive::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w)
{
    QGraphicsPixmapItem::paint(painter, option, w);
    /*
    QColor grass(51, 204, 51);
    QColor tower(255, 255, 0);

    painter->setBrush(grass);
    painter->setPen(Qt::NoPen);

    painter->drawRect(mTile);

    painter->setBrush(tower);
    painter->drawEllipse(mCenter, TILE_DIM * 30 / 100, TILE_DIM * 30 / 100);
    */
}

void TowerActive::setAttackSpeed(int attackSpeed)
{
    mAttackSpeed = attackSpeed;
}

int TowerActive::getAttackSpeed() const
{
    return mAttackSpeed;
}

void TowerActive::setAttackPower(int attackPower)
{
    mAttackPower = attackPower;
}

int TowerActive::getAttackPower() const
{
    return mAttackPower;
}

void TowerActive::attackTarget(Enemy *target)
{   
    if(!target)
        return;
    //create a projectile
    Projectile* bullet = new Projectile(target, mAttackPower);
    int a = x() - (bullet->getDimension() / 2) + TILE_DIM / 2;
    int b = y() - (bullet->getDimension() / 2) + TILE_DIM / 2;
    bullet->setPos(QPointF(a, b));

    //create a line from which we can withdraw the angle
    QPointF dest(target->mapToScene(getCenter()));
    QLineF movingLine(QPointF(x() + TILE_DIM / 2, y() + TILE_DIM / 2), dest);

    //getting the angle from a line
    //HAX: -1 is used because the rotation returned is counter to the rotation needed
    int angle = -1 * movingLine.angle();
    bullet->setRotation(angle);

    mGame->addItem(bullet);
}

/*Used to detect collision between Enemy and mAttackRange polygon*/
void TowerActive::acquireTarget()
{
    //get all the coliding items
    QList<QGraphicsItem*> colidingItems = mAttackArea.collidingItems();

    //when there are no collisions the size is 1 ( tower in the middle )
    // figure out how to scale this 21 in terms of AttackArea::getRange()
    if(colidingItems.size() == 21){

        mTargetAcquired = false;
        return; //do nothing
    }

    //we need closest enemy and its point
    double closestDistance = 1000;
    Enemy *target = nullptr;

    //there are collisions, check if enemy is coliding
    for(auto &e:colidingItems) {
        //attempt to convert the GraphisItem to Enemy
        Enemy* tmp = dynamic_cast<Enemy*>(e);
        if(tmp) { //flase if tmp == nullptr, true if it is an Enemy
            double distanceTo = distanceToItem(tmp);
            if(distanceTo < closestDistance) { //if there is a closer enemy
                closestDistance = distanceTo; // new closest
                target = tmp;
                mTargetAcquired = true;
            }
        }
    }

    //now attack that target
    if(mTargetAcquired)
        attackTarget(target);

}

/*Returns the distance between an item and the tower */
double TowerActive::distanceToItem(QGraphicsItem *item)
{
    QLineF line(pos(), item->pos());
    return line.length();
}


