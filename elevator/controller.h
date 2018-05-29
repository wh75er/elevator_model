#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT

signals:
    void newFloor(int floor);

private slots:
    void buttonPushedSlot();
    void liftButtonPushedSlot();
};

#endif // CONTROLLER_H
