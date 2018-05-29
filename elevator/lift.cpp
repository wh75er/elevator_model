#include "lift.h"
#include <QObject>

Lift::Lift()
{
    QObject::connect(&controller, SIGNAL(newFloor(int, bool)), &cabin, SLOT(getNewFloorSlot(int , bool)));
}
