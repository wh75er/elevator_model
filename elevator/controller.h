#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>
#include "static_array.h"

typedef enum
{
    DOWN = 0,
    UP = 1,
} Direction;

typedef enum
{
    FREE = 0,
    BUSY = 1,
} Condition;

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller();
signals:
    void newFloor(int floor);
    void movingUp();
    void movingDown();
    void arrived();

    void __draw_floor(int);

private slots:
    void buttonPushedSlot();
    void getNewFloorSlot(int floor);
    void continueWorkSlot();
    void stayClosedSlot();
    void movedToFloorSlot();

protected:
    int current_floor = 1;
    Condition condition = FREE;
    Direction direction;
    StaticArray *current_dir_floor;
    StaticArray *next_dir_floor;
};

#endif // CONTROLLER_H
