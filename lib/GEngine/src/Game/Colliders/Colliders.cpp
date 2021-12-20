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

    // ONLY IF SEG's ATTACHED TO THE ORIGIN
    Hit circSegCollision(CircCollider *circ, SegCollider *seg)
    {
        Hit hit;

        hit.a = circ->center - seg->normal * circ->radius; // closest circ's point to the seg
        hit.b = hit.a - seg->normal * (seg->normal.dot(hit.a));
        hit.is_valid = sign(seg->normal.dot(hit.a)) + 1; // ax + by >= 0 for {x, y} means it's above the line

        return hit;
    }

}