#ifndef SLOWINGPROJECTILE_H
#define SLOWINGPROJECTILE_H
#include "projectile.h"

class SlowingProjectile: public Projectile
{
public:
   SlowingProjectile(QGraphicsScene *game,Enemy* target, int attackPower = 1, int dim = TILE_DIM / 4);

    void targetHit(int currHealth);
};

#endif // SLOWINGPROJECTILE_H
