#include "Collision.hpp"
#include "Colliders.hpp"
#include "utils/math.hpp"
#include "math.h"
#include "vec2.h"

namespace algo
{
    Hit circCircCollision(CircCollider *a, CircCollider *b)
    {
        auto d = b->center - a->center;
        Hit hit;
        hit.is_valid = d.abs_sqr() <= (a->radius + b->radius) * (a->radius + b->radius);

        d.normalize();

        hit.a = a->radius * d;
        hit.b = b->radius * (-d);

        return hit;
    }

    Hit circSegCollision(CircCollider *circ, SegCollider *seg)
    {
        Hit hit;

        hit.a = circ->center - seg->normal * circ->radius + seg->center; // closest circ's point to the seg
        hit.dist = vec2f::dot(seg->normal, hit.a - seg->center);         // distance between seg & circ
        hit.b = hit.a - seg->normal * hit.dist;                          // closest seg's point to the circ
        hit.is_valid = sign(hit.dist) + 1;                               // ax + by >= 0 for {x, y} means it's above the line

        return hit;
    }

}