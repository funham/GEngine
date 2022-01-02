#pragma once

template <typename T>
class Vector
{
public:
    Vector() = default;
    ~Vector();

    // working with range-based loops
    T *begin();
    T *end();

    T *find(T &item);
    T *find(T &&item);

    // pushes item to the back
    void push(const T &item);
    void push(const T &&item);
    void pop();

    Vector &operator<<(const T &&item);
    Vector &operator<<(const T &item);
    Vector &operator>>(T &item);

    T &back();
    T &front();

    void erase(T *&it);
    void erase(T *&&it);

    // with reverse indexation
    T &operator[](int i);
    int size() const;

private:
    bool _is_iterator_valid(const T *);

private:
    T *_data = nullptr;
    int _size = 0;
};
