#ifndef ATTACKAREA_H
#define ATTACKAREA_H

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>

#include "tile.h"

class TowerActive;
extern const int ATTACK_RANGE_SIZE;

class AttackArea
{
public:
    AttackArea(TowerActive *tower, QGraphicsScene *scene);
    ~AttackArea();
    void setRange(int r);
    QList<QGraphicsItem *> collidingItems(Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const;
    bool collidesWithItem(const QGraphicsItem * other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const;
    bool collidesWithPath(const QPainterPath & path, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const;

private:
    QGraphicsEllipseItem *mArea;
    TowerActive *mTower;
//    QGraphicsScene *mScene;
    int mRange = ATTACK_RANGE_SIZE;

    void allignWithTower();
};

#endif // ATTACKAREA_H
