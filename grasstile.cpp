#include "grasstile.h"

GrassTile::GrassTile(int dim, int x, int y)
    : Tile(QPixmap(":/map/images/tile/grass.jpg"), dim, x, y)
{
    mType = TileType::Grass;
}


void GrassTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w)
{
    QGraphicsPixmapItem::paint(painter, option, w);
    /*
    QColor grass(51, 204, 51);

    painter->setBrush(grass);
    painter->setPen(Qt::NoPen);

    painter->drawRect(mTile);
    */
}
