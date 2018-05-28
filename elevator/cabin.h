#ifndef CABIN_H
#define CABIN_H

#include <QObject>

typedef enum {
    STAY,
    MOVING_UP,
    MOVING_DOWN
} cabin_state;

class Cabin : public QObject
{
    Q_OBJECT
public:
protected:
    lift_state current_state = STAY;
    int floor = 0;
    vector<int> current_dir_floor;
    vector<int> next_dir_floor;
    Doors doors;
};

#endif // CABIN_H
