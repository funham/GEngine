#pragma once

#include "Graphics/Sprite/Sprite.hpp"
#include "Math/Dynamics.hpp"

class Level;

class GObj
{
public:
    virtual void update(float) = 0;

    Sprite *sprite = EmptySprite::instance();

protected:
    Level *_lvl;
};

class Actor : public GObj
{
public:
    Dynamics dynamics;

public:
    virtual void update(float) override;
};