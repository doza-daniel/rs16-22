#ifndef TOWERACTIVE_H
#define TOWERACTIVE_H

#include "towertile.h"
#include "Logic/enemy.h"
#include "attackarea.h"

#include <QGraphicsPolygonItem>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneHoverEvent>
#include <QTimer>

extern const int ATTACK_SPEED;
extern const int ATTACK_POWER;

class TowerActive: public QObject, public Tile
{
    Q_OBJECT
public:
    TowerActive(int x, int y, QGraphicsScene *game);
    ~TowerActive();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w = Q_NULLPTR) Q_DECL_OVERRIDE;
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event) Q_DECL_OVERRIDE;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event) Q_DECL_OVERRIDE;

    void setAttackSpeed(int attackSpeed);
    int getAttackSpeed() const;
    void setAttackPower(int attackPower);
    int getAttackPower() const;

public slots:
    void acquireTarget();
private:
    AttackArea mAttackArea;
    QGraphicsScene *mGame;
    QTimer mAttackTimer;
    bool mTargetAcquired;

    int mAttackSpeed = ATTACK_SPEED;
    int mAttackPower = ATTACK_POWER;

    double distanceToItem(QGraphicsItem *item);
    void attackTarget(Enemy *target);
};

#endif // TOWERACTIVE_H
