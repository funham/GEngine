#include "Shape.h"
#include "vec2.h"
#include "math.h"
#include "utils/math.hpp"

#include "Graphics/buffer.hpp"

Shape::Shape(vec2<u8> p0, bool fill_color = true)
    : p0(p0), f_color(fill_color)
{
}

void Shape::_try_write(Buffer *buff, vec2<u8> p)
{
    if (p.x < 0 || p.x >= buff->w || p.y < 0 || p.y >= buff->h)
    {
        return;
    }

    buff->on(p) = f_color;
}

PixShape::PixShape(vec2<u8> p0, bool fill_color = true)
    : Shape(p0, fill_color)
{
}

void PixShape::draw(Buffer *buff)
{
    _try_write(buff, p0);
}

SegShape::SegShape(vec2<u8> p0, vec2<u8> p1, bool fill_color = true)
    : Shape(p0, fill_color), p1(p1)
{
}

void SegShape::draw(Buffer *buff)
{
    u8 err = 0;
    u8 y = p0.y;

    s8 dy = p1.y - p0.y;
    s8 dx = p1.x - p0.x;
    s8 dir = sign(dy);

    for (u8 x = p0.x; x < p1.x; x++)
    {
        _try_write(buff, {x, y});

        err += fabs(dy);
        if (err >= dx)
        {
            y += dir;
        }
    }
}

RectShape::RectShape(vec2<u8> p0, vec2<u8> size,
                     bool fill_color = true)
    : Shape(p0, f_color), size(size)
{
}

void RectShape::draw(Buffer *buff)
{
    for (u8 x = 0; x < size.x; x++)
    {
        _try_write(buff, {x, p0.y});
        _try_write(buff, {x, p0.y + size.y - 1});
    }
    for (u8 y = 1; y < size.y - 1; y++)
    {
        _try_write(buff, {p0.x, y});
        _try_write(buff, {p0.x, p0.y + size.x - 1});
    }
}

void CircShape::draw(Buffer *buff)
{
    // float count = radius * 4;
    // float sect = 6.28318530718 / count;
    // float a = sect;

    // SegShape line({radius, 0}, {0, 0});

    // for (u8 i = 0; i < count; i++)
    // {
    //     line.p1 = radius * vec2f{cos(a), sin(a)};

    //     line.draw(buff);
    //     line.p0 = line.p1;
    // }

    // line.p1 = {radius, 0};
    // line.draw(buff);
}