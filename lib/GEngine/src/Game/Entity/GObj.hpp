#pragma once

#include "GENcore.hpp"

#include <Game/Math/Transform.hpp>
#include <Game/Math/Dynamics.hpp>

#include <Graphics/Sprite/Sprite.hpp>

class GObj
{
public:
    virtual void update(float) = 0;

    Transform transform;
    Dynamics dynamics;

    bool is_dynamic = false;
    bool has_gravity = false;

protected:
    class Level *_lvl;
    class Sprite *_sprite = EmptySprite::instance();
};

class Pawn : public GObj
{
public:
    virtual void handle_input() = 0;

protected:
    class Contoroller *controller;
};
