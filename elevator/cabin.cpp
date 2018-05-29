#include "cabin.h"
#include <QTimer>
#include <iostream>

Cabin::Cabin()
{
//    QObject::connect(this, SIGNAL(movingUp()), this, SLOT(moveUpSlot()));
//    QObject::connect(this, SIGNAL(movingDown()), this, SLOT(moveDownSlot()));
    //QObject::connect(this, SIGNAL(arrived()), this, SLOT(arrivedSlot()));
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
    for (int i = 1; i < 5; i++)
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

//void Cabin::moveUpSlot()
//{
//    if (this->current_dir_floor.find(getFloor()) != this->current_dir_floor.end())
//    {
//        this->current_dir_floor.erase(getFloor());
//        emit arrived();
//    }
//    else
//    {
//        QTimer::singleShot(5000, this, SLOT(moveUpSlot()));
//        emit movingUp();
//    }
//}

//void Cabin::moveDownSlot()
//{
//    if (this->current_dir_floor.find(getFloor()) != this->current_dir_floor.end())
//    {
//        this->current_dir_floor.erase(getFloor());
//        emit arrived();
//    }
//    else
//    {
//        QTimer::singleShot(5000, this, SLOT(moveDownSlot));
//        emit movingDown();
//    }
//}


int findArray(int* a, int element)
{
    int len = a[0];
    for (int i = 1; i < len; i++)
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
    if (!id)
    {
        a[id] = 0; // ne objazatelno, chisto dlya vida
        a[0] -= 1;
    }
}
