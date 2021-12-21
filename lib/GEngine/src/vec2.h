#pragma once

#include <cmath>
#include "utils/types.hpp"
#include "utils/math.hpp"

template <typename T>
struct vec2
{
    vec2() = default;
    vec2(T x, T y) : x(x), y(y) {}

    template <typename T2>
    vec2(vec2<T2> &vec)
    {
        x = static_cast<T>(vec.x);
        y = static_cast<T>(vec.y);
    }

    double abs_sqr() const
    {
        return x * x + y * y;
    }

    double abs() const
    {
        return sqrt(abs_sqr());
    }

    vec2 &operator=(const vec2 v)
    {
        x = v.x;
        y = v.y;
        return *this;
    }

    bool operator!=(vec2 v) const
    {
        return (v.x != x || v.y != y);
    }

    bool operator==(vec2 v) const
    {
        return (v.x == x && v.y == y);
    }

    vec2 operator-() const
    {
        return {-x, -y};
    }

    vec2 operator+(vec2 v) const
    {
        return vec2(x + v.x, y + v.y);
    }

    vec2 operator-(vec2 v) const
    {
        return vec2(x - v.x, y - v.y);
    }

    vec2 &operator+=(vec2 v)
    {
        (*this) = (*this) + v;
    }

    vec2 &operator-=(vec2 v)
    {
        (*this) = (*this) - v;
    }

    vec2 operator*(float val) const
    {
        return vec2{x * val, y * val};
    }

    vec2 operator/(T val) const
    {
        if (val != 0)
            return vec2{x / val, y / val};
        else
            throw("division by zero");
    }

    float dist(vec2 v) const
    {
        sqrt(dist_sqr);
    }

    float dist_sqr(vec2 v) const
    {
        return abs_sqr(v - *this);
    }

    float dot(vec2 v) const
    {
        return dot(*this, v);
    }

    static float dot(vec2, vec2);

    vec2 normalized() const
    {
        return (*this) * Q_rsqrt(abs_sqr());
    }

    void normalize()
    {
        (*this) = normalized();
    }

    float operator*(vec2 v) const
    {
        return dot(v);
    }

    void rotate(float angle)
    {
        float ca = cos(angle);
        float sa = sin(angle);

        (*this) = {x * ca - y * sa,
                   x * sa + y * ca};
    }

    void rotate(float angle) const
    {
        float ca = cos(angle);
        float sa = sin(angle);

        return {x * ca - y * sa,
                x * sa + y * ca};
    }

    float get_angle() const
    {
        return atan2(y, x);
    }

    void set_angle(float angle)
    {
        float mag = abs();

        x = mag * cos(angle);
        y = mag * sin(angle);
    }

    void inv_axis()
    {
        T tmp = x;
        x = y;
        y = tmp;
    }

    void inv_axis() const
    {
        return {y, x};
    }

    template <typename T2>
    operator vec2<T2>()
    {
        return {T2(x), T2(y)};
    }

    T x, y;
};

template <typename T>
vec2<T> operator*(float val, vec2<T> v)
{
    return v * val;
}

template <typename T>
float vec2<T>::dot(vec2<T> a, vec2<T> b)
{
    return (a.x * b.x + a.y * b.y);
}

using vec2f = vec2<float>;
