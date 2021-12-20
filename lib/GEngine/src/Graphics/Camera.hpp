#pragma once

#include "utils/Array.hpp"

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
    Array<PostFX *> _fx;
    Level *_lvl;
};