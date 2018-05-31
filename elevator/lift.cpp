#include "lift.h"
#include <QObject>

Lift::Lift()
{
    QTimer::connect(&this->cabin.timer, SIGNAL(timeout()), &this->controller, SLOT(movedToFloorSlot()));
    QTimer::connect(&this->cabin.timer, SIGNAL(timeout()), &this->controller, SLOT(movedToFloorSlot()));

    QTimer::connect(&this->cabin.doors, SIGNAL(doorsClosed()), &this->controller, SLOT(stayClosedSlot));
}
