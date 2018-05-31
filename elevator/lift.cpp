#include "lift.h"
#include <QObject>

Lift::Lift()
{
    QTimer::connect(&this->cabin.timer, SIGNAL(timeout()), &this->controller, SLOT(movedToFloorSlot()));
    QTimer::connect(&this->cabin.timer, SIGNAL(timeout()), &this->controller, SLOT(movedToFloorSlot()));

    QTimer::connect(&this->cabin.doors, SIGNAL(doorsClosed()), &this->controller, SLOT(stayClosedSlot()));

    QTimer::connect(&this->controller, SIGNAL(arrived()), &this->cabin, SLOT(stayClosedSlot()));
    QTimer::connect(&this->controller, SIGNAL(movingUp()), &this->cabin, SLOT(movingUpSlot()));
    QTimer::connect(&this->controller, SIGNAL(movingDown()), &this->cabin, SLOT(movingDownSlot()));
}
