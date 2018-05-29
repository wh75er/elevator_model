#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "lift.h"
#include <QObject>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Lift lift;
    QObject::connect(ui->button_1, SIGNAL(clicked()), &lift.controller, SLOT(buttonPushedSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
