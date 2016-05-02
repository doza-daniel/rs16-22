#include "projectile.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QDebug>
#include <QTransform>
#include "enemy.h"
#include "tower.h"
#include <QList>

Projectile::Projectile(Enemy *target, int dim)
    : mTarget(target),
      mTip(dim, dim / 2),
      mDimension(dim),
      mMoveTimer(this)
{
    //sets the image of the projectile and scales it accordingly
    setPixmap(QPixmap(":/map/images/tower/bullet.png"));

    //creates a timer, adds it to a slot which will be called periodically
    connect(&mMoveTimer, SIGNAL(timeout()), this,  SLOT(move()));
    //set the periodic calls to be equal to shootingSpeed
    mMoveTimer.start(mShootingSpeed);
}

int Projectile::getDimension() const
{
    return mDimension;
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
    pts << QPointF(0, 0) << QPointF(1, 0.5) << QPointF(0, 1);
    for(auto &p: pts)
        p *= mDimension;

    QPainterPath path;
    path.addPolygon(QPolygonF(pts));
    return path;
}


/*Used periodically to move the item in the correct posititon*/
void Projectile::move()
{
    if(mTarget == nullptr) {
        return;
    }
    QLineF ln(mapToScene(mTip), mTarget->mapToScene(mTarget->getCenter()));
    //gets the current angle of rotation
    double angle = -1 * ln.angle();

    // ovde bi trebalo prvo + pa - ali onda baguje, ne znam sto
    QTransform m;
    m.translate(-mDimension / 2, +mDimension / 2);
    m.rotate(angle + 180);
    m.translate(mDimension / 2, mDimension / 2);
    setTransform(m);



     //get the x an d y coordinates
    double dy = mProjectileSpeed * qSin(qDegreesToRadians(angle));
    double dx = mProjectileSpeed * qCos(qDegreesToRadians(angle));

    //move the proejctile accordingly
    moveBy(dx, dy);

    //get the collisions and destory any enemies that are in contact with the projectile
    checkForHit();
}

void Projectile::checkForHit()
{
    if(!mTarget)
        return;
    if(collidesWithItem(mTarget)) {
        delete mTarget;
        delete this;
    }
}
