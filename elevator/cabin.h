#ifndef CABIN_H
#define CABIN_H

#include <set>
#include <QObject>
#include "doors.h"
#include <QTimer>
#include <iostream>

int findArray(int* a, int element);
void insertArray(int* a, int element);
void removeArray(int* a, int element);

typedef enum
{
    UP,
    DOWN,
} Direction;

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
    Cabin();
signals:
    void arrived();
    void movingUp();
    void movingDown();

public slots:
    void getNewFloorSlot(int floor, bool out);

    void movedUpSlot();
    void moveUpSlot();
    //void moveUpSlot();
    //void moveDownSlot();
//    void arrivedSlot();
//    void getDoorsOpenedSlot();
//    void getDoorsClosedSlot();

protected:
    cabin_state current_state = STAY_WITH_CLOSED_DOORS;
    int current_floor = 0;
    Direction direction;
    int orders_list[6] = {0, 0, 0, 0, 0, 0};
    int current_dir_floor[6] = {0, 0, 0, 0, 0, 0};
    int next_dir_floor[6] = {0, 0, 0, 0, 0, 0};
    Doors doors;

private:
    void changeState(cabin_state new_state);
    int getFloor();
    cabin_state getState();
};

#endif // CABIN_H
