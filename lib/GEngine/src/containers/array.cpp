#include "array.hpp"

template <typename T>
array<T>::iterator array<T>::begin()
{
    return _data;
}

template <typename T>
array<T>::iterator array<T>::end()
{
    return _data + _size;
}

template <typename T>
array<T>::iterator array<T>::find(const T &item)
{
    for (const auto &e : *this)
    {
        if (e == item)
            return &e;
    }
    return end();
}

template <typename T>
array<T>::iterator array<T>::find(const T &&item)
{
    for (T &e : *this)
    {
        if (e == item)
            return &e;
    }
    return end();
}

template <typename T>
array<T>::~array()
{
    delete[] _data;
}

template <typename T>
array<T> &array<T>::operator<<(const T &item)
{
    append(item);
    return *this;
}

// deletes last item and returns it's copy
template <typename T>
array<T> &array<T>::operator>>(T &item)
{
    item = pop();
    return *this;
}

template <typename T>
T &array<T>::back()
{
    return _data[_size - 1];
}

template <typename T>
T &array<T>::front()
{
    return *_data;
}

// appendes item to the back
template <typename T>
void array<T>::append(const T &item)
{
    array<T>::iterator new_data = new T[_size + 1];

    for (int i = 0; i < _size; i++)
    {
        new_data[i] = _data[i];
    }

    new_data[_size] = item;
    ++_size;

    delete[] _data;
    _data = new_data;
}

template <typename T>
T array<T>::pop(int index = -1)
{
    T last = this->operator[](index);
    erase(end() - 1);
    return last;
}

template <typename T>
bool array<T>::_is_iterator_valid(iterator it)
{
    return (it >= _data && it < _data + _size);
}

template <typename T>
void array<T>::erase(iterator it)
{
    if (!_is_iterator_valid(it))
        return;

    array<T>::iterator new_data = new T[_size - 1];

    for (int i = 0; i < it - _data; i++)
    {
        new_data[i] = _data[i];
    }

    for (int i = 0; i < end() - it - 1; i++)
    {
        new_data[i + (it - _data)] = it[i + 1];
    }

    --_size;

    iterator new_it = new_data + (it - _data);

    delete[] _data;
    _data = new_data;

    it = new_it;
}

// with reverse indexation
template <typename T>
T &array<T>::operator[](int i)
{
    return _data[i >= 0 ? i : _size + i];
}

template <typename T>
int array<T>::size() const
{
    return _size;
}