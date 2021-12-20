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
    virtual CollisionPoints collision(Collider *) = 0;
    virtual CollisionPoints collision(CircCollider *) = 0;
    virtual CollisionPoints collision(RectCollider *) = 0;
    virtual CollisionPoints collision(SegCollider *) = 0;
};

struct CircCollider : Collider
{
    vec2f center;
    float radius;

    CircCollider(vec2f c, float r) : center(c), radius(r){};

    virtual CollisionPoints collision(Collider *coll) override
    {
        return coll->collision(this);
    }

    virtual CollisionPoints collision(CircCollider *circ) override
    {
        return {};
    }

    virtual CollisionPoints collision(RectCollider *) override
    {
        return {};
    }

    virtual CollisionPoints collision(SegCollider *) override
    {
        return {};
    }
};

struct RectCollider : Collider
{
    vec2f p0, size;
    virtual CollisionPoints collision(Collider *coll) override
    {
        return coll->collision(this);
    }

    virtual CollisionPoints collision(CircCollider *) override
    {
        return {};
    }

    virtual CollisionPoints collision(RectCollider *rect) override
    {
    }

    virtual CollisionPoints collision(SegCollider *) override
    {
        return {};
    }
};

struct SegCollider : Collider
{
    float len;
    vec2f center, normal;

    virtual CollisionPoints collision(Collider *coll) override
    {
        return coll->collision(this);
    }

    virtual CollisionPoints collision(CircCollider *) override
    {
        return {};
    }

    virtual CollisionPoints collision(RectCollider *) override
    {
        return {};
    }

    virtual CollisionPoints collision(SegCollider *) override
    {
        return {};
    }
};