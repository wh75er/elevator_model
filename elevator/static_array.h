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

    void copy(StaticArray &other);
    void clear();

    ~StaticArray();
private:
    int *arr;
};

#endif // STATIC_ARRAY_H
