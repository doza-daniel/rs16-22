#ifndef ENDTILE_H
#define ENDTILE_H

#include "tile.h"

#include <QTimer>
#include <QPainterPath>
#include <QObject>

class EndTile : public QObject, public Tile
{
    Q_OBJECT
public:
    EndTile(int dim = TILE_DIM, int x = 0, int y = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w = Q_NULLPTR) Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    int getLives();
    void setLives(int lives);
public slots:
    void destroy();
private:
    QTimer mDestroyTimer;
    int mLivesLeft = 50;
};

#endif // ENDTILE_H
