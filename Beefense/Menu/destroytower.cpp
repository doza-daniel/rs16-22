#include "destroytower.h"
#include "ui_destroytower.h"
#include "../Tiles/Towers/attackarea.h"
#include "../Tiles/Towers/greaterattacktower.h"
#include "../Tiles/Towers/greaterrangetower.h"

DestroyTower::DestroyTower(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DestroyTower)
{
    ui->setupUi(this);
}

void DestroyTower::setParameters(QPointF point, Game *game,TowerActive *active)
{
    mGame = game;
    mPos = point;
    mTilePlace = active;
}

DestroyTower::~DestroyTower()
{
    delete ui;
}
//TODO: HARDCODED 35 AS GOLD PRICE
void DestroyTower::yes()
{

        //TODO: TowerActive should have a method that returns sellPrice and buyPrice
        //and use that method anywhere where 35 appears in destroy and create tower
        TowerTile *passive = new TowerTile();
        passive->setPos(mPos);
        mGame->setGold(mGame->getGold()+35);
        mGame->addItem(passive);
        delete mTilePlace;
        ui->noButton->click();


}

void DestroyTower::no()
{
    this->close();
}
