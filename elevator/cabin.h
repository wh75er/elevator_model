#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include "doors.h"
#include "lift.h"

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
    Cabin(Lift *lift);

signals:
    void arrived();
    void movingUp();
    void movingDown();

public slots:
//    void getNewFloorSlot(int floor);
//    void getDoorsOpenedSlot();
//    void getDoorsClosedSlot();


protected:
    cabin_state current_state = STAY_WITH_CLOSED_DOORS;
    int current_floor = 0;
    std::vector<int> orders_list;
    std::vector<int> current_dir_floor;
    std::vector<int> next_dir_floor;
    Doors doors;
};

#endif // CABIN_H
