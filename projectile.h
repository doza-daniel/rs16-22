#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QLineF>

class Projectile: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Projectile(QGraphicsItem* parent = 0);
    void setShootingSpeed(int speed);
    void setProjectileSpeed(int speed);
public slots:
    void move();
private:
     QGraphicsItem *mParent;
     int mShootingSpeed = 10;
     int mProjectileSpeed = 1;
     void checkForHit();
};

#endif // PROJECTILE_H
