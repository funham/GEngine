#pragma once

#include "vec2.h"

template <u8 W, u8 H>
struct Matrix
{
    float *operator[](u16 i)
    {
        return data + i * W;
    }

    float data[W * H];
};

template <>
struct Matrix<1, 1>
{
    float data;

    operator float &()
    {
        return data;
    }
};