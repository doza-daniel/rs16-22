#ifndef ENDTILE_H
#define ENDTILE_H
#include "tile.h"

class EndTile : public Tile
{
public:
    EndTile(int dim = TILE_DIM, int x = 0, int y = 0);
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w = Q_NULLPTR) Q_DECL_OVERRIDE;

};

#endif // ENDTILE_H
