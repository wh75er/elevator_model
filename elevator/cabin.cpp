#include "cabin.h"
#include <QTimer>
#include <iostream>
#include <cstring>

#define MOVING_TIME 1000

Cabin::Cabin()
{
    this->timer.setSingleShot(false);

    QObject::connect(this, SIGNAL(openDoors()), &this->doors, SLOT(openDoorsSlot()));
    QObject::connect(&this->doors, SIGNAL(doorsOpened()), this, SLOT(stayOpenedSlot()));
    QObject::connect(&this->doors, SIGNAL(doorsClosed()), this, SLOT(stayClosedSlot()));
}


void Cabin::movingUpSlot() // <- movingUp
{
    this->current_state = MOVING_UP;
    this->timer.start(MOVING_TIME);
}


void Cabin::movingDownSlot() // <- movingDown
{
    this->current_state = MOVING_DOWN;
    this->timer.start(MOVING_TIME);
}


void Cabin::stayClosedSlot() // <- arrived
{
    this->current_state = STAY_WITH_CLOSED_DOORS;

    emit __draw_closed_doors();
}


void Cabin::stayOpenedSlot() // <- doorsOpened
{
    this->current_state = STAY_WITH_OPENED_DOORS;

    emit __draw_opened_doors();
}
