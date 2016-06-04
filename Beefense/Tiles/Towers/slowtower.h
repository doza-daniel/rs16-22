#ifndef SLOWTOWER_H
#define SLOWTOWER_H
#include "toweractive.h"
#include "projectile.h"
#include "slowingprojectile.h"

class SlowTower: public TowerActive
{
public:
   SlowTower(int x, int y, QGraphicsScene *game, const QPixmap &pic = QPixmap(":/images/tower/tower_slow.png"));

   Projectile* createProjectile(Enemy *target);
};

#endif // SLOWTOWER_H
