#include "greaterrangetower.h"

const double RANGE_INCREASE = 1.5;

GreaterRangeTower::GreaterRangeTower(int x, int y, QGraphicsScene *game)
    : TowerActive(x, y, game, QPixmap(":/images/tower/greater_range_tower.jpg"))
{
    setAttackRange(getAttackRange() + RANGE_INCREASE);
}

void GreaterRangeTower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w)
{
    QGraphicsPixmapItem::paint(painter, option, w);
}

int GreaterRangeTower::getCost()
{
    return COST;
}
