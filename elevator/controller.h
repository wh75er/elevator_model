#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "lift.h"

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller(Lift *lift);

signals:
    void newFloor(int floor);

private slots:
//    void buttonPushedSlot();
//    void liftButtonPushedSlot();
};

#endif // CONTROLLER_H
