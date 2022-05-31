#pragma once

#include <cmath>
#include "utils/math.hpp"

struct vec2
{
    vec2() = default;
    vec2(float x, float y);

    float abs_sqr() const;
    float abs() const;

    vec2 &operator=(vec2 v);
    vec2 operator-() const;
    vec2 &flip();

    bool operator==(vec2 v) const;
    bool operator!=(vec2 v) const;

    vec2 operator+(vec2 v) const;
    vec2 operator-(vec2 v) const;

    void operator+=(vec2 v);
    void operator-=(vec2 v);

    vec2 operator*(float val) const;
    vec2 operator/(float val) const;

    void operator*=(float s);
    void operator/=(float s);

    float dist(vec2 v) const;
    float dist_sqr(vec2 v) const;

    float dot(vec2 v) const;
    vec2 normalized() const;
    vec2 &normalize();

    // may hurt later
    float operator*(vec2 v) const;

    vec2 &rotate(float angle);
    vec2 rotated(float angle) const;
    float angle() const;

    static float dot(vec2, vec2);

    float x, y;

    static const vec2 zero;
    static const vec2 up;
    static const vec2 down;
    static const vec2 right;
    static const vec2 left;
};

const vec2 vec2::zero = vec2(0, 0);
const vec2 vec2::up = vec2(0, 1);
const vec2 vec2::down = vec2(0, -1);
const vec2 vec2::right = vec2(1, 0);
const vec2 vec2::left = vec2(-1, 0);
