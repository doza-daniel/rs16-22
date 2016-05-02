#ifndef TOWER_H
#define TOWER_H
#include "towertile.h"
#include "enemy.h"
#include <QGraphicsPolygonItem>
#include <QGraphicsScene>
#include <QObject>

class Tower: public QObject, public TowerTile{
    Q_OBJECT
public:
    Tower(int x, int y, QGraphicsScene &game);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w = Q_NULLPTR) Q_DECL_OVERRIDE;
    void setAttackSpeed(int attackSpeed);
    QGraphicsPolygonItem* getAttackArea() const;
public slots:
    void acquireTarget();
private:
    QGraphicsPolygonItem* mAttackArea;
    QPointF mAttackDest;
    QGraphicsScene &mGame;
    int mAttackSpeed = 1000;
    bool mTargetAcquired;
    QGraphicsPolygonItem* createPolygon();
    double distanceToItem(QGraphicsItem* item);
    void attackTarget(Enemy *target);
    void centerPolygon();
    double HALF_BULLET = 12.5;
};

#endif // TOWER_H
