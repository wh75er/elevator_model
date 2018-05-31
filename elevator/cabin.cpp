#include "cabin.h"
#include <QTimer>
#include <iostream>
#include <cstring>

#define MOVING_TIME 2000

Cabin::Cabin()
{
    this->timer.setSingleShot(true);

    QObject::connect(this, SIGNAL(openDoors()), &this->doors, SLOT(openDoorsSlot()));

    QObject::connect(&this->doors, SIGNAL(doorsOpened()), this, SLOT(stayOpenedSlot()));
    QObject::connect(&this->doors, SIGNAL(doorsClosed(bool)), this, SLOT(stayClosedSlot(bool)));
}


void Cabin::movingUpSlot() // <- movingUp
{
    std::cout << ">> movingUpSlot()\n";

    this->current_state = MOVING_UP;
    this->timer.start(MOVING_TIME);
}


void Cabin::movingDownSlot() // <- movingDown
{
    std::cout << ">> movingDownSlot()\n";

    this->current_state = MOVING_DOWN;
    this->timer.start(MOVING_TIME);
}


void Cabin::stayClosedSlot(bool worked) // <- arrived
{
    std::cout << "\nstayClosedSlot: " << worked << "\n";

    this->current_state = STAY_WITH_CLOSED_DOORS;

    if (!worked)
        emit openDoors();

    emit __draw_closed_doors();

    emit continueWork();
}


void Cabin::stayOpenedSlot() // <- doorsOpened
{
    this->current_state = STAY_WITH_OPENED_DOORS;

    emit __draw_opened_doors();
}
