#include "Vector.hpp"

template <typename T>
T *Vector<T>::begin()
{
    return _data;
}

template <typename T>
T *Vector<T>::end()
{
    return _data + _size;
}

template <typename T>
T *Vector<T>::find(T &item)
{
    for (T &e : *this)
    {
        if (e == item)
            return &e;
    }
    return end();
}

template <typename T>
T *Vector<T>::find(T &&item)
{
    for (T &e : *this)
    {
        if (e == item)
            return &e;
    }
    return end();
}

template <typename T>
Vector<T> &Vector<T>::operator<<(const T &&item)
{
    push(item);
    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] _data;
}

template <typename T>
Vector<T> &Vector<T>::operator<<(const T &item)
{
    push(item);
    return *this;
}

// deletes last item and returns it's copy
template <typename T>
Vector<T> &Vector<T>::operator>>(T &item)
{
    T copy = back();
    item = copy;
    pop();

    return *this;
}

template <typename T>
T &Vector<T>::back()
{
    return _data[_size - 1];
}

template <typename T>
T &Vector<T>::front()
{
    return *_data;
}

// pushes item to the back
template <typename T>
void Vector<T>::push(const T &item)
{
    T *new_data = new T[_size + 1];

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
void Vector<T>::push(const T &&item)
{
    T *new_data = new T[_size + 1];

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
void Vector<T>::pop()
{
    erase(end() - 1);
}

template <typename T>
bool Vector<T>::_is_iterator_valid(const T *it)
{
    return (it >= _data && it < _data + _size);
}

template <typename T>
void Vector<T>::erase(T *&it)
{
    if (!_is_iterator_valid(it))
        return;

    T *new_data = new T[_size - 1];

    for (int i = 0; i < it - _data; i++)
    {
        new_data[i] = _data[i];
    }

    for (int i = 0; i < end() - it - 1; i++)
    {
        new_data[i + (it - _data)] = it[i + 1];
    }

    --_size;

    T *new_it = new_data + (it - _data);

    delete[] _data;
    _data = new_data;

    it = new_it;
}

template <typename T>
void Vector<T>::erase(T *&&it)
{
    if (!_is_iterator_valid(it))
        return;

    T *new_data = new T[_size - 1];

    for (int i = 0; i < it - _data; i++)
    {
        new_data[i] = _data[i];
    }

    for (int i = 0; i < end() - it - 1; i++)
    {
        new_data[i + (it - _data)] = it[i + 1];
    }

    --_size;

    delete[] _data;
    _data = new_data;
}

// with reverse indexation
template <typename T>
T &Vector<T>::operator[](int i)
{
    return _data[i >= 0 ? i : _size + i];
}

template <typename T>
int Vector<T>::size() const
{
    return _size;
}