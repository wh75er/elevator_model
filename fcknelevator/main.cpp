#include "mainwindow.h"
#include <QApplication>
#include "lift.h"
#include <iostream>


using namespace std;

#include <csignal>
#include "signals_def.h"

void print(int param)
{
    std::cout << "Button clicked!";
}

int main(int argc, char *argv[])
{
    std::signal(B5_CLICKED, print);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
