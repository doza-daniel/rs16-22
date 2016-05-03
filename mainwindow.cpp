#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mGame(nullptr),
    mGameStarted(false)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGame()
{
    if(mGameStarted)
        return;
    mGame = new Game(0, 0, 1000, 800);
    mGameStarted = true;
    qDebug() << "start clicked";
    mGame->show();
}

void MainWindow::exitGame()
{
    delete this;
}
