#include "doors.h"
#include <QTimer>
#include <iostream>

#define DOORS_DELAY_MS 2000
#define OPEND_DOORS_MS 2000

/*
 *                 + arrived()
 *
 *  ->[ CLOSED ]-----openDoors()----->[ OPENING ]-----timer(opening)----->
 *
 *  ->[ OPENED ]-----closeDoors()----->[ CLOSING ]-----timer(closing)----->
 *
 *
 */


Doors::Doors()
    :current_state(CLOSED)
{
    QObject::connect(this, SIGNAL(doorsOpened()), this, SLOT(closeDoorsSlot()));
}


//// SLOTS ////
void Doors::openDoorsSlot() // <- openDoors()
{
    this->current_state = OPENING;
    QTimer::singleShot(DOORS_DELAY_MS, this, SLOT(doorsOpenedSlot()));
}

void Doors::doorsOpenedSlot()
{
    this->current_state = OPENED;
    emit doorsOpened();
    QTimer::singleShot(OPEND_DOORS_MS, this, SLOT(closeDoorsSlot()));

    std::cout << "doors opened\n";
}

void Doors::closeDoorsSlot()
{
    this->current_state = CLOSING;
    QTimer::singleShot(DOORS_DELAY_MS, this, SLOT(doorsClosedSlot()));
}

void Doors::doorsClosedSlot()
{
    this->current_state = CLOSED;
    emit doorsClosed();

    std::cout << "doors closed\n";
}
