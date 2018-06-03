#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>
#include "static_array.h"

class Controller : public QObject
{
    typedef enum
    {
        DOWN = 0,
        UP,
    } Direction;

    typedef enum
    {
        GET_FLOOR = 0,
        BUSY,
    } Condition;

    typedef enum {
        MOVING = 0,
        ARRIVING,
        NONE,
    } Motion;

    Q_OBJECT

public:
    Controller();
signals:
    void movingUp();
    void movingDown();
    void arriving();

    void selfCheck();

    void __draw_floor(int);

private slots:
    void gettingNewFloorSlot();
    void checkingMoveSlot();

protected:
    int current_floor;
    Condition condition;
    Motion last_motion;
    Direction direction;
    StaticArray *current_dir_floor;
    StaticArray *next_dir_floor;
};

#endif // CONTROLLER_H
