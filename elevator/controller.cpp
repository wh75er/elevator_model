#include "controller.h"

Controller::Controller(Lift *lift)
{
    QObject::connect(this, SIGNAL(newFloor(int)), lift->cabin, SLOT(getNewFloorSlot(int)));
}
