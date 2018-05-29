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
    if ((current_state == STAY_WITH_CLOSED_DOORS) && !this->current_dir_floor.size())
    {
        if (floor == current_floor)
        {
            emit arrived();
        }
        else
        {
            this->current_dir_floor.insert(floor);
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
            this->current_dir_floor.insert(floor);
        }
        else
        {
            this->next_dir_floor.insert(floor);
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
