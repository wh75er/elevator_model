#include "cabin.h"
#include <iostream>

void Cabin::getNewFloorSlot(int floor, bool out)
{
    std::cout << "floor is " << floor << ((!out) ? " from inside": " from outside") << std::endl;
}
