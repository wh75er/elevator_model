#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>
#include "static_array.h"

typedef enum
{
    DOWN = 0,
    UP,
} Direction;

typedef enum
{
    FREE = 0,       //  У НАС НЕТ ТАКОГО СОСТОЯНИЯ, ПРИ КОТОРОМ КОНТРОЛЛЕР НЕ_ПРИНИМАЛ_БЫ СИГНАЛЫ
    BUSY,           //  Т.К. СИГНАЛЫ С КНОПОК ДОЛЖНЫ ИДТИ В ОДИН СЛОТ, ТО ОН ЭНИВЕЙ БУДЕТ
} Condition;

typedef enum {
    MOVING = 0,
    ARRIVING,
    NONE,
} Motion;

class Controller : public QObject
{
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
//    void stayClosedSlot();

protected:
    int current_floor;
    Condition condition;
    Motion last_motion;
    Direction direction;
    StaticArray *current_dir_floor;
    StaticArray *next_dir_floor;
};

#endif // CONTROLLER_H
