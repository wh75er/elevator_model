#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

#include <cstring>

class StaticArray
{
public:
    explicit StaticArray(size_t size);

    void insert(int element);
    void remove(int element);
    size_t find(int element);
    size_t size();

    void copy(StaticArray &other, size_t n);
    void clear();


    ~StaticArray();
//private:
    int *arr;
    size_t capacity;
};

#endif // STATIC_ARRAY_H
