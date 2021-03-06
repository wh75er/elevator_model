#ifndef LIFT_H
#define LIFT_H

#include "doors.h"
#include "controller.h"
#include "cabin.h"
#include <QTimer>

class Lift : public QObject
{
    Q_OBJECT
    friend class MainWindow;
public:
    Lift();
protected:
    Cabin cabin;
    Controller controller;
};

#endif // LIFT_H
