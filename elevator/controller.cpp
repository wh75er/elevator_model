#include "controller.h"

Controller::Controller()
{
    QObject::connect(this, SIGNAL(newFloor(int)), cabin, );
}
