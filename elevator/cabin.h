#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include "doors.h"
#include <QTimer>
#include <iostream>

#include "static_array.h"

typedef enum
{
    DOWN = 0,
    UP = 1,
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
    void arrived();                 //
    void movingUp();                // signals cabin gets from controller
    void movingDown();              //

    void movedUp();                 // signals cabing sends
    void movedDown();               // to controller

    void openDoors();               // singal cabin sends to the doors

    void __draw_floor(int floor);   // singnals
    void __draw_opened_doors();     // for interface
    void __draw_closed_doors();     // (changing colors and so on)

public slots:
    void stayClosedSlot();
    void movingUpSlot();
    void movingDownSlot();
    void stayOpenedSlot();

protected:
    cabin_state current_state = STAY_WITH_CLOSED_DOORS;
    Doors doors;
public:
    QTimer timer;
};

#endif // CABIN_H
