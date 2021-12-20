#pragma once

#include "vec2.h"
#include "utils/math.hpp"
#include "Collision.hpp"

struct Collider;
struct CircCollider;
struct RectCollider;
struct SegCollider;

struct Collider
{
    virtual Hit collision(Collider *) = 0;
    virtual Hit collision(CircCollider *) = 0;
    virtual Hit collision(RectCollider *) = 0;
    virtual Hit collision(SegCollider *) = 0;
};

struct CircCollider : Collider
{
    vec2f center;
    float radius;

    CircCollider(vec2f c, float r) : center(c), radius(r){};

    virtual Hit collision(Collider *coll) override
    {
        return coll->collision(this);
    }

    virtual Hit collision(CircCollider *circ) override
    {
        return algo::circCircCollision(this, circ);
    }

    virtual Hit collision(RectCollider *) override
    {
        return {};
    }

    virtual Hit collision(SegCollider *) override
    {
        return {};
    }
};

struct RectCollider : Collider
{
    vec2f p0, size;
    virtual Hit collision(Collider *coll) override
    {
        return coll->collision(this);
    }

    virtual Hit collision(CircCollider *) override
    {
        return {};
    }

    virtual Hit collision(RectCollider *rect) override
    {
    }

    virtual Hit collision(SegCollider *) override
    {
        return {};
    }
};

struct SegCollider : Collider
{
    float len;
    vec2f center, normal;

    virtual Hit collision(Collider *coll) override
    {
        return coll->collision(this);
    }

    virtual Hit collision(CircCollider *) override
    {
        return {};
    }

    virtual Hit collision(RectCollider *) override
    {
        return {};
    }

    virtual Hit collision(SegCollider *) override
    {
        return {};
    }
};