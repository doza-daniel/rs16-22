#include "createtower.h"
#include "ui_createtower.h"
#include "../Tiles/Towers/attackarea.h"
#include "../Tiles/Towers/greaterattacktower.h"
#include "../Tiles/Towers/greaterrangetower.h"

CreateTower::CreateTower(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateTower)
{
    ui->setupUi(this);
    ui->label->setVisible(false);
}

void CreateTower::setParameters(QPointF point, Game *game,TowerTile *pasive)
{
    mGame = game;
    mPos = point;
    mTilePlace = pasive;
}

CreateTower::~CreateTower()
{
    delete ui;
}
//TODO: HARDCODED 35 AS GOLD PRICE
void CreateTower::buy()
{
    int type = ui->createList->currentRow();
    TowerActive *twr = nullptr;
    switch(type){
        case 1:
        if(mGame->getGold() > 35)
             twr = new GreaterRangeTower(mPos.x(), mPos.y(), mGame);
        break;
        case 0:
            if(mGame->getGold() > 35)
                 twr = new GreaterAttackTower(mPos.x(), mPos.y(), mGame);
        break;

    }
    if(twr){
        mGame->setGold(mGame->getGold()-35);
        mGame->addItem(twr);
        delete mTilePlace;
        ui->cancelButton->click();
    }
    else
       ui->label->setVisible(true);

}

void CreateTower::cancel()
{
    this->close();
}
