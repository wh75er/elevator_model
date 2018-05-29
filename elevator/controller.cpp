#include "controller.h"
#include <iostream>
#include <QPushButton>

Controller::Controller()
{
}

void Controller::buttonPushedSlot()
{
    auto button = qobject_cast<QPushButton *>(sender());
//    std::string utf8_text = button->text().toUtf8().constData();
//    std::cout << "button num is " << utf8_text << std::endl;
//    setbuf(stdout, NULL);
//    std::cout << "pushed outside!\n";
    if (button->text() == "1")
        emit newFloor(1, true);
    if (button->text() == "2")
        emit newFloor(2, true);
    if (button->text() == "3")
        emit newFloor(3, true);
    if (button->text() == "4")
        emit newFloor(4, true);
    if (button->text() == "5")
        emit newFloor(5, true);
}
void Controller::liftButtonPushedSlot()
{
    auto button = qobject_cast<QPushButton *>(sender());
//    std::string utf8_text = button->text().toUtf8().constData();
//    std::cout << "button num is " << utf8_text << std::endl;
//    setbuf(stdout, NULL);
//    std::cout << "pushed outside!\n";
    if (button->text() == "1")
        emit newFloor(1, false);
    if (button->text() == "2")
        emit newFloor(2, false);
    if (button->text() == "3")
        emit newFloor(3, false);
    if (button->text() == "4")
        emit newFloor(4, false);
    if (button->text() == "5")
        emit newFloor(5, false);
}
