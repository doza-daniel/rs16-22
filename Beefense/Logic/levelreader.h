#ifndef LEVELREADER_H
#define LEVELREADER_H

#include <QString>
#include <QXmlStreamReader>

class LevelReader
{
public:
    LevelReader();
    void load(const QString &path);
private:
    bool read(QIODevice *device);
    void readAllLevels();
    void readLevel();
    void readGold();
    void readWaves();
    void readEnemyHP();
    void readMap();
    QXmlStreamReader mXml;

};

#endif // LEVELREADER_H
