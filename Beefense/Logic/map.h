#ifndef MAP_H
#define MAP_H

#include "Tiles/tile.h"

#include <QVector>
#include <QString>
#include <QPointF>
#include <QGraphicsScene>

extern QVector<QString> levelList;

class Map
{
public:
    Map(int rows, int cols, int level = 1);
    QVector<QPointF *> getPath() const;
    QVector< QVector<Tile *> > getMap() const;
    QVector<Tile *> getTowers() const;
    Tile *getStart() const;
    Tile *getEnd() const;
    int getRows() const;
    int getCols() const;

private:
    int mRows;
    int mCols;
    int mLevel;
    Tile *mStart;
    Tile *mEnd;
    QVector< QVector<Tile *> > mMap;
    QVector<QPointF *> mPath;
    QVector<Tile *> mTowers;


    enum class Direction {
        None, Up, Down, Left, Right
    };

    void loadMap();
    void generatePath();
    Direction nextDirection(int i, int j, Direction curr) const;
    QVector< QVector<TileType> > readCSVMap();


};

#endif // MAP_H
