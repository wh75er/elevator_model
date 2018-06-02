#include "controller.h"
#include <iostream>
#include <QPushButton>

Controller::Controller()
{
    this->current_floor = 1;
    this->condition = FREE;

    this->current_dir_floor = new StaticArray(5);
    this->next_dir_floor = new StaticArray(5);
}

void Controller::gettingNewFloorSlot()
{
    std::cout << "\n>>> gettingNewFloor";
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    int floor;
    if (button->text() == "1")
        floor = 1;
    else if (button->text() == "2")
        floor = 2;
    else if (button->text() == "3")
        floor = 3;
    else if (button->text() == "4")
        floor = 4;
    else if (button->text() == "5")
        floor = 5;

    std::cout << "[" << floor << "]";

    std::cout << "\n current_dir_floor.size() = " << this->current_dir_floor->size();

    if (!this->current_dir_floor->size() && this->condition == FREE)
    {
//        this->condition = BUSY;
        this->condition = WAITING_FOR_RESPONSE;
        if (floor == this->current_floor)
        {
            this->last_motion = ARRIVING;
            std::cout << "\nemit arriving()";
            emit arriving();
        }
        else
        {
            this->last_motion = MOVING;
            this->current_dir_floor->insert(floor);
            if (floor < current_floor)
            {
                this->direction = DOWN;
                std::cout << "\nemit movingDown()";
                emit movingDown();
            }
            else
                this->direction = UP;
                std::cout << "\nemit movingUp()";
                emit movingUp();
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
}

void Controller::checkingMoveSlot() // waitingForResponseSlot()
{
    std::cout << "\n\t>>> checkingMoveSlot()";

    if (this->last_motion == MOVING)
    {
        if (this->direction == UP)
            this->current_floor += 1;
        else
            this->current_floor -= 1;
        emit __draw_floor(this->current_floor);
    }

    std::cout << "\nCURRENT FLOOR: " << this->current_floor;

    std::cout << "\ncurrent_dir_floor: ";
    for (int i = 0; i < 5; i++) { std::cout << this->current_dir_floor->arr[i+1] << " ";}
    std::cout << "\nnext_dir_floor   : ";
    for (int i = 0; i < 5; i++) { std::cout << this->next_dir_floor->arr[i+1] << " ";}

    if (this->current_dir_floor->find(this->current_floor) && this->last_motion == MOVING)
    {
        this->last_motion = ARRIVING;
        std::cout << "\nemit arriving()";
        emit arriving();
        return;
    }

    if (this->last_motion == ARRIVING)
    {
        std::cout << "\nremoved " << this->current_floor << " floor from cur_dir_floor\n";
        this->current_dir_floor->remove(this->current_floor);

        if (!this->current_dir_floor->size() && this->next_dir_floor->size())
        {
            this->current_dir_floor->copy(*(this->next_dir_floor), this->next_dir_floor->capacity);
            this->next_dir_floor->clear();
            this->direction = this->direction == UP ? DOWN : UP;
        }
        else if (!this->current_dir_floor->size() && !this->next_dir_floor->size())
        {
            this->condition = FREE;
            return;
        }
    }

    this->last_motion = MOVING;
    if (this->direction == UP)
    {
        std::cout << "\nemit movingUp()";
        emit movingUp();
    }
    else
    {
        std::cout << "\nemit movingDown()";
        emit movingDown();
    }
}
