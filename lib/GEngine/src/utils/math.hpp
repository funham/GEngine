#pragma once

#include "types.hpp"
#include "range.hpp"

template <typename T>
s8 sign(T x)
{
    return (x > T(0)) - (x < T(0));
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