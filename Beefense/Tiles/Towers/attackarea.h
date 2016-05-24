#ifndef ATTACKAREA_H
#define ATTACKAREA_H

#include "Tiles/tile.h"

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include <QPen>

class TowerActive;
extern const double ATTACK_RANGE_SIZE;

class AttackArea
{
public:
    AttackArea(TowerActive *tower, QGraphicsScene *scene);
    ~AttackArea();
    QList<QGraphicsItem *> collidingItems(Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const;
    bool collidesWithItem(const QGraphicsItem * other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const;
    bool collidesWithPath(const QPainterPath & path, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const;

    void setRange(double r);
    double getRange() const;
    void show();
    void hide();


private:
    QGraphicsEllipseItem *mArea;
    TowerActive *mTower;
//    QGraphicsScene *mScene;
    double mRange = ATTACK_RANGE_SIZE;

    void allignWithTower();
};

#endif // ATTACKAREA_H
