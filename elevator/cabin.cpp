#include "cabin.h"
#include <QTimer>
#include <iostream>
#include <cstring>

Cabin::Cabin()
{
    QObject::connect(this, SIGNAL(movingUp()), this, SLOT(movingUpSlot()));
    QObject::connect(this, SIGNAL(movingDown()), this, SLOT(movingDownSlot()));
    QObject::connect(this, SIGNAL(arrived()), this, SLOT(arrivedSlot()));
    QObject::connect(this, SIGNAL(arrived()), &this->doors, SLOT(liftArrivedSlot()));
    QObject::connect(&this->doors, SIGNAL(terminated()), this, SLOT(continueWorkSlot()));
}

void Cabin::getNewFloorSlot(int floor, bool out)
{
    //std::cout << "floor is " << floor << ((!out) ? " from inside": " from outside") << std::endl;

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
                this->direction = DOWN;
            }
            else
            {
                emit movingUp();
                this->direction = UP;
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
    setbuf(stdout, NULL);
    std::cout << "moved up to " << this->current_floor+1 << "\n";

    this->current_floor += 1;
    emit __draw_floor(this->current_floor);
    if (findArray(this->current_dir_floor, current_floor))
    {
        emit arrived();
    }
    else
    {
        emit movingUp();
    }
}

void Cabin::movingUpSlot() // <- movingUp
{
    this->current_state = MOVING_UP;
    QTimer::singleShot(5000, this, SLOT(movedUpSlot()));
}


void Cabin::movedDownSlot()
{
    setbuf(stdout, NULL);
    std::cout << "moved down to " << this->current_floor-1 << "\n";

    this->current_floor -= 1;
    emit __draw_floor(this->current_floor);
    if (findArray(this->current_dir_floor, current_floor))
    {
        emit arrived();
    }
    else
    {
        emit movingDown();
    }
}

void Cabin::movingDownSlot() // <- movingDown
{
    this->current_state = MOVING_DOWN;
    QTimer::singleShot(5000, this, SLOT(movedDownSlot()));
}

void Cabin::arrivedSlot()
{
    this->current_state = STAY_WITH_CLOSED_DOORS;
    std::cout << "lift arrived at floor " << this->current_floor << std::endl;
}

void Cabin::continueWorkSlot()
{
    setbuf(stdout, NULL);
    std::cout << "continue " << "\n";
    removeArray(this->current_dir_floor, this->current_floor);
    if (!sizeArray(this->current_dir_floor) && sizeArray(this->next_dir_floor)) {
        memcpy(this->current_dir_floor, this->next_dir_floor, sizeof(int)*6);
        memset(this->next_dir_floor, 0, sizeof(int)*6);
        this->direction = this->direction == UP ? DOWN : UP;
    } else if(!sizeArray(this->current_dir_floor) && !sizeArray(this->next_dir_floor)) {
        this->current_state = STAY_WITH_CLOSED_DOORS;
        return;
    }

    if(this->direction == UP)
        emit movingUp();
    else
        emit movingDown();
}


int findArray(int* a, int element)
{
    int len = a[0];
    for (int i = 1; i < len+1; i++)
    {
        if (a[i] == element)
        {
            return i;
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

int sizeArray(int* a)
{
    return a[0];
}
