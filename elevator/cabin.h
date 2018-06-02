#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include "doors.h"
#include <QTimer>
#include <QSignalMapper>
#include <iostream>

#include "static_array.h"

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

    void openDoors();               // singal cabin sends to the doors
    void closeDoors();              //

    void doorsTerminated();         // signal cabin sends to controller

    void __draw_opened_doors();     // signals for interface
    void __draw_closed_doors();     // (changing colors and so on)

public slots:
    void stayClosedSlot();
    void movingUpSlot();
    void movingDownSlot();
    void stayOpenedSlot();

protected:
    cabin_state current_state;
    bool doors_terminating;
public: // for connecting in lift
    Doors doors;
    QTimer timer;
};

#endif // CABIN_H
