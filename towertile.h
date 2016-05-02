#ifndef TOWERTILE_H
#define TOWERTILE_H
#include "tile.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class TowerTile : public Tile
{
public:
    TowerTile(QGraphicsScene &game, int dim = TILE_DIM, int x = 0, int y = 0);
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w = Q_NULLPTR) Q_DECL_OVERRIDE;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
protected:
    QGraphicsScene &mGame;
};

#endif // TOWERTILE_H
