#include "slowtower.h"

SlowTower::SlowTower(int x, int y, QGraphicsScene *game, const QPixmap &pic):
    TowerActive(x,y,game,pic)
{

}

Projectile* SlowTower::createProjectile(Enemy *target)
{
    return new SlowingProjectile(mGame,target,mAttackPower);
}

int SlowTower::getCost()
{
    return COST;
}
