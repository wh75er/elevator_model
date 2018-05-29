#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "lift.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Lift lift;
}

MainWindow::~MainWindow()
{
    delete ui;
}
