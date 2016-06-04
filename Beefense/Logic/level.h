#ifndef LEVEL_H
#define LEVEL_H

#include "Logic/map.h"

class Level
{
public:
    Level();

    static QVector<Level *> getLevels(const QString &path);

    Level& operator =(const Level& other);

    Map* getMap() const;
    void setMap(Map *m);
    int getNumber() const;
    void setNumber(int num);
    int getGold() const;
    void setGold(int gold);
    int getWaves() const;
    void setWaves(int waves);

private:
    Map *mMap;
    int mGold;
    int mWaves;
    int mNumber;
};

#endif // LEVEL_H
