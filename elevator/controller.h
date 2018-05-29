#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller(QObject *lift);

signals:
    void newFloor(int floor);

private slots:
    void buttonPushed();
    void liftButtonPushed();
};

#endif // CONTROLLER_H
