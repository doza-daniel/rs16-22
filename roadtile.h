#ifndef ROADTILE_H
#define ROADTILE_H
#include "tile.h"

enum class RoadTileType {
    Tunnel, Corner
};

class RoadTile : public Tile
{
public:
    RoadTile(RoadTileType type, int dim = TILE_DIM, int x = 0, int y = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w = Q_NULLPTR) Q_DECL_OVERRIDE;

private:
    RoadTileType mRoadType;
};

#endif // ROADTILE_H
