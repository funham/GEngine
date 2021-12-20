#pragma once

template <typename T>
class Array
{
public:
    Array() = default;

    virtual ~Array()
    {
        delete[] _data;
    }

    // analog to push()
    Array &operator<<(T &item)
    {
        push(item);
        return *this;
    }

    // analog to pop()
    Array &operator>>(T &item)
    {
        item = pop();
        return *this;
    }

    inline T &back()
    {
        return _data[_size - 1];
    }

    inline T &front()
    {
        return *_data;
    }

    // pushes item to the back
    void push(T item)
    {
        T *new_data = new T[_size + 1];

        for (int i = 0; i < _size; i++)
        {
            new_data[i] = _data[i];
        }

        new_data[_size] = item;
        ++size;

        delete[] _data;
        _data = new_data;
    }

    // deletes item at given index and returns its copy
    T pop(s32 i = -1)
    {
        // TODO should throw a NORMAL exception
        if (_size == 0)
            throw("popping from empty array");

        T *new_data = new T[--_size];

        if (i >= 0)
        {
            memcpy(new_data, _data, sizeof(T) * i);
            memcpy(new_data + i, _data + i + 1, _size - i);
        }
        else
        {
            memcpy(new_data, _data, sizeof(T) * _size + i);
            memcpy(new_data + _size + i, _data + _size + i, -i - 1);
        }

        T item(this->operator[](i));

        delete[] _data;
        _data = new_data;

        return item;
    }

    size_t index(const T &item)
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (_data[i] == item)
            {
                return i;
            }
        }

        return -1;
    }

    void del(T &item)
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (item == _data[i])
            {
                T *new_data = new T[--_size];

                memcpy(new_data, _data, sizeof(T) * i);
                memcpy(new_data + i, _data + i + 1, _size - i);

                delete[] _data;
                _data = new_data;

                return;
            }
        }
    }

    // with reverse indexation
    inline T &operator[](s32 i)
    {
        return _data[i >= 0 ? i : _size + i];
    }

    inline int size()
    {
        return _size;
    }

private:
    T *_data = nullptr;
    int _size = 0;
};