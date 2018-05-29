#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <csignal>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_1_clicked()
{
    std::raise(B1_CLICKED);
}

void MainWindow::on_button_2_clicked()
{
    std::raise(B2_CLICKED);
}

void MainWindow::on_button_3_clicked()
{
    std::raise(B3_CLICKED);
}

void MainWindow::on_button_4_clicked()
{
    std::raise(B4_CLICKED);
}

void MainWindow::on_button_5_clicked()
{
    std::raise(B5_CLICKED);
}


void MainWindow::on_lift_button_1_clicked()
{
    //
}

void MainWindow::on_lift_button_2_clicked()
{
    //
}

void MainWindow::on_lift_button_3_clicked()
{
    std::raise(LB3_CLICKED);
}

void MainWindow::on_lift_button_4_clicked()
{
    std::raise(LB4_CLICKED);
}

void MainWindow::on_lift_button_5_clicked()
{
    std::raise(LB5_CLICKED);
}
