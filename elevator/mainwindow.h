#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lift.h"

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
    void drawFloorSlot(int floor);
    void drawOpenedDoorsSlot();
    void drawClosedDoorsSlot();

private:
    Ui::MainWindow *ui;
    Lift lift;
};

#endif // MAINWINDOW_H
