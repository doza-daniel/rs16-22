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
#include <QGraphicsScene>
#include "../../Logic/game.h"

extern const int SHOOTING_SPEED;
extern const int PROJECTILE_SPEED;

class Projectile: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Projectile(QGraphicsScene *game,Enemy* target, int attackPower = 1, int dim = TILE_DIM / 4);
    Projectile();

    void setShootingSpeed(int speed);
    int getShootingSpeed() const;
    void setProjectileSpeed(int speed);
    int getProjectileSpeed() const;
    void setAttackPower(int attackPower);
    int getAttackPower() const;

    int getDimension() const;

    virtual void targetHit(int currHealth);
    Enemy *mTarget;


    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;

public slots:
    void move();
    void targetDestroyed();




private:
     int mAttackPower;
     QPointF mTip;
     int mDimension;
     QTimer mMoveTimer;
     int mShootingSpeed = SHOOTING_SPEED;
     int mProjectileSpeed = PROJECTILE_SPEED;
     void checkForHit();
     QGraphicsScene *mGame;
};

#endif // PROJECTILE_H
