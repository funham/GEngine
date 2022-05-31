#pragma once

#include "containers/array.hpp"

class Level;
class Buffer;
class PostFX;

class Camera
{
public:
    Camera(Level *);

    void render(Buffer *);
    void add_fx(PostFX *);
    void del_fx(PostFX *);

private:
    array<PostFX *> _fx;
    Level *_lvl;
    vec2 pos;
    float fov;
};