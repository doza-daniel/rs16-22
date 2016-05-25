#ifndef GREATERRANGETOWER_H
#define GREATERRANGETOWER_H
#include "toweractive.h"
#include <QGraphicsScene>

extern const double RANGE_INCREASE;

class GreaterRangeTower : public TowerActive
{
public:
    GreaterRangeTower(int x, int y, QGraphicsScene *game);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w = Q_NULLPTR);
    static int getCost();
private:
    static const int COST = 35;
};

#endif // GREATERRANGETOWER_H
