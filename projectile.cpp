#include "projectile.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>

Projectile::Projectile(QGraphicsItem *parent)
{
    //sets the image of the projectile
    setPixmap(QPixmap(":/map/images/Tower/bullet.png"));

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
}
