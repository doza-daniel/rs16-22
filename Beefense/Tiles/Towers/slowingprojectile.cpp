#include "slowingprojectile.h"

SlowingProjectile::SlowingProjectile(QGraphicsScene *game, Enemy *target, int attackPower, int dim):
    Projectile(game,target,attackPower,dim)
{

}

void SlowingProjectile::targetHit(int currHealth)
{
    mTarget->setHealth(currHealth);
    mTarget->setMovementSpeed(mTarget->getMovementSpeed()*0.5);
}
