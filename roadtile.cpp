#include "roadtile.h"
#include "tile.h"

RoadTile::RoadTile(RoadTileType type, int dim, int x, int y)
    : Tile(dim, x, y), mRoadType(type)
{
    mType = TileType::Road;
}

void RoadTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QColor grass(51, 204, 51);
    QColor road(224, 224, 224);

    painter->setPen(Qt::NoPen);
    painter->setBrush(grass);
    painter->drawRect(mTile);

    if(mRoadType == RoadTileType::Tunnel) {
        painter->setBrush(road);
        painter->drawRect(QRectF(0, 5, TILE_DIM, TILE_DIM - 10));
    } else {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRoundedRect(QRectF(0, 5, TILE_DIM - 5, TILE_DIM - 5), 10, 10);
        path.addRect(QRectF(0, 5, 10, 10));
        path.addRect(QRectF(35, 40, 10, 10));

        painter->setBrush(road);
        painter->drawPath(path);

        painter->setBrush(grass);
        painter->drawRect(QRectF(0, 45, 5, 5));
    }
}
