#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void startGame();
    void exitGame();

private:
    Ui::MainWindow *ui;
    Game *mGame;
    bool mGameStarted;
};

#endif // MAINWINDOW_H
