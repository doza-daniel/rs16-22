#include "projectile.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QDebug>
#include <QTransform>
#include "enemy.h"
#include "tower.h"
#include <QList>

Projectile::Projectile(QGraphicsItem *parent)
    : mParent(parent)
{
    //sets the image of the projectile and scales it accordingly
    setPixmap(QPixmap(":/map/images/tower/bullet.png"));

    //creates a timer, adds it to a slot which will be called periodically
    QTimer* moveTimer = new QTimer(this);
    connect(moveTimer,SIGNAL(timeout()),this,SLOT(move()));
    //set the periodic calls to be equal to shootingSpeed
    moveTimer->start(mShootingSpeed);

}


/*Used periodically to move the item in the correct posititon*/
void Projectile::move()
{
    //gets the current angle of rotation
    double angle = rotation();

     //get the x an d y coordinates
    double dy = mProjectileSpeed*qSin(qDegreesToRadians(angle));
    double dx = mProjectileSpeed*qCos(qDegreesToRadians(angle));

    //move the proejctile accordingly
    setPos(x()+dx, y()+dy);

    //get the collisions and destory any enemies that are in contact with the projectile
    checkForHit();

    // implement a check if bullet is out of bounds, and delete it
}

void Projectile::checkForHit()
{
    //get all the coliding items and if it's an enemy delete it and the projectile
    QList<QGraphicsItem*> colidingItems = this->collidingItems();
    for(auto &e:colidingItems){
        Enemy* tmp = dynamic_cast<Enemy*>(e);
        if(tmp){
            //check the center of enemy to center of bullet
            if(this->collidesWithItem(e)){
                delete tmp;
                delete this;
            }
        }
    }
}
