#ifndef SLOWTOWER_H
#define SLOWTOWER_H
#include "toweractive.h"
#include "projectile.h"
#include "slowingprojectile.h"

class SlowTower: public TowerActive
{
public:
   SlowTower(int x, int y, QGraphicsScene *game, const QPixmap &pic = QPixmap(":/images/tower/slow_tower.png"));

   Projectile* createProjectile(Enemy *target);
   static int getCost();
private:
   static const int COST = 50;
};

#endif // SLOWTOWER_H
