#ifndef TOWER_H
#define TOWER_H
#include "towertile.h"
#include "enemy.h"
#include <QGraphicsPolygonItem>
#include <QObject>
#include <QGraphicsScene>

class TowerActive: public QObject, public Tile
{
    Q_OBJECT
public:
    TowerActive(int x, int y, QGraphicsScene &game);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w = Q_NULLPTR) Q_DECL_OVERRIDE;
    void setAttackSpeed(int attackSpeed);
    QGraphicsPolygonItem* getAttackArea() const;
public slots:
    void acquireTarget();
private:
    QGraphicsPolygonItem* mAttackArea;
    QPointF mAttackDest;
    int mAttackSpeed = 1000;
    QGraphicsScene &mGame;
    bool mTargetAcquired;
    double mPolygonScale = 1.5;
    QGraphicsPolygonItem* createPolygon();
    double distanceToItem(QGraphicsItem* item);
    void attackTarget(Enemy *target);
    void centerPolygon();
};

#endif // TOWER_H
