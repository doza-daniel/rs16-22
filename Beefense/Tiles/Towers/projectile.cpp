#include "projectile.h"
#include "Logic/enemy.h"
#include "toweractive.h"

#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QDebug>
#include <QTransform>
#include <QList>

const int SHOOTING_SPEED = 7;
const int PROJECTILE_SPEED = 3;

Projectile::Projectile(QGraphicsScene *game,Enemy *target, int attackPower, int dim)
    : mTarget(target),
      mAttackPower(attackPower),
      mTip(dim, dim / 2),
      mDimension(dim),
      mMoveTimer(this),
      mGame(game)
{
    //sets the image of the projectile and scales it accordingly
    setPixmap(QPixmap(":/images/tower/bullet.png").scaled(dim + 4, dim + 4));

    //creates a timer, adds it to a slot which will be called periodically
    connect(&mMoveTimer, SIGNAL(timeout()), this,  SLOT(move()));
    //set the periodic calls to be equal to shootingSpeed
    mMoveTimer.start(mShootingSpeed);

    //if there is a target, catch it's destroy signal
    if(target)
        connect(mTarget, SIGNAL(destroyed()), this, SLOT(targetDestroyed()));
}

int Projectile::getShootingSpeed() const
{
    return mShootingSpeed;
}

int Projectile::getProjectileSpeed() const
{
    return mProjectileSpeed;
}

int Projectile::getDimension() const
{
    return mDimension;
}

void Projectile::setAttackPower(int attackPower)
{
    mAttackPower = attackPower;
}

int Projectile::getAttackPower() const
{
    return mAttackPower;
}

void Projectile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w)
{
    QGraphicsPixmapItem::paint(painter, option, w);
//    painter->setBrush(Qt::red);
//    painter->drawPath(this->shape());
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
    //check to see if the target isn't destroyed
    if(!mTarget){
        delete this;
        return;
    }

    QLineF ln(mapToScene(mTip), mTarget->mapToScene(mTarget->getCenter()));
    //gets the current angle of rotation
    double angle = -1 * ln.angle();

    //transformation for the angle of the bullet
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

/*Checks for the projectile and enemy collision and adjusts the health of the target that was hit*/
void Projectile::checkForHit()
{
    if(collidesWithItem(mTarget)) {
        int currHealth = mTarget->getHealth();
        currHealth -= mAttackPower;
        if(currHealth <= 0){
            Game *g = dynamic_cast<Game*>(mGame);
            g->setGold(g->getGold()+mTarget->getWorth());
            delete mTarget;
        }
        else{
            mTarget->setHealth(currHealth);
        }
        delete this;
    }
}

/*Defines what happens to the bullet when the target is destroyed*/
void Projectile::targetDestroyed()
{
    mTarget = nullptr;
}
