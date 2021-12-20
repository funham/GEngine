#pragma once
#include "utils/types.hpp"
#include "vec2.h"

class Buffer;
struct Shape
{
    Shape() = default;
    Shape(vec2<u8> p0, bool fill_color);
    vec2<u8> p0;
    bool f_color = 1;
    virtual void draw(Buffer *) = 0;

protected:
    void _try_write(Buffer *, vec2<u8>);
};

struct PixShape : Shape
{
    PixShape() = default;
    PixShape(vec2<u8> p0, bool fill_color);
    virtual void draw(Buffer *) override;
};

struct SegShape : Shape
{
    SegShape() = default;
    SegShape(vec2<u8> p0, vec2<u8> p1, bool fill_color);
    vec2<u8> p1;
    virtual void draw(Buffer *) override;
};

struct RectShape : Shape
{
    RectShape() = default;
    RectShape(vec2<u8> p0, vec2<u8> size, bool fill_color);
    vec2<u8> size;
    virtual void draw(Buffer *) override;
};

struct CircShape : Shape
{
    u8 radius;
    virtual void draw(Buffer *) override;
};