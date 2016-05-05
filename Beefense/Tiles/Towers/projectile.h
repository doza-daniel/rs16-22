#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Logic/enemy.h"

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QLineF>
#include <QPointF>
#include <QTimer>
#include <QPainterPath>

extern const int SHOOTING_SPEED;
extern const int PROJECTILE_SPEED;

class Projectile: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Projectile(Enemy* target, int attackPower = 1, int dim = TILE_DIM / 4);

    void setShootingSpeed(int speed);
    int getShootingSpeed() const;
    void setProjectileSpeed(int speed);
    int getProjectileSpeed() const;
    void setAttackPower(int attackPower);
    int getAttackPower() const;

    int getDimension() const;


    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;

public slots:
    void move();
    void targetDestroyed();
private:
     Enemy *mTarget;
     int mAttackPower;
     QPointF mTip;
     int mDimension;
     QTimer mMoveTimer;
     int mShootingSpeed = SHOOTING_SPEED;
     int mProjectileSpeed = PROJECTILE_SPEED;
     void checkForHit();
};

#endif // PROJECTILE_H
