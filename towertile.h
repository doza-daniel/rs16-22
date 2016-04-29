#ifndef TOWERTILE_H
#define TOWERTILE_H
#include "tile.h"

class TowerTile : public Tile
{
public:
    TowerTile(int dim = TILE_DIM, int x = 0, int y = 0);
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w = Q_NULLPTR) Q_DECL_OVERRIDE;
};

#endif // TOWERTILE_H
