#pragma once

#include "vec2.h"
#include "Graphics/Matrix/buffer.hpp"
#include "Graphics/Shape/Shape.h"

class Sprite
{
public:
    struct Rect
    {
    };

public:
    virtual void draw(Buffer *) = 0;
};

// empty sprite for invisible Objects
class EmptySprite : public Sprite
{
private:
    EmptySprite() = default;

public:
    // literally does nothing
    virtual void draw(Buffer *) override
    {
    }

    // returns a pointer to the static singleton object
    static EmptySprite *instance()
    {
        static EmptySprite sprite;
        return &sprite;
    }
};

// simple rectangle
class RectSprite : public Sprite
{
public:
    bool f_color = true;

protected:
    RectShape _shape;

public:
    /*
    virtual void draw(Buffer *buff) override
    {
        _shape.f_color = f_color;
        _shape.size = rect.size;
        _shape.p0 = rect.pos;

        _shape.draw(buff);
    }*/
};
