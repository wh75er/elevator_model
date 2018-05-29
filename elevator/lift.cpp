#include "lift.h"
#include <QObject>

Lift::Lift()
{
    QObject::connect(&controller, SIGNAL(newFloor(int)), &cabin, SLOT(getNewFloorSlot(int floor)));
}
