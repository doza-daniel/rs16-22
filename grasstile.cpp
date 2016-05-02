#include "grasstile.h"

GrassTile::GrassTile(int dim, int x, int y)
    : Tile(dim, x, y)
{
    mType = TileType::Grass;
}


void GrassTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QColor grass(51, 204, 51);

    painter->setBrush(grass);
    painter->setPen(Qt::NoPen);

    painter->drawRect(mTile);
}
