#include "lift.h"


Lift::Lift()
    :   cabin(Cabin(this)), controller(Controller(this))
{
}
