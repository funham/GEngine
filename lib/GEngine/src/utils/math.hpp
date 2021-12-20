#pragma once

#include "types.hpp"

template <typename T>
u8 sign(T x)
{
    return (x >= 0 ? 1 : -1);
}

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

float Q_rsqrt(float number)
{
    const float x2 = number * 0.5F;
    const float threehalfs = 1.5F;

    union
    {
        float f;
        uint32_t i;
    } conv = {number}; // member 'f' set to value of 'number'.
    conv.i = 0x5f3759df - (conv.i >> 1);
    conv.f *= threehalfs - x2 * conv.f * conv.f;
    return conv.f;
}