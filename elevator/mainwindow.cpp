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

    QObject::connect(ui->lift_button_1, SIGNAL(clicked()), &lift.controller, SLOT(ButtonPushedSlot()));
    QObject::connect(ui->lift_button_2, SIGNAL(clicked()), &lift.controller, SLOT(ButtonPushedSlot()));
    QObject::connect(ui->lift_button_3, SIGNAL(clicked()), &lift.controller, SLOT(ButtonPushedSlot()));
    QObject::connect(ui->lift_button_4, SIGNAL(clicked()), &lift.controller, SLOT(ButtonPushedSlot()));
    QObject::connect(ui->lift_button_5, SIGNAL(clicked()), &lift.controller, SLOT(ButtonPushedSlot()));

    QObject::connect(&lift.cabin, SIGNAL(__draw_floor(int)), this, SLOT(drawFloorSlot(int)));
    QObject::connect(&lift.cabin, SIGNAL(__draw_opened_doors()), this, SLOT(drawOpenedDoorsSlot()));
    QObject::connect(&lift.cabin, SIGNAL(__draw_closed_doors()), this, SLOT(drawClosedDoorsSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawFloorSlot(int floor)
{
    this->ui->show_floor_num->display(floor);
}

void MainWindow::drawClosedDoorsSlot()
{
    this->ui->doors_status->setText("Doors closed");
    this->ui->doors_status->setStyleSheet("color: red;");
}

void MainWindow::drawOpenedDoorsSlot()
{
    this->ui->doors_status->setText("Doors opened");
    this->ui->doors_status->setStyleSheet("color: green;");
}
