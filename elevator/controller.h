#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller();
signals:
    void newFloor(int floor);

private slots:
    void buttonPushedSlot();
    void newFloorSlot(int floor);
};

#endif // CONTROLLER_H
