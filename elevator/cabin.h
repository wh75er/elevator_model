#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include "doors.h"

typedef enum {
    STAY_WITH_CLOSED_DOORS,
    STAY_WITH_OPENED_DOORS,
    MOVING_UP,
    MOVING_DOWN
} cabin_state;

class Cabin : public QObject
{
    Q_OBJECT
public:

signals:
    void arrived();
    void movingUp();
    void movingDown();

public slots:
    void getNewFloor(int floor);


protected:
    lift_state current_state = STAY;
    int current_floor = 0;
    vector<int> orders_list;
    vector<int> current_dir_floor;
    vector<int> next_dir_floor;
    Doors doors;
};

#endif // CABIN_H
