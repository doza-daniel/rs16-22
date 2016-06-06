#include "slowtower.h"

SlowTower::SlowTower(int x, int y, QGraphicsScene *game, const QPixmap &pic):
    TowerActive(x,y,game,pic)
{

}

Projectile* SlowTower::createProjectile(Enemy *target)
{
    Projectile *p = new SlowingProjectile(mGame,target,mAttackPower);
    p->setColor(QColor(110, 226, 176));
    return p;
}

int SlowTower::getCost()
{
    return COST;
}
