#include "cabin.h"
#include <iostream>

void Cabin::getNewFloorSlot(int floor, bool out)
{
    std::cout << "floor is " << floor << ((!out) ? " from inside": " from outside") << std::endl;

    cabin_state current_state = getState();
    if (current_state == STAY_WITH_CLOSED_DOORS)
    {
        if (floor == current_floor)
        {
            emit arrived();
        }
        else
        {
            current_dir_floor.push_back(floor);
            if (floor < current_floor)
            {
                emit movingDown();
            }
            else
            {
                emit movingUp();
            }
        }
    }
    else
    {
        int current_floor = getFloor();
        if (((current_state == MOVING_UP) && (floor > current_floor)) ||
                 ((current_state == MOVING_DOWN) && (floor < current_floor)))
        {
            current_dir_floor.push_back(floor);
        }
        else
        {
            next_dir_floor.push_back(floor);
        }
    }
}

void Cabin::changeState(cabin_state new_state)
{
    this->current_state = new_state;
    std::cout << "lift is " << this->current_state << std::endl;
}

int Cabin::getFloor()
{
    return current_floor;
}

cabin_state Cabin::getState()
{
    return current_state;
}
