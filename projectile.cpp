#include "projectile.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QDebug>
#include <QTransform>
#include "enemy.h"
#include "tower.h"
#include <QList>

Projectile::Projectile(Enemy *target)
    : mTarget(target),
      mMoveTimer(this)
{
    //sets the image of the projectile and scales it accordingly
    setPixmap(QPixmap(":/map/images/tower/bullet.png"));

    //creates a timer, adds it to a slot which will be called periodically
    connect(&mMoveTimer, SIGNAL(timeout()), this,  SLOT(move()));
    //set the periodic calls to be equal to shootingSpeed
    mMoveTimer.start(mShootingSpeed);

}

void Projectile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w)
{
    QGraphicsPixmapItem::paint(painter, option, w);
    /*painter->setBrush(Qt::red);
    painter->drawPath(this->shape());*/
}

QPainterPath Projectile::shape() const
{
    QVector<QPointF> pts;
    pts << QPointF(0, 0) << QPointF(2, 1) << QPointF(0, 2);
    for(auto &p: pts)
        p *= 10;
    QPainterPath path;
    path.addPolygon(QPolygonF(pts));
    return path;

    //krug shape, ne radi
    /*QPainterPath path;
    path.addEllipse(QPointF(12.5, 12.5), 6, 6);
    return path;*/
}


/*Used periodically to move the item in the correct posititon*/
void Projectile::move()
{
    if(!mTarget) {
        delete this;
    }
    QLineF ln(mapToScene(10, 10), mTarget->mapToScene(mTarget->getCenter()));
    QTransform m;
    m.translate(-12.5, -12.5);
    m.rotate(-1 * ln.angle());
    m.translate(12.5, 12.5);
    setTransform(m);
    //gets the current angle of rotation
    double angle = -1 * ln.angle();

     //get the x an d y coordinates
    double dy = mProjectileSpeed * qSin(qDegreesToRadians(angle));
    double dx = mProjectileSpeed * qCos(qDegreesToRadians(angle));

    //move the proejctile accordingly
    moveBy(dx, dy);

    //get the collisions and destory any enemies that are in contact with the projectile
    checkForHit();

    // implement a check if bullet is out of bounds, and delete it

}

void Projectile::checkForHit()
{
    if(!mTarget)
        return;
    if(collidesWithItem(mTarget)) {
        delete mTarget;
        delete this;
    }
    //get all the coliding items and if it's an enemy delete it and the projectile
   /*QList<QGraphicsItem*> colidingItems = this->collidingItems();
    for(auto &e:colidingItems){
        Enemy* tmp = dynamic_cast<Enemy*>(e);
        if(tmp){
            //check the center of enemy to center of bullet
            if(this->collidesWithItem(e)){
                delete tmp;
                delete this;
            }
        }
    }*/
}
