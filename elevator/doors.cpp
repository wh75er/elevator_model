#include "doors.h"
#include <QTimer>
#include <iostream>

#define DOORS_DELAY_MS 2000
#define OPEND_DOORS_MS 2000

/*
 *                 + arrived()
 *
 *  ->[ CLOSED ]-----closed()----->[ OPENING ]-----timer(opening)----->
 *
 *  ->[ OPENED ]-----opened()----->[ CLOSING ]-----timer(closing)----->
 *
 *
 */


Doors::Doors()
    :current_state(CLOSED)
{
    QObject::connect(this, SIGNAL(opened()), this, SLOT(closeDoorsSlot()));
}


//// SLOTS ////
void Doors::openDoorsSlot()
{
    this->current_state = OPENING;
    QTimer::singleShot(DOORS_DELAY_MS, this, SLOT(doorsOpenedSlot()));
}

void Doors::doorsOpenedSlot()
{
    this->current_state = OPENED;
    emit opened();
    QTimer::singleShot(OPEND_DOORS_MS, this, SLOT(closeDoorsSlot()));
}

void Doors::closeDoorsSlot()
{
    this->current_state = CLOSING;
    QTimer::singleShot(DOORS_DELAY_MS, this, SLOT(doorsClosedSlot()));
}

void Doors::doorsClosedSlot()
{
    this->current_state = CLOSED;
    emit closed();
}
