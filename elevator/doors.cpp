#include "doors.h"

void Doors::liftArrivedSlot()
{
    emit open();
}

void Doors::openDoorsSlot()
{
    emit opened(); // timer
}

void Doors::doorsOpenedSlot()
{
    emit close();
}

void Doors::closeDoorsSlot()
{
    emit closed(); // timer
}
