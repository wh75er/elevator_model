#include "controller.h"
#include <iostream>
#include <QPushButton>

Controller::Controller()
{
    this->current_dir_floor = new StaticArray(5);
    this->next_dir_floor = new StaticArray(5);

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
    std::cout << "\n\nPushed button [" << floor << "]\n";

    int current_floor = this->current_floor;

    if ((this->condition == FREE) && !this->current_dir_floor->size())
    {
//        std::cout << "(condition == FREE) && current_dir_floor->size() == 0\n";
        if (floor == current_floor)
        {
//            std::cout << "  : emit arrived(0)\n";
            std::cout << "Controller condition: BUSY\n";
            this->condition = BUSY;
            emit arrived(false);
        }
        else
        {
            this->current_dir_floor->insert(floor);
            if (floor < current_floor)
            {
//                std::cout << "  : emit movingDown()\n";
                emit movingDown();
                this->direction = DOWN;
                this->condition = BUSY;
                std::cout << "Controller condition: BUSY\n";
                emit movingDown();
            }
            else
            {
//                std::cout << "  : emit movingUp()\n";
                this->direction = UP;
                this->condition = BUSY;
                std::cout << "Controller condition: BUSY\n";
                emit movingUp();
            }
        }
    }
    else
    {
        if (((this->direction == UP) && (floor > current_floor)) ||
                 ((this->direction == DOWN) && (floor < current_floor)))
        {
            std::cout << "  > added to 'current_dir_floor'\n";
            this->current_dir_floor->insert(floor);
        }
        else if (floor != current_floor)
        {
            std::cout << "  > added to 'next_dir_floor'\n";
            this->next_dir_floor->insert(floor);
        }
    }
    std::cout << std::endl;

//    std::cout << "CUR FLOORS: ";
//    for (int i = 0; i < 5; i++) { std::cout << " " << this->current_dir_floor->arr[i+1]; }
//    std::cout << "\n";

//    std::cout << "NXT FLOORS: ";
//    for (int i = 0; i < 5; i++) { std::cout << " " << this->next_dir_floor->arr[i+1]; }
//    std::cout << "\n";
}

void Controller::continueWorkSlot()
{
//    std::cout << "\n>> continueWorkSlot\n";

    this->current_dir_floor->remove(this->current_floor);
    if (!this->current_dir_floor->size() && this->next_dir_floor->size()) {
        this->current_dir_floor->copy(*(this->next_dir_floor), this->next_dir_floor->capacity);
        this->next_dir_floor->clear();
        this->direction = this->direction == UP ? DOWN : UP;
    } else if (!this->current_dir_floor->size() && !this->next_dir_floor->size()) {
        return;
    }

    std::cout << "Controller condition: BUSY\n";
    if (this->direction == UP) {
//        std::cout << "  : emit movingUp()\n";
        this->condition = BUSY;
        emit movingUp();
    } else {
//        std::cout << "  : emit movingDown()\n";
        this->condition = BUSY;
        emit movingDown();
    }


//    std::cout << "\nCUR FLOORS: ";
//    for (int i = 0; i < 5; i++) { std::cout << " " << this->current_dir_floor->arr[i+1]; }
//    std::cout << "\n";

//    std::cout << "NXT FLOORS: ";
//    for (int i = 0; i < 5; i++) { std::cout << " " << this->next_dir_floor->arr[i+1]; }
//    std::cout << "\n";
}

void Controller::stayClosedSlot()
{
//    std::cout << "\n>> stayClosedSlot()\n";
    std::cout << "Controller condition: FREE\n";
    this->condition = FREE;
}

void Controller::movedToFloorSlot()
{
//    std::cout << "\n>> movedToFloorSlot()  // <- timeout() \n";

    if (this->direction == UP)
        (this->current_floor)++;
    else
        (this->current_floor)--;

    int current_floor = this->current_floor;

    if (this->current_dir_floor->find(current_floor))
    {
//        std::cout << "  : emit arrived(0)\n";
        emit arrived(false);
    } else {
        if (this->direction == UP)
        {
//            std::cout << "  : emit movingUp()\n";
            emit movingUp();
        }
        else
        {
//            std::cout << "  : emit movingDown()\n";
            emit movingDown();
        }
    }

    emit __draw_floor(this->current_floor);

//    std::cout << "   current floor: " << this->current_floor << "\n";
}
