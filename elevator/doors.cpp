#include "doors.h"
#include <QTimer>

#define DOORS_DELAY_MS 2000

Doors::Doors()
{
    QObject::connect(this, SIGNAL(open()), this, SLOT(openDoorsSlot()));
    QObject::connect(this, SIGNAL(opened()), this, SLOT(doorsOpenedSlot()));
    QObject::connect(this, SIGNAL(close()), this, SLOT(closeDoorsSlot()));
    QObject::connect(this, SIGNAL(closed()), this, SLOT(doorsClosedSlot()));
}


//// SLOTS
void Doors::liftArrivedSlot()
{
    emit open();
}

void Doors::openDoorsSlot()
{
    QTimer::singleShot(DOORS_DELAY_MS, this, SLOT(doorsOpenedSlot()));
}

void Doors::doorsOpenedSlot()
{
    emit close();
}

void Doors::closeDoorsSlot()
{
    QTimer::singleShot(DOORS_DELAY_MS, this, SLOT(doorsClosedSlot()));
}

void Doors::doorsClosedSlot()
{
    emit terminated();
}
