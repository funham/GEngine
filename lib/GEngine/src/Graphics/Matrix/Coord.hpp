#pragma once

#include "utils/types.hpp"

struct Coord
{
    Coord() = default;
    Coord(Coord &c) = default;
    Coord(Coord &&c) = default;

    Coord(s16 x, s16 y) : x(x), y(y) {}

    // (x, y) -> (y, x)
    void inverse()
    {
        x = x + y;
        y = x - y;
        x = x - y;
    }

    Coord inversed()
    {
        return {y, x};
    }

    u16 index(u16 buff_width, u16 buff_height) const noexcept
    {
        return Coord::index(x, y, buff_width, buff_height);
    }

    u16 index(const Coord &buff_size) const noexcept
    {
        return index(x, y, buff_size.x, buff_size.y);
    }

    static u16 index(u16 x, u16 y, const Coord &) noexcept;
    static u16 Coord::index(u16 x, u16 y, u16, u16) noexcept;

    // s16 for w^2 + h^2 <= 2^16
    s16 operator*(Coord c) const noexcept
    {
        return x * c.x + y * c.y;
    }

    Coord inversed() const
    {
        return Coord(y, x);
    }

    Coord &operator=(Coord v)
    {
        x = v.x;
        y = v.y;
        return *this;
    }

    bool operator==(Coord &&v) const
    {
        return v.x == x && v.y == y;
    }

    bool operator!=(Coord v) const
    {
        return x != v.x || y != v.y;
    }

    Coord operator-() const
    {
        return {-x, -y};
    }

    Coord operator+(Coord v) const
    {
        return Coord(x + v.x, y + v.y);
    }

    Coord operator-(Coord v) const
    {
        return Coord(x - v.x, y - v.y);
    }

    void operator+=(Coord v)
    {
        x += v.x;
        y += v.y;
    }

    void operator-=(Coord v)
    {
        x -= v.x;
        y -= v.y;
    }

    Coord operator*(s16 val) const
    {
        return Coord{x * val, y * val};
    }

    Coord operator/(s16 val) const
    {
        return Coord{x / val, y / val};
    }

    void operator*=(s16 s)
    {
        x *= s;
        y *= s;
    }

    void operator/=(s16 s)
    {
        x /= s;
        y /= s;
    }

    s16 x, y;
};

u16 Coord::index(u16 x, u16 y, const Coord &buff_size)
{
    return y * buff_size.x + buff_size.y;
}

u16 Coord::index(u16 x, u16 y, u16 buff_width, u16 buff_height)
{
    return y * buff_width + buff_height;
}
