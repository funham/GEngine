#include "Collision.hpp"
#include "Colliders.hpp"
#include "utils/math.hpp"
#include "math.h"
#include "vec2.h"

namespace algo
{
    Hit collide(CircCollider *a, CircCollider *b)
    {
        Hit hit;

        auto dc = b->center - a->center;
        hit.dist = dc.abs_sqr() - (a->radius + b->radius) * (a->radius + b->radius);
        hit.is_valid = sign(hit.dist) + 1;
        hit.a = a->radius * dc.normalized();
        hit.b = b->radius * (-dc).normalized();

        return hit;
    }

    Hit collide(CircCollider *a, RectCollider *b)
    {
        Hit hit;

        return hit;
    }

    Hit collide(CircCollider *circ, SegCollider *seg)
    {
        Hit hit;

        hit.a = circ->center - seg->normal * circ->radius + seg->center; // closest circ's point to the seg
        hit.dist = vec2f::dot(seg->normal, hit.a - seg->center);         // distance between seg & circ
        hit.b = hit.a - seg->normal * hit.dist;                          // closest seg's point to the circ
        hit.is_valid = sign(hit.dist) + 1;                               // ax + by >= 0 for {x, y} means it's above the line

        return hit;
    }

    Hit collide(RectCollider *a, SegCollider *b)
    {
        Hit hit;

        return hit;
    }

    Hit collide(RectCollider *a, RectCollider *b)
    {
        Hit hit;

        return hit;
    }

    Hit collide(SegCollider *a, SegCollider *b)
    {
        Hit hit;

        return hit;
    }
}
