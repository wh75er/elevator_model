#include "controller.h"
#include <iostream>

Controller::Controller()
{
}

void Controller::buttonPushedSlot()
{
    setbuf(stdout, NULL);
    std::cout << "button pushed!\n";
}
