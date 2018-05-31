#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QTimer>

typedef enum {
    CLOSED = 0,
    CLOSING,
    OPENING,
    OPENED,
} doors_state;

class Doors : public QObject
{
    Q_OBJECT
public:
    Doors();

signals:
    void openDoors();
    void doorsOpened();
    void closeDoors();
    void doorsClosed(bool worked);

private slots:
    void openDoorsSlot();
    void doorsOpenedSlot();
    void closeDoorsSlot();
    void doorsClosedSlot();

public:
    doors_state current_state;
};

#endif // DOORS_H
