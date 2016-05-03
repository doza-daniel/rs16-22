#include "tower.h"
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsPolygonItem>
#include <QLineF>
#include <QTimer>
#include <QList>
#include <QDebug>
#include "projectile.h"
#include "enemy.h"

TowerActive::TowerActive(int x, int y, QGraphicsScene &game)
    : QObject(),
      Tile(QPixmap(":/map/images/tower/tower_active.jpg"), TILE_DIM, x, y),
      mGame(game),
      mTargetAcquired(false)
{
    mAttackArea = createPolygon();
    mAttackArea->setZValue(900);
    setZValue(1000);

    centerPolygon();

    //test connect timer to attackTarget
    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(acquireTarget()));
    timer->start(mAttackSpeed);
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

QGraphicsPolygonItem *TowerActive::getAttackArea() const
{
    return mAttackArea;
}

void TowerActive::attackTarget(Enemy *target)
{   
    //create a projectile
    Projectile* bullet = new Projectile(target);
    int a = x() - (bullet->getDimension() / 2) + TILE_DIM / 2;
    int b = y() - (bullet->getDimension() / 2) + TILE_DIM / 2;
    bullet->setPos(QPointF(a, b));

    //create a line from which we can withdraw the angle
    QLineF movingLine(QPointF(x() + TILE_DIM / 2, y() + TILE_DIM / 2), mAttackDest);

    //getting the angle from a line
    //HAX: -1 is used because the rotation returned is counter to the rotation needed
    int angle = -1 * movingLine.angle();
    bullet->setRotation(angle);

    mGame.addItem(bullet);
}

/*Used to detect collision between Enemy and mAttackRange polygon*/
void TowerActive::acquireTarget()
{
    //get all the coliding items
    QList<QGraphicsItem*> colidingItems = mAttackArea->collidingItems();

    //when there are no collisions the size is 1 ( tower in the middle )
    if(colidingItems.size() == 21){

        mTargetAcquired = false;
        return; //do nothing
    }

    //we need closest enemy and its point
    double closestDistance = 1000;
    QPointF closestPoint = QPointF(0, 0);
    Enemy *target = nullptr;

    //there are collisions, check if enemy is coliding
    for(auto &e:colidingItems){
        //attempt to convert the GraphisItem to Enemy
        Enemy* tmp = dynamic_cast<Enemy*>(e);
        if(tmp){ //flase if tmp == nullptr, true if it is an Enemy
            double distanceTo = distanceToItem(tmp);
            if(distanceTo < closestDistance){ //if there is a closer enemy
                closestDistance = distanceTo; // new closest
                closestPoint = e->mapToScene(e->boundingRect().center()); // get the Point of the closest enemy
                target = tmp;
                mTargetAcquired = true;
            }
        }
    }

    //when we're done, we have to closest point to the enemy
    mAttackDest = closestPoint;
    //now attack that target
    if(mTargetAcquired)
        attackTarget(target);

}

/*Poitns for attack area (1,0) (2,0) (3,1) (3,2) (1,3) (0,2) (0,1)*/
/*Points are used in order to create a polygon that represents the tower range*/
QGraphicsPolygonItem* TowerActive::createPolygon(){

    QVector<QPointF> polyPts;
    polyPts << QPoint(1, 0)<< QPoint(2, 0)<< QPoint(3, 1)<< QPoint(3, 2)<< QPoint(2, 3)<< QPoint(1, 3)
            << QPoint(0, 2)<< QPoint(0, 1);

    //sacale to tile
    for(auto &p:polyPts){
        p = p * TILE_DIM * mPolygonScale;
    }

    //create scaled polygon
    QPolygonF polygon(polyPts);

    //this <- represents the parent so that polygon knows where to draw itself
    QGraphicsPolygonItem *poly = new QGraphicsPolygonItem(polygon, this);
    return poly;

}

/*Returns double, the distance between an item and the tower */
double TowerActive::distanceToItem(QGraphicsItem *item)
{
    QLineF line(pos(), item->pos());
    return line.length();
}

/*1.5 is the center of previously defined polygon*/
void TowerActive::centerPolygon(){
    QPointF polyCenter(1.5, 1.5);

    //scale the center point to fit the tile
    polyCenter *= TILE_DIM * mPolygonScale;

    //get the coordinates to be determined by the scene
    polyCenter = mapToScene(polyCenter);

    //create a line on which to move
    QLineF movingLine(polyCenter, mCenter);

    //finally set the attackArea coordinates accordingly
    mAttackArea->setPos(x() + movingLine.dx(), y() + movingLine.dy());
}
