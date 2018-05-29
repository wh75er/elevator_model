#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

class StaticArray
{
public:
    StaticArray(size_t size);

    void insert(int element);
    void remove(int element);
    size_t find(int element);
    size_t size();

    ~StaticArray();
private:
    int *arr;
};

StaticArray::StaticArray(size_t size)
{
    this->arr = new int[size+1];
    arr[0] = size;
}

void StaticArray::insert(int element)
{
    int size = this->size();
    if (!this->find(element))
    {
        a[size+1] = element;
        a[0] += 1;
    }
}

void StaticArray::remove(int element)
{
    int id = this->findArray(element);
    int size = this->size();
    if (id)
    {
        a[id] = a[len];
        a[size] = 0;

        a[0] -= 1;
    }
}

size_t StaticArray::find(int element)
{
    int size = this->size();
    for (int i = 1; i < size+1; i++)
    {
        if (a[i] == element)
        {
            return i;
        }
    }
    return 0;
}

size_t StaticArray::size()
{
    return a[0];
}

#endif // STATIC_ARRAY_H
