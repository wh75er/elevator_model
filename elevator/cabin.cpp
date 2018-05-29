#include "cabin.h"
#include <QTimer>
#include <iostream>

Cabin::Cabin()
{
    QObject::connect(this, SIGNAL(movingUp()), this, SLOT(moveUpSlot()));
    QObject::connect(this, SIGNAL(movingDown()), this, SLOT(moveUpSlot()));
}

void Cabin::getNewFloorSlot(int floor, bool out)
{
    std::cout << "floor is " << floor << ((!out) ? " from inside": " from outside") << std::endl;

    cabin_state current_state = getState();
    if ((current_state == STAY_WITH_CLOSED_DOORS) && current_dir_floor[0] == 0)
    {
        if (floor == current_floor)
        {
            emit arrived();
        }
        else
        {
            insertArray(this->current_dir_floor, floor);
            if (floor < current_floor)
            {
                emit movingDown();
                this->direction = UP;
            }
            else
            {
                emit movingUp();
                this->direction = DOWN;
            }
        }
    }
    else
    {
        int current_floor = getFloor();
        if (((this->direction == UP) && (floor > current_floor)) ||
                 ((this->direction == DOWN) && (floor < current_floor)))
        {
            insertArray(this->current_dir_floor, floor);
        }
        else
        {
            insertArray(this->next_dir_floor, floor);
        }
    }
    for (int i = 1; i < 6; i++)
        std::cout << " " << this->next_dir_floor[i];
    std::cout << std::endl;
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


void Cabin::movedUpSlot() // <- 'movedUp signal'
{
    std::cout << "moved up to " << this->current_floor+1 << "\n";

    this->current_floor += 1;
    if (findArray(this->current_dir_floor, current_floor))
    {
        removeArray(this->current_dir_floor, this->current_floor);
        emit arrived();
        std::cout << "lift arrived at floor " << this->current_floor << std::endl;
    }
    else
    {
        emit movingUp();
    }
}

void Cabin::movingUpSlot() // <- movingUp
{
    std::cout << "moveUpSlot()\n";

    QTimer::singleShot(5000, this, SLOT(movedUpSlot()));
}


void Cabin::moveDownSlot()
{
    std::cout << "moved down to " << this->current_floor-1 << "\n";

    this->current_floor -= 1;
    if (findArray(this->current_dir_floor, current_floor))
    {
        removeArray(this->current_dir_floor, this->current_floor);
        emit arrived();
        std::cout << "lift arrived at floor " << this->current_floor << std::endl;
    }
    else
    {
        emit movingDown();
    }
}

void Cabin::movingDownSlot() // <- movingDown
{
    std::cout << "moving down\n";

    QTimer::singleShot(5000, this, SLOT(movedDownSlot()));
}


int findArray(int* a, int element)
{
    int len = a[0];
    for (int i = 1; i < len+1; i++)
    {
        if (a[i] == element)
        {
            return true;
        }
    }
    return 0;
}

void insertArray(int* a, int element)
{
    int len = a[0];
    if (len > 5 || findArray(a, element))
    {
        return;
    }
    a[len+1] = element;
    a[0] += 1;
}

void removeArray(int* a, int element)
{
    int id = findArray(a, element);
    int len = a[0];
    if (id)
    {
        a[id] = a[len];
        a[len] = 0;

        a[0] -= 1;
    }
}
