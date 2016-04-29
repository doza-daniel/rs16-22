#include "tile.h"

Tile::Tile(int dim, int x, int y)
    : mTile(QRectF(0, 0, dim, dim)), mCenter(mTile.center())
{
    setPos(x, y);
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
    return mCenter;
}

TileType Tile::getTileType() const
{
    return mType;
}
