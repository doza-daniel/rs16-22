#ifndef TOWERACTIVE_H
#define TOWERACTIVE_H

#include "towertile.h"
#include "Logic/enemy.h"
#include "attackarea.h"
//#include "projectile.h"
#include <QGraphicsPolygonItem>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneHoverEvent>
#include <QTimer>

extern const int ATTACK_SPEED;
extern const int ATTACK_POWER;
extern const int TOWER_Z_VALUE;
class Projectile;

class TowerActive: public QObject, public Tile
{
    Q_OBJECT
public:
    TowerActive(int x, int y, QGraphicsScene *game, const QPixmap &pic = QPixmap(":/images/tower/tower_active.png"));
    ~TowerActive();

    void hoverEnterEvent(QGraphicsSceneHoverEvent * event) Q_DECL_OVERRIDE;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event) Q_DECL_OVERRIDE;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w = Q_NULLPTR);


    void setAttackSpeed(int attackSpeed);
    int getAttackSpeed() const;
    void setAttackPower(int attackPower);
    int getAttackPower() const;
    void setAttackRange(double range);
    double getAttackRange() const;
    void attackTarget(Enemy *target);
    static int getCost();

    virtual Projectile* createProjectile(Enemy* target);
    QGraphicsScene *mGame;
    int mAttackPower = ATTACK_POWER;


public slots:
    void acquireTarget();




private:
    AttackArea mAttackArea;

    QTimer mAttackTimer;
    bool mTargetAcquired;

    int mAttackSpeed = ATTACK_SPEED;


    double distanceToItem(QGraphicsItem *item);
};

#endif // TOWERACTIVE_H
