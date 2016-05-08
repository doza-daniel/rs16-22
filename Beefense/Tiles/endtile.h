#ifndef ENDTILE_H
#define ENDTILE_H

#include "tile.h"

#include <QPainterPath>

class EndTile : public Tile
{
public:
    EndTile(int dim = TILE_DIM, int x = 0, int y = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w = Q_NULLPTR) Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    int getLives();
    void setLives(int lives);
protected slots:
    void advance(int phase) Q_DECL_OVERRIDE;
private:
    int mLivesLeft = 5;
};

#endif // ENDTILE_H
