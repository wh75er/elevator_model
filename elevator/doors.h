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
public:
protected:
    doors_state current_state = CLOSED;
};

#endif // DOORS_H
