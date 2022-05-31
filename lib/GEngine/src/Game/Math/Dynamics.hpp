#pragma once

#include "vec2.h"
#include "utils/math.hpp"

struct Dynamics
{
    vec2 force;
    vec2 velocity;
    float mass;

    // call just before update
    void apply_forces(float dt)
    {
        velocity += force * dt;
        force = vec2::zero;
    }
};
