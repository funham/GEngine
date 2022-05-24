#pragma once

template <typename T>
bool in_range(T x, T x0, T x1)
{
    return (x - x0) * (x - x1) <= 0;
}

template <typename T>
bool in_range(T, Range<T>);

template <typename T>
struct Range
{
    T p0, p1;
    Range(T p0, T p1) : p0(p0), p1(p1) {}

    bool intersects(Range r) const
    {
        return in_range(r.p0, *this) ||
               in_range(r.p1, *this) ||
               in_range(this->p0, r) ||
               in_range(this->p1, r);
    }
};

template <typename T>
bool in_range(T x, Range<T> range)
{
    return (x - range.p0) * (x - range.p1) <= 0;
}

template <typename T>
Range<T> vec_to_range(T origin, T vec)
{
    return {origin, origin + vec};
}