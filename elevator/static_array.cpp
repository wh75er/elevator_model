#include "static_array.h"

StaticArray::StaticArray(size_t size)
{
    this->arr = new int[size+1];
    for (int i = 0; i < size+1; i++)
        this->arr[i] = 0;
}

void StaticArray::insert(int element)
{
    int size = this->size();
    if (!this->find(element))
    {
        arr[size+1] = element;
        arr[0] += 1;
    }
}

void StaticArray::remove(int element)
{
    int id = this->find(element);
    int size = this->size();
    if (id)
    {
        arr[id] = arr[size];
        arr[size] = 0;

        arr[0] -= 1;
    }
}

size_t StaticArray::find(int element)
{
    int size = this->size();
    for (int i = 1; i < size+1; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return 0;
}

size_t StaticArray::size()
{
    return arr[0];
}

void StaticArray::copy(StaticArray &other)
{
    this->clear();
    int size = other.size();
    memcpy(this->arr, other.arr, sizeof(int) * size);
}

void StaticArray::clear()
{
    int size = this->size();
    memset(this->arr, 0, sizeof(int) * size);
}

StaticArray::~StaticArray()
{
    delete arr;
}
