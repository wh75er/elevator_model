#include "cabin.h"
#include <QTimer>
#include <iostream>
#include <cstring>

Cabin::Cabin()
{
    this->current_dir_floor = new StaticArray(5);
    this->next_dir_floor = new StaticArray(5);

    QObject::connect(this, SIGNAL(movingUp()), this, SLOT(movingUpSlot()));
    QObject::connect(this, SIGNAL(movingDown()), this, SLOT(movingDownSlot()));
    QObject::connect(this, SIGNAL(arrived()), this, SLOT(arrivedSlot()));
    QObject::connect(this, SIGNAL(arrived()), &this->doors, SLOT(liftArrivedSlot()));
    QObject::connect(&this->doors, SIGNAL(terminated()), this, SLOT(continueWorkSlot()));

    QObject::connect(&this->doors, SIGNAL(__draw_closed_doors()), this, SLOT(drawClosedDoors()));
    QObject::connect(&this->doors, SIGNAL(__draw_opened_doors()), this, SLOT(drawOpenedDoors()));
}

void Cabin::getNewFloorSlot(int floor, bool out)
{
    std::cout << "\n getNewFloor \n";
    std::cout << "CUR FLOORS: ";
    for (int i = 0; i < 5; i++) { std::cout << " " << this->current_dir_floor->arr[i+1]; }
    std::cout << "\n";

    std::cout << "NXT FLOORS: ";
    for (int i = 0; i < 5; i++) { std::cout << " " << this->next_dir_floor->arr[i+1]; }
    std::cout << "\n";

    cabin_state current_state = getState();
    if ((current_state == STAY_WITH_CLOSED_DOORS) && !current_dir_floor->size())
    {
        if (floor == current_floor)
        {
            emit arrived();
        }
        else
        {
            this->current_dir_floor->insert(floor);
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
            this->current_dir_floor->insert(floor);
        }
        else if (floor != current_floor)
        {
            this->next_dir_floor->insert(floor);
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
    if (this->current_dir_floor->find(current_floor))
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
    if (this->current_dir_floor->find(current_floor))
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
    std::cout << "\n getNewFloor \n";
    std::cout << "CUR FLOORS: ";
    for (int i = 0; i < 5; i++) { std::cout << " " << this->current_dir_floor->arr[i+1]; }
    std::cout << "\n";

    std::cout << "NXT FLOORS: ";
    for (int i = 0; i < 5; i++) { std::cout << " " << this->next_dir_floor->arr[i+1]; }
    std::cout << "\n";

    this->current_dir_floor->remove(this->current_floor);
    if (!this->current_dir_floor->size() && this->next_dir_floor->size()) {
        this->current_dir_floor->copy(*(this->next_dir_floor), this->next_dir_floor->capacity);
        this->next_dir_floor->clear();

        this->direction = this->direction == UP ? DOWN : UP;
    } else if (!this->current_dir_floor->size() && !this->next_dir_floor->size()) {
        this->current_state = STAY_WITH_CLOSED_DOORS;
        return;
    }

    if (this->direction == UP)
        emit movingUp();
    else
        emit movingDown();

}

void Cabin::drawClosedDoors()
{
    emit __draw_closed_doors();
}

void Cabin::drawOpenedDoors()
{
    emit __draw_opened_doors();
}
