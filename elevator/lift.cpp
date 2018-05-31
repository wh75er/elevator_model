#include "lift.h"
#include <QObject>

Lift::Lift()
{
    QObject::connect(&this->cabin.timer, SIGNAL(timeout()), &this->controller, SLOT(movedToFloorSlot()));

    QObject::connect(&this->cabin.doors, SIGNAL(doorsClosed(bool)), &this->controller, SLOT(stayClosedSlot()));

    QObject::connect(&this->controller, SIGNAL(arrived(bool)), &this->cabin, SLOT(stayClosedSlot(bool)));

    QObject::connect(&this->controller, SIGNAL(movingUp()), &this->cabin, SLOT(movingUpSlot()));
    QObject::connect(&this->controller, SIGNAL(movingDown()), &this->cabin, SLOT(movingDownSlot()));

    QObject::connect(&this->cabin, SIGNAL(continueWork()), &this->controller, SLOT(continueWorkSlot()));
}
