#pragma once
#include "utils/Array.hpp"

class Buffer;
class Shape;

class PostFX
{
public:
    bool active = true;
    virtual void apply(Buffer *) = 0;
};

class Overlay : PostFX
{
public:
    void add(Shape *);
    virtual void apply(Buffer *) override;

private:
    Array<Shape *> _shapes;
};