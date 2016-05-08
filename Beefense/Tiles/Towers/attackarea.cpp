#include "attackarea.h"
#include "toweractive.h"

#include <QDebug>

const int ATTACK_RANGE_SIZE = TILE_DIM * 5;

AttackArea::AttackArea(TowerActive *tower, QGraphicsScene *scene)
    : mTower(tower)
//      mScene(scene)
{
    mArea = new QGraphicsEllipseItem(0, 0, ATTACK_RANGE_SIZE, ATTACK_RANGE_SIZE);
    allignWithTower();
    scene->addItem(mArea);
}

AttackArea::~AttackArea()
{
    delete mArea;
}

void AttackArea::setRange(int r)
{
    mRange = TILE_DIM * r;
    mArea->setRect(QRectF(0, 0, mRange, mRange));
    allignWithTower();
}

QList<QGraphicsItem *> AttackArea::collidingItems(Qt::ItemSelectionMode mode) const
{
    return mArea->collidingItems(mode);
}

bool AttackArea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return mArea->collidesWithItem(other, mode);
}

bool AttackArea::collidesWithPath(const QPainterPath &path, Qt::ItemSelectionMode mode) const
{
    return mArea->collidesWithPath(path, mode);
}

void AttackArea::show()
{
    mArea->setPen(QPen());
}

void AttackArea::hide()
{
    mArea->setPen(Qt::NoPen);
}

void AttackArea::allignWithTower()
{
    QPointF tCenter = mTower->getCenter();
    QPointF eCenter = mArea->boundingRect().center();
    QLineF movingLine(tCenter, eCenter);
    mArea->setPos(mTower->x() - movingLine.dx(), mTower->y() - movingLine.dy());
}
