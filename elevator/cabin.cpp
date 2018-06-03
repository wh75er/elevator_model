#include "cabin.h"
#include <QTimer>
#include <iostream>
#include <cstring>

#define MOVING_TIME 3000

Cabin::Cabin()
{
    this->current_state = STAY_WITH_CLOSED_DOORS;
    this->doors_terminating = false;

    this->timer.setSingleShot(true);

    QObject::connect(this, SIGNAL(openDoors()), &this->doors, SLOT(openDoorsSlot()));

    QObject::connect(&this->doors, SIGNAL(doorsOpened()), this, SLOT(stayOpenedSlot()));

    QObject::connect(this, SIGNAL(closeDoors()), &this->doors, SLOT(closeDoorsSlot()));

    QObject::connect(&this->doors, SIGNAL(doorsClosed()), this, SLOT(stayClosedSlot()));


}


void Cabin::movingUpSlot() // <- movingUp
{
    std::cout << "\nCabin: MOVING UP\n";


    this->current_state = MOVING_UP;
    this->timer.start(MOVING_TIME);
}


void Cabin::movingDownSlot() // <- movingDown
{
    std::cout << "\nCabin: MOVING DOWN\n";

    this->current_state = MOVING_DOWN;
    this->timer.start(MOVING_TIME);
}


void Cabin::stayClosedSlot() // <- arriving
{
    std::cout << "\nCabin: STAY WITH CLOSE DOORS\n";
    this->current_state = STAY_WITH_CLOSED_DOORS;

    if (!this->doors_terminating)
    {
        emit openDoors();
        this->doors_terminating = true;
    }
    else
    {
        emit __draw_closed_doors();
        emit doorsTerminated();
        this->doors_terminating = false;
    }
}


void Cabin::stayOpenedSlot() // <- doorsOpened
{
    std::cout << "\nCabin: STAY WITH OPENED DOORS\n";
    this->current_state = STAY_WITH_OPENED_DOORS;

    emit closeDoors();

    emit __draw_opened_doors();
}
