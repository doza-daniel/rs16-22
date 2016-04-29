#include "endtile.h"

EndTile::EndTile(int dim, int x, int y)
    : Tile(dim, x, y)
{
    mType = TileType::End;
}

QRectF EndTile::boundingRect() const
{
    return mTile;
}

void EndTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QColor clr(204, 0, 51);

    painter->setBrush(clr);
    painter->setPen(Qt::NoPen);

    painter->drawRect(mTile);

    painter->setBrush(Qt::black);
    painter->setPen(QPen());
    painter->drawText(QPointF(15, 30), QString("END"));
}

