#ifndef DOORS_H
#define DOORS_H

typedef enum {
    OPENED,
    CLOSED
} doors_state;

class Doors
{
public:
    void opening();
    void closing();
protected:
    doors_state current_state = CLOSED;
};

#endif // DOORS_H
