#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void chooseLevel();
    void exitGame();

private:
    Ui::MainWindow *ui;
    bool OpenDialogWindow;
};

#endif // MAINWINDOW_H
