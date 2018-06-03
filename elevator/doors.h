#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QTimer>

class Doors : public QObject
{
    typedef enum {
        CLOSED = 0,
        CLOSING,
        OPENING,
        OPENED,
    } doors_state;

    Q_OBJECT
public:
    Doors();

signals:
    void openDoors();
    void doorsOpened();
    void closeDoors();
    void doorsClosed();

private slots:
    void openDoorsSlot();
    void doorsOpenedSlot();
    void closeDoorsSlot();
    void doorsClosedSlot();

public:
    doors_state current_state;
};

#endif // DOORS_H
