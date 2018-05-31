#include "controller.h"
#include <iostream>
#include <QPushButton>

Controller::Controller()
{
    QObject::connect(this, SIGNAL(newFloor(int)), this, SLOT(getNewFloorSlot(int)));
}

void Controller::buttonPushedSlot()
{
    auto button = qobject_cast<QPushButton *>(sender());
    if (button->text() == "1")
        emit newFloor(1);
    if (button->text() == "2")
        emit newFloor(2);
    if (button->text() == "3")
        emit newFloor(3);
    if (button->text() == "4")
        emit newFloor(4);
    if (button->text() == "5")
        emit newFloor(5);
}

void Controller::getNewFloorSlot(int floor)
{
    Condition condition = this->condition;
    int current_floor = this->current_floor;
    if ((condition == FREE) && !current_dir_floor->size())
    {
        if (floor == current_floor)
        {
            emit arrived();
            this->condition = BUSY;
        }
        else
        {
            this->current_dir_floor->insert(floor);
            if (floor < current_floor)
            {
                emit movingDown();
                this->direction = DOWN;
                this->condition = BUSY;
            }
            else
            {
                emit movingUp();
                this->direction = UP;
                this->condition = BUSY;
            }
        }
    }
    else
    {
        if (((this->direction == UP) && (floor > current_floor)) ||
                 ((this->direction == DOWN) && (floor < current_floor)))
        {
            this->current_dir_floor->insert(floor);
        }
        else if (floor != current_floor)
        {
            this->next_dir_floor->insert(floor);
        }
    }

    std::cout << "\n getNewFloor[" << floor << "]\n";
    std::cout << "CUR FLOORS: ";
    for (int i = 0; i < 5; i++) { std::cout << " " << this->current_dir_floor->arr[i+1]; }
    std::cout << "\n";

    std::cout << "NXT FLOORS: ";
    for (int i = 0; i < 5; i++) { std::cout << " " << this->next_dir_floor->arr[i+1]; }
    std::cout << "\n";

    std::cout << "CRNT STATE: ";
    if (getState() == STAY_WITH_CLOSED_DOORS)
        std::cout << "STAY_WITH_CLOSED_DOORS\n";
    else if (getState() == STAY_WITH_OPENED_DOORS)
        std::cout << "STAY_WITH_OPENED_DOORS\n";
    else if (getState() == MOVING_UP)
        std::cout << "MOVING_UP\n";
    else if (getState() == MOVING_DOWN)
        std::cout << "MOVING DOWN\n";

    std::cout << "current_dir_floor->size() = " << current_dir_floor->size() << "\n";
    std::cout << "doors state: " << this->doors.current_state << "\n";
    std::cout << "direction: " << this->direction << "\n";
}

void Controller::continueWorkSlot()
{
    this->current_dir_floor->remove(this->current_floor);
    if (!this->current_dir_floor->size() && this->next_dir_floor->size()) {
        this->current_dir_floor->copy(*(this->next_dir_floor), this->next_dir_floor->capacity);
        this->next_dir_floor->clear();

        this->direction = this->direction == UP ? DOWN : UP;
    } else if (!this->current_dir_floor->size() && !this->next_dir_floor->size()) {
        return;
    }

    if (this->direction == UP) {
        emit movingUp();
        this->condition = BUSY;
    } else {
        emit movingDown();
        this->condition = BUSY;
    }

    std::cout << "\n continueWork \n";
    std::cout << "CUR FLOORS: ";
    for (int i = 0; i < 5; i++) { std::cout << " " << this->current_dir_floor->arr[i+1]; }
    std::cout << "\n";

    std::cout << "NXT FLOORS: ";
    for (int i = 0; i < 5; i++) { std::cout << " " << this->next_dir_floor->arr[i+1]; }
    std::cout << "\n";
}

void Controller::stayClosedSlot()
{
    this->condition = FREE;
}

void Controller::movedToFloorSlot()
{
    if (this->direction == UP)
        (this->current_floor)++;
    else
        (this->current_floor)--;

    int current_floor = this->current_floor;

    if (this->current_dir_floor->find(current_floor))
        emit arrived();
}
