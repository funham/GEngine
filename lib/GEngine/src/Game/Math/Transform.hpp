#pragma once

#include "vec2.h"

class Transform
{
public:
    void move_relative(vec2 relative_dir)
    {
        pos += relative_dir * dir.x + relative_dir * dir.y;
    }

    vec2 pos;
    vec2 dir;
    vec2 scale;
};