#ifndef DOORS_H
#define DOORS_H

#include <QObject>

typedef enum {
    OPENED,
    CLOSED
} doors_state;

class Doors : public QObject
{
    Q_OBJECT

signals:
    void openDoors();
    void closeDoors();

    void doorsOpened();
    void doorsClosed();

private slots:
    void liftArrive();

protected:
    doors_state current_state;
};

#endif // DOORS_H
