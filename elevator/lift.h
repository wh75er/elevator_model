#ifndef LIFT_H
#define LIFT_H

#include "doors.h"
#include "controller.h"
#include "cabin.h"
#include <csignal>

using namespace std;

typedef enum {
    STAY,
    MOVING_UP,
    MOVING_DOWN
} cabin_state;

class Lift
{
public:
protected:
    Cabin cabin;
    Controller controller;

signals:
};

#endif // LIFT_H
