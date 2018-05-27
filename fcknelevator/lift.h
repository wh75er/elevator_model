#ifndef LIFT_H
#define LIFT_H

typedef enum {
    STAY,
    MOVING_UP,
    MOVING_DOWN
} lift_state;

typedef enum {
    OPENED,
    CLOSED
} doors_state;

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

class Doors
{
public:
    void opening();
    void closing();
protected:
    doors_state current_state = CLOSED;
};

#endif // LIFT_H
