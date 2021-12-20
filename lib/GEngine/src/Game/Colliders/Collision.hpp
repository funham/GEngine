#pragma once

#include "vec2.h"
#include "utils/math.hpp"
#include "utils/Array.hpp"

class Obj;

struct Hit
{
    vec2f a, b;
    bool is_valid = false;
};

struct Collision
{
    Obj *a, *b;
    Hit points;
};