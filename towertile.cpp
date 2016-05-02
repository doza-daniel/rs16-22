#include "towertile.h"
#include <QPointF>
#include "tower.h"

TowerTile::TowerTile(QGraphicsScene &game,int dim, int x, int y)
    : Tile(dim, x, y),mGame(game)
{
    mType = TileType::Tower;
}

void TowerTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QColor grass(51, 204, 51);
    QColor tower(204, 0, 51);

    painter->setBrush(grass);
    painter->setPen(Qt::NoPen);

    painter->drawRect(mTile);

    painter->setBrush(tower);
    painter->drawEllipse(mCenter, TILE_DIM - 35, TILE_DIM - 35);
}

/*When pressed, attempts to build a real Tower*/
void TowerTile::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF pos = this->pos();
    auto t = new Tower(pos.x(),pos.y(),mGame);
    mGame.addItem(t);
    delete this;
}
