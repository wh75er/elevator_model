#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QTimer>

typedef enum {
    MOVING,
    OPENED,
    CLOSED
} doors_state;

class Doors : public QObject
{
    Q_OBJECT
public:
    Doors();

signals:
    void open();
    void close();

    void opened();
    void closed();
    void terminated();

    void __draw_opened_doors();
    void __draw_closed_doors();

private slots:
    void liftArrivedSlot();
    void openDoorsSlot();
    void closeDoorsSlot();
    void doorsOpenedSlot();
    void doorsClosedSlot();

protected:
    doors_state current_state;
};

#endif // DOORS_H
