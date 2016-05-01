#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QLineF>
#include <QPointF>
#include <QTimer>
#include <QPainterPath>
#include "enemy.h"

class Projectile: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Projectile(Enemy* target);
    void setShootingSpeed(int speed);
    void setProjectileSpeed(int speed);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;

public slots:
    void move();
private:
     Enemy *mTarget;
     QTimer mMoveTimer;
     int mShootingSpeed = 5;
     int mProjectileSpeed = 1;
     void checkForHit();
};

#endif // PROJECTILE_H
