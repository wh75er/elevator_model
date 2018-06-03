#include "doors.h"
#include <QTimer>
#include <iostream>

#define DOORS_DELAY_MS 2000
#define OPEND_DOORS_MS 1000

Doors::Doors()
    :current_state(CLOSED)
{}


//// SLOTS ////
void Doors::openDoorsSlot() // <- openDoors()
{
    std::cout << "     Doors: OPENING\n";

    this->current_state = OPENING;
    QTimer::singleShot(DOORS_DELAY_MS, this, SLOT(doorsOpenedSlot()));
}

void Doors::doorsOpenedSlot()
{
    std::cout << "     Doors: OPENED\n";

    this->current_state = OPENED;
    emit doorsOpened();
}

void Doors::closeDoorsSlot()
{
    std::cout << "     Doors: CLOSING\n";

    this->current_state = CLOSING;
    QTimer::singleShot(DOORS_DELAY_MS, this, SLOT(doorsClosedSlot()));
}

void Doors::doorsClosedSlot()
{
    std::cout << "     Doors: CLOSED\n";

    this->current_state = CLOSED;
    emit doorsClosed();
}
