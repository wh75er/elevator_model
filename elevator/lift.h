#ifndef LIFT_H
#define LIFT_H

#include "doors.h"
#include <csignal>

using namespace std;

enum {
    PUSHED_BUTTON_OUTSIDE,
    PUSHED_BUTTON_INSIDE,
    ARRIVED,
    CONTINUE,
}; // signals

typedef enum {
    STAY,
    MOVING_UP,
    MOVING_DOWN
} lift_state;

class Lift
{
public:
    void stopped();
    void moving_up();
    void moving_down();
protected:
     lift_state current_state = STAY;
     int floor = 0;
     vector<int> current_dir_floor;
     vector<int> next_dir_floor;
     Doors doors;
};

#endif // LIFT_H
