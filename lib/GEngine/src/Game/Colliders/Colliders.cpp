#include "Collision.hpp"
#include "Colliders.hpp"
#include "math.h"
#include "vec2.h"

namespace algo
{
    CollisionPoints CircCircCol(CircCollider *a, CircCollider *b)
    {
        return {(a->center - b->center).normalized() * b->radius,
                (b->center - a->center).normalized() * a->radius};
    }

    CollisionPoints RectRectCol(RectCollider *a, RectCollider *b)
    {
    }
}