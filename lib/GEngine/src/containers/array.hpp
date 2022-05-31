#pragma once

template <typename T>
class array
{
public:
    using iterator = T *;

    array() = default;
    ~array();

    // working with range-based loops
    iterator begin();
    iterator end();

    iterator find(const T &item);
    iterator find(const T &&item);

    // appends item to the back
    void append(const T &item);
    T pop(int index = -1);

    // alias to append and pop
    array &operator<<(const T &item);
    array &operator>>(T &item);

    T &back();
    T &front();

    void erase(iterator it);

    // with reverse indexation
    T &operator[](int i);
    int size() const;

private:
    bool _is_iterator_valid(iterator);

private:
    T *_data = nullptr;
    int _size = 0;
};
