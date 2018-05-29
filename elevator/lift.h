#ifndef LIFT_H
#define LIFT_H

#include "doors.h"
#include "controller.h"
#include "cabin.h"

class Lift : public QObject
{
    Q_OBJECT
protected:
    Cabin cabin;
    Controller controller;
};

#endif // LIFT_H
