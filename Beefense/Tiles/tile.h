#ifndef TILE_H
#define TILE_H

#include <QGraphicsPixmapItem>
#include <QRectF>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QPointF>
#include "../Logic/enumhead.h"

extern const int TILE_DIM;

class Tile : public QGraphicsPixmapItem
{
public:
    Tile(QPixmap pic, int dim = TILE_DIM, int x = 0, int y = 0);

    virtual QRectF boundingRect() const Q_DECL_OVERRIDE;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w = Q_NULLPTR) = 0;
    TileType getTileType() const;
    void rotate(qreal angle);
    QPointF getCenter() const;

protected:
    QRectF mTile;
    QPointF mCenter;
    TileType mType;

};

#endif // TILE_H
