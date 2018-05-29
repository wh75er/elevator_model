#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "lift.h"
#include <QObject>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->button_1, SIGNAL(clicked()), &lift.controller, SLOT(buttonPushedSlot()));
    QObject::connect(ui->button_2, SIGNAL(clicked()), &lift.controller, SLOT(buttonPushedSlot()));
    QObject::connect(ui->button_3, SIGNAL(clicked()), &lift.controller, SLOT(buttonPushedSlot()));
    QObject::connect(ui->button_4, SIGNAL(clicked()), &lift.controller, SLOT(buttonPushedSlot()));
    QObject::connect(ui->button_5, SIGNAL(clicked()), &lift.controller, SLOT(buttonPushedSlot()));

    QObject::connect(ui->lift_button_1, SIGNAL(clicked()), &lift.controller, SLOT(liftButtonPushedSlot()));
    QObject::connect(ui->lift_button_2, SIGNAL(clicked()), &lift.controller, SLOT(liftButtonPushedSlot()));
    QObject::connect(ui->lift_button_3, SIGNAL(clicked()), &lift.controller, SLOT(liftButtonPushedSlot()));
    QObject::connect(ui->lift_button_4, SIGNAL(clicked()), &lift.controller, SLOT(liftButtonPushedSlot()));
    QObject::connect(ui->lift_button_5, SIGNAL(clicked()), &lift.controller, SLOT(liftButtonPushedSlot()));

    QObject::connect(&lift.cabin, SIGNAL(__draw_floor(int)), this, SLOT(drawFloorSlot(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawFloorSlot(int floor)
{
    this->ui->show_floor_num->display(floor);
}
