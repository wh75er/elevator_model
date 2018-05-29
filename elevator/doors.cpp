#include "doors.h"
#include <QTimer>

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
//    emit opened(); // timer
    QTimer::singleShot(5000, this, SLOT(doorsOpenedSlot()));
}

void Doors::doorsOpenedSlot()
{
    emit close();
}

void Doors::closeDoorsSlot()
{
//    emit closed(); // timer
    QTimer::singleShot(5000, this, SLOT(doorsClosedSlot()));
}

void Doors::doorsClosedSlot()
{
    emit terminated();
}
