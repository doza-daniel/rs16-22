#include "endtile.h"
#include "Logic/enemy.h"

#include <cstdlib>

EndTile::EndTile(int dim, int x, int y)
    : Tile(QPixmap(":/images/tile/end.png"), dim, x, y)
{
    mType = TileType::End;
}

void EndTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w)
{
    QGraphicsPixmapItem::paint(painter, option, w);
    /*
    QColor clr(204, 0, 51);

    painter->setBrush(clr);
    painter->setPen(Qt::NoPen);

    painter->drawRect(mTile);

    painter->setBrush(Qt::black);
    painter->setPen(QPen());
    painter->drawText(QPointF(15, 30), QString("END"));
    */
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
        if(e){
            delete e;
            mLivesLeft--;
        }
        if(mLivesLeft <= 0){
            exit(EXIT_SUCCESS);
        }
    }
}

