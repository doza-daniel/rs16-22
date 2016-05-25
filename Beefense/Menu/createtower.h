#ifndef CREATETOWER_H
#define CREATETOWER_H

#include <QDialog>
#include <QPointF>
#include "../Logic/game.h"

namespace Ui {
class CreateTower;
}

class CreateTower : public QDialog
{
    Q_OBJECT

public:
    explicit CreateTower(QWidget *parent = 0);
    void setParameters(QPointF point, Game *game,TowerTile *pasive);
    ~CreateTower();
public slots:
    void buy();
    void cancel();

private:
    Ui::CreateTower *ui;
    Game *mGame = nullptr;
    QPointF mPos;
    TowerTile *mTilePlace;
};

#endif // CREATETOWER_H
