#ifndef GREATERATTACKTOWER_H
#define GREATERATTACKTOWER_H
#include "toweractive.h"
#include <QGraphicsScene>

extern const int POWER_INCREASE;
class GreaterAttackTower : public TowerActive
{
public:
    GreaterAttackTower(int x, int y, QGraphicsScene *game);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w = Q_NULLPTR);
};

#endif // GREATERATTACKTOWER_H
