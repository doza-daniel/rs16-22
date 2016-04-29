#ifndef TILE_H
#define TILE_H

#define TILE_DIM 50

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QPointF>

enum class TileType {
    Grass = 0,
    Road = 1,
    Tower = 2,
    Start = 3,
    End = 4
};
class Tile : public QGraphicsItem
{
public:
    Tile(int dim = TILE_DIM, int x = 0, int y = 0);

    virtual QRectF boundingRect() const = 0;
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
