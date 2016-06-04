#include "tile.h"
#include <QTime>
#include <QDebug>

const int TILE_DIM = 50;

Tile::Tile(QPixmap pic, int dim, int x, int y)
    : mTile(QRectF(0, 0, dim, dim)), mCenter(mTile.center())
{
    setPixmap(pic.scaled(dim, dim));
    setPos(x, y);
}

QRectF Tile::boundingRect() const
{
    return mTile;
}

void Tile::rotate(qreal angle)
{
    QTransform m;
    m.translate(mCenter.x(), mCenter.y());
    m.rotate(angle);
    m.translate(-mCenter.x(), -mCenter.y());
    setTransform(m);
}

QPointF Tile::getCenter() const
{
    return mTile.center();
}

TileType Tile::getTileType() const
{
    return mType;
}
