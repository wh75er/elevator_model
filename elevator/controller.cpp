#include "controller.h"
#include <iostream>
#include <QPushButton>

Controller::Controller()
{
    QObject::connect(this, SIGNAL(newFloor(int)), this, SLOT(getNewFloorSlot(int)));

}

void Controller::buttonPushedSlot()
{
    auto button = qobject_cast<QPushButton *>(sender());
    if (button->text() == "1")
        emit newFloor(1);
    if (button->text() == "2")
        emit newFloor(2);
    if (button->text() == "3")
        emit newFloor(3);
    if (button->text() == "4")
        emit newFloor(4);
    if (button->text() == "5")
        emit newFloor(5);
}

void Controller::newFloorSlot(int floor)
{

}
