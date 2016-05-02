#include "towertile.h"

TowerTile::TowerTile(int dim, int x, int y)
    : Tile(dim, x, y)
{
    mType = TileType::Tower;
}

void TowerTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QColor grass(51, 204, 51);
    QColor tower(204, 0, 51);

    painter->setBrush(grass);
    painter->setPen(Qt::NoPen);

    painter->drawRect(mTile);

    painter->setBrush(tower);
    painter->drawEllipse(mCenter, TILE_DIM - 35, TILE_DIM - 35);
}
