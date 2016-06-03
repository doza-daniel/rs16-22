#ifndef DESTROYTOWER_H
#define DESTROYTOWER_H

#include <QDialog>
#include <QPointF>
#include "../Logic/game.h"

namespace Ui {
class DestroyTower;
}

class DestroyTower: public QDialog
{
    Q_OBJECT

public:
    explicit DestroyTower(QWidget *parent = 0);
    void setParameters(QPointF point, Game *game,TowerActive *active);
    ~DestroyTower();
public slots:
    void yes();
    void no();

private:
    Ui::DestroyTower *ui;
    Game *mGame = nullptr;
    QPointF mPos;
    TowerActive *mTilePlace;
};

#endif // DESTROYTOWER_H
