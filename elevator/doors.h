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
    void open();
    void close();

    void opened();
    void closed();

private slots:
    void liftArrivedSlot();
    void openDoorsSlot();
    void closeDoorsSlot();
    void doorsOpenedSlot();

protected:
    doors_state current_state;
};

#endif // DOORS_H
