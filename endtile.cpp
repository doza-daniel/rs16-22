#include "endtile.h"
#include "enemy.h"

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

QPainterPath EndTile::shape() const
{
    QPainterPath path;
    path.addRect(mTile);
    return path;
}

void EndTile::advance(int)
{
    QList<QGraphicsItem*> items = this->collidingItems();
    for(int i = 0; i < items.size(); i++) {
        Enemy *e = dynamic_cast<Enemy *>(items[i]);
        if(e)
            delete e;
    }

}

