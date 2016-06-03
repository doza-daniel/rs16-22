#include "level.h"
#include "levelreader.h"

Level::Level()
    : mMap(0),
      mGold(0),
      mWaves(0)
{
}

void Level::getLevels(const QString &path)
{
    LevelReader r;
    r.load(path);
}

Map* Level::getMap() const
{
    return mMap;
}

int Level::getNumber() const
{
    return mNumber;
}

void Level::setNumber(int num)
{
    mNumber = num;
}

int Level::getGold() const
{
   return mGold;
}

void Level::setGold(int gold)
{
   mGold = gold;
}

int Level::getWaves() const
{
   return mWaves;
}

void Level::setWaves(int waves)
{
   mWaves = waves;
}
