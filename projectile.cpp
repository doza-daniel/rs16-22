#include "projectile.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QDebug>
#include <QTransform>
#include "enemy.h"
#include <QList>

Projectile::Projectile(QGraphicsItem *parent)
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
}

void Projectile::checkForHit()
{
    //get all the coliding items and if it's an enemy delete it and the projectile
    QList<QGraphicsItem*> colidingItems = this->collidingItems();
    for(auto &e:colidingItems){
        Enemy* tmp = dynamic_cast<Enemy*>(e);
        if(tmp){
            //check the center of enemy to center of bullet
            if(e->mapToScene(e->boundingRect()).contains(e->mapToScene(e->boundingRect().center()))){
                delete tmp;
                delete this;
            }
        }
    }
}
