#ifndef STARTTILE_H
#define STARTTILE_H
#include "tile.h"

class StartTile : public Tile
{
public:
    StartTile(int dim = TILE_DIM, int x = 0, int y = 0);
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w = Q_NULLPTR) Q_DECL_OVERRIDE;

};

#endif // STARTTILE_H
