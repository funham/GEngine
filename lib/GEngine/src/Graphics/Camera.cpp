#include <stddef.h>

#include "Camera.hpp"
#include "PostFX/PostFX.hpp"
#include "buffer.hpp"
#include "Game/Level.hpp"
#include "Game/GObj.hpp"

void Camera::add_fx(PostFX *fx)
{
    _fx.push(fx);
}

void Camera::del_fx(PostFX *fx)
{
    _fx.del(fx);
}

void Camera::render(Buffer *buff)
{
    auto objects = _lvl->get_objects();
    for (size_t i = 0; i < objects.size(); i++)
    {
        objects[i]->sprite->draw(buff);
    }

    for (size_t i = 0; i < _fx.size(); i++)
    {
        if (_fx[i]->active)
        {
            _fx[i]->apply(buff);
        }
    }
}
