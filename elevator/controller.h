#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller();
signals:
    void newFloor(int floor, bool out);

private slots:
    void buttonPushedSlot();
    void liftButtonPushedSlot();
};

#endif // CONTROLLER_H
