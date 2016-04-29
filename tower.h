#ifndef TOWER_H
#define TOWER_H
#include "towertile.h"
#include <QGraphicsPolygonItem>

class Tower: public TowerTile{
public:
    Tower(int x,int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w = Q_NULLPTR) Q_DECL_OVERRIDE;
private:
    QGraphicsPolygonItem* mAttackArea;
    QGraphicsPolygonItem* createPolygon();
    void centerPolygon();
};

#endif // TOWER_H
