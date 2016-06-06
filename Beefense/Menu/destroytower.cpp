#include "destroytower.h"
#include "ui_destroytower.h"
#include "../Tiles/Towers/attackarea.h"
#include "../Tiles/Towers/greaterattacktower.h"
#include "../Tiles/Towers/greaterrangetower.h"
#include "../Tiles/Towers/slowtower.h"

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
        // Bad OOP design, last minute fix
        int towerCost = 0;
        if(dynamic_cast<GreaterAttackTower*>(mTilePlace))
            towerCost = GreaterAttackTower::getCost();
        else if(dynamic_cast<GreaterRangeTower*>(mTilePlace))
            towerCost = GreaterRangeTower::getCost();
        else if(dynamic_cast<SlowTower*>(mTilePlace))
            towerCost = SlowTower::getCost();
        else if(dynamic_cast<TowerActive*>(mTilePlace))
            towerCost = TowerActive::getCost();

        TowerTile *passive = new TowerTile();
        passive->setPos(mPos);
        mGame->setGold(mGame->getGold() + towerCost);
        mGame->addItem(passive);
        delete mTilePlace;
        ui->noButton->click();
}

void DestroyTower::no()
{
    this->close();
}
