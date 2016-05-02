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

class Projectile: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Projectile(Enemy* target, int dim = TILE_DIM / 4);
    void setShootingSpeed(int speed);
    void setProjectileSpeed(int speed);
    int getDimension() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;

public slots:
    void move();
    void targetDestroyed();
private:
     const Enemy *mTarget;
     QPointF mTip;
     int mDimension;
     QTimer mMoveTimer;
     int mShootingSpeed = 5;
     int mProjectileSpeed = 1;
     void checkForHit();
};

#endif // PROJECTILE_H
