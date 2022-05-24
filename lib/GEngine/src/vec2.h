#pragma once

#include <cmath>
#include "utils/types.hpp"
#include "utils/math.hpp"

struct vec2
{
    vec2() = default;
    vec2(float x, float y) : x(x), y(y) {}

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

    bool operator==(vec2 v) const
    {
        return (v.x == x && v.y == y);
    }

    bool operator!=(vec2 v) const
    {
        return !(v == *this);
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

    void operator+=(vec2 v)
    {
        (*this) = (*this) + v;
    }

    void operator-=(vec2 v)
    {
        this->operator=(this->operator-(v));
    }

    vec2 operator*(float val) const
    {
        return vec2{x * val, y * val};
    }

    vec2 operator/(float val) const
    {
        return vec2{x / val, y / val};
    }

    void operator*=(float val)
    {
        (*this) = this->operator*(val);
    }

    void operator/=(float val)
    {
        (*this) = this->operator/(val);
    }

    float dist(vec2 v) const
    {
        sqrt(dist_sqr(v));
    }

    float dist_sqr(vec2 v) const
    {
        return (v - *this).abs_sqr();
    }

    float dot(vec2 v) const
    {
        return dot(*this, v);
    }

    vec2 normalized() const
    {
        return (*this) * Q_rsqrt(abs_sqr());
    }

    vec2 &normalize()
    {
        return (*this) = normalized();
    }

    // may hurt later
    float operator*(vec2 v) const
    {
        return dot(v);
    }

    vec2 &rotate(float angle)
    {
        float ca = cos(angle);
        float sa = sin(angle);

        return (*this) = {x * ca - y * sa,
                          x * sa + y * ca};
    }

    vec2 rotated(float angle) const
    {
        float ca = cos(angle);
        float sa = sin(angle);

        return {x * ca - y * sa,
                x * sa + y * ca};
    }

    float angle() const
    {
        return atan2(y, x);
    }

    static float dot(vec2, vec2);

    float x, y;
};

vec2 operator*(float val, vec2 v)
{
    return v * val;
}

float vec2::dot(vec2 a, vec2 b)
{
    return (a.x * b.x + a.y * b.y);
}
