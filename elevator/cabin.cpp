#include "cabin.h"
#include <QTimer>
#include <iostream>
#include <cstring>

#define MOVING_TIME 2000

Cabin::Cabin()
{
    this->timer.setSingleShot(true);

    QObject::connect(this, SIGNAL(openDoors()), &this->doors, SLOT(openDoorsSlot()));

    QObject::connect(&this->doors, SIGNAL(doorsOpened()), this, SLOT(stayOpenedSlot()));

    QObject::connect(this, SIGNAL(closeDoors()), &this->doors, SLOT(closeDoorsSlot()));

    QObject::connect(&this->doors, SIGNAL(doorsClosed(bool)), this, SLOT(stayClosedSlot(bool)));
}


void Cabin::movingUpSlot() // <- movingUp
{
//    std::cout << "\n>> movingUpSlot()\n";
    std::cout << "Cabin: MOVING UP\n";


    this->current_state = MOVING_UP;
    this->timer.start(MOVING_TIME);
}


void Cabin::movingDownSlot() // <- movingDown
{
//    std::cout << "\n>> movingDownSlot()\n";
    std::cout << "Cabin: MOVING DOWN\n";

    this->current_state = MOVING_DOWN;
    this->timer.start(MOVING_TIME);
}


void Cabin::stayClosedSlot(bool worked) // <- arrived
{
//    std::cout << "\n>> stayClosedSlot(" << worked << ") // Cabin\n";
    std::cout << "Cabin: STAY WITH CLOSE DOORS\n";
    this->current_state = STAY_WITH_CLOSED_DOORS;

    if (!worked)
    {
//        std::cout << "  : emit openDoors()\n";
        emit openDoors();
    }
    else
    {
//        std::cout << "  : emit continueWork()\n";
        emit __draw_closed_doors();
        emit continueWork();
    }
}


void Cabin::stayOpenedSlot() // <- doorsOpened
{
//    std::cout << "\n>> stayOpenedSlot() // Cabin\n";
//    std::cout << "  : emit closeDoors()\n";

    std::cout << "Cabin: STAY WITH OPENED DOORS\n";
    this->current_state = STAY_WITH_OPENED_DOORS;

    emit closeDoors();

    emit __draw_opened_doors();
}
