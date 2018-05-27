#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <csignal>
#include "signals_def.h"

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

void MainWindow::on_button_in_5_clicked()
{
    std::raise(B5_CLICKED);
}
