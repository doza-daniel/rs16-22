#ifndef LEVELREADER_H
#define LEVELREADER_H

#include "level.h"
#include <QString>
#include <QXmlStreamReader>

class LevelReader
{
public:
    LevelReader(const QString &path);
    QVector<Level *> getLoadedLevels() const;
private:
    void load(const QString &path);
    bool read(QIODevice *device);
    void readAllLevels();
    void readLevel();
    void readGold(Level *currLevel);
    void readWaves(Level *currLevel);
    void readEnemyHP(Level *currLevel);
    void readMap(Level *currLevel);
    void readWaveSpawnTime(Level *currLevel);
    QXmlStreamReader mXml;
    QVector<Level*> loadedLevels;

};

#endif // LEVELREADER_H
