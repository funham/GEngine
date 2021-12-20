#pragma once

#include "vec2.h"
#include "utils/math.hpp"
#include "utils/Array.hpp"

class Obj;

struct CollisionPoints
{
    // A in B and B in A
    vec2f ab, ba; // in b, in a;
};

struct Collision
{
    Obj *a, *b;
    CollisionPoints points;
};