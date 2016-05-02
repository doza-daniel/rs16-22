#include "starttile.h"

StartTile::StartTile(int dim, int x, int y)
    : Tile(dim, x, y)
{
    mType = TileType::Start;
}

void StartTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QColor clr(0, 153, 255);

    painter->setBrush(clr);
    painter->setPen(Qt::NoPen);

    painter->drawRect(mTile);

    painter->setBrush(Qt::black);
    painter->setPen(QPen());
    painter->drawText(QPointF(5, 30), QString("START"));
}

