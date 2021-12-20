#pragma once

#include "vec2.h"
#include "utils/math.hpp"

struct Dynamics
{
    vec2f pos;
    vec2f vel;
    vec2f acc;

    float mass;

    void do_kinematics(float dt)
    {
        vel += acc * dt;
        pos += vel * dt;
    }
};
