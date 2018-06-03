#include "lift.h"
#include <QObject>

Lift::Lift()
{
    QObject::connect(&this->controller, SIGNAL(movingUp()), &this->cabin, SLOT(movingUpSlot()));
    QObject::connect(&this->controller, SIGNAL(movingDown()), &this->cabin, SLOT(movingDownSlot()));
    QObject::connect(&this->controller, SIGNAL(arriving()), &this->cabin, SLOT(stayClosedSlot()));

    QObject::connect(&this->cabin.timer, SIGNAL(timeout()), &this->controller, SLOT(checkingMoveSlot()));
    QObject::connect(&this->cabin, SIGNAL(doorsTerminated()), &this->controller, SLOT(checkingMoveSlot()));
}
