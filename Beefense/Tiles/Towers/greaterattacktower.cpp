#include "greaterattacktower.h"

const int POWER_INCREASE = 2;


GreaterAttackTower::GreaterAttackTower(int x, int y, QGraphicsScene *game)
    : TowerActive(x, y, game, QPixmap(":/images/tower/greater_attack_tower.png"))
{
    setAttackPower(getAttackPower() + POWER_INCREASE);
}

void GreaterAttackTower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w)
{
    QGraphicsPixmapItem::paint(painter, option, w);
}

int GreaterAttackTower::getCost()
{
    return COST;
}
