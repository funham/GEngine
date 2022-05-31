#include "vec2.h"

vec2::vec2(float x, float y) : x(x), y(y) {}

float vec2::abs_sqr() const
{
    return x * x + y * y;
}

float vec2::abs() const
{
    return sqrt(abs_sqr());
}

vec2 &vec2::flip()
{
    x = -x;
    y = -y;

    return *this;
}

vec2 &vec2::operator=(vec2 v)
{
    x = v.x;
    y = v.y;
    return *this;
}

bool vec2::operator==(vec2 v) const
{
    return v.x == x && v.y == y;
}

bool vec2::operator!=(vec2 v) const
{
    return x != v.x || y != v.y;
}

vec2 vec2::operator-() const
{
    return {-x, -y};
}

vec2 vec2::operator+(vec2 v) const
{
    return vec2(x + v.x, y + v.y);
}

vec2 vec2::operator-(vec2 v) const
{
    return vec2(x - v.x, y - v.y);
}

void vec2::operator+=(vec2 v)
{
    x += v.x;
    y += v.y;
}

void vec2::operator-=(vec2 v)
{
    x -= v.x;
    y -= v.y;
}

vec2 vec2::operator*(float val) const
{
    return vec2{x * val, y * val};
}

vec2 vec2::operator/(float val) const
{
    return vec2{x / val, y / val};
}

void vec2::operator*=(float s)
{
    x *= s;
    y *= s;
}

void vec2::operator/=(float s)
{
    x /= s;
    y /= s;
}

float vec2::dist(vec2 v) const
{
    sqrt(dist_sqr(v));
}

float vec2::dist_sqr(vec2 v) const
{
    return (v - *this).abs_sqr();
}

float vec2::dot(vec2 v) const
{
    return dot(*this, v);
}

vec2 vec2::normalized() const
{
    return (*this) * Q_rsqrt(abs_sqr());
}

vec2 &vec2::normalize()
{
    return (*this) = normalized();
}

// may hurt later
float vec2::operator*(vec2 v) const
{
    return dot(v);
}

vec2 &vec2::rotate(float angle)
{
    float ca = cos(angle);
    float sa = sin(angle);

    return (*this) = {x * ca - y * sa,
                      x * sa + y * ca};
}

vec2 vec2::rotated(float angle) const
{
    float ca = cos(angle);
    float sa = sin(angle);

    return {x * ca - y * sa,
            x * sa + y * ca};
}

float vec2::angle() const
{
    return atan2(y, x);
}

vec2 operator*(float val, vec2 v)
{
    return v * val;
}

float vec2::dot(vec2 a, vec2 b)
{
    return (a.x * b.x + a.y * b.y);
}
