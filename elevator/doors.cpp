#include "doors.h"
#include <QTimer>
#include <iostream>

#define DOORS_DELAY_MS 1000
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
{}


//// SLOTS ////
void Doors::openDoorsSlot() // <- openDoors()
{
//    std::cout << "\n>>>> openDoorsSlot()\n";
    std::cout << "     Doors: OPENING\n";

    this->current_state = OPENING;
    QTimer::singleShot(DOORS_DELAY_MS, this, SLOT(doorsOpenedSlot()));
}

void Doors::doorsOpenedSlot()
{
//    std::cout << ">>>> doorsOpenedSlot()\n";
    std::cout << "     Doors: OPENED\n";
//    std::cout << "     emit doorsOpened()\n";

    this->current_state = OPENED;
    emit doorsOpened();
}

void Doors::closeDoorsSlot()
{
//    std::cout << ">>>> closeDoorsSlot()\n";
    std::cout << "     Doors: CLOSING\n";

    this->current_state = CLOSING;
    QTimer::singleShot(DOORS_DELAY_MS, this, SLOT(doorsClosedSlot()));
}

void Doors::doorsClosedSlot()
{
//    std::cout << ">>>> doorsClosedSlot()\n";
    std::cout << "     Doors: CLOSED\n";
//    std::cout << "     emit doorsClosed(1)\n";

    this->current_state = CLOSED;
    emit doorsClosed(true);
}
