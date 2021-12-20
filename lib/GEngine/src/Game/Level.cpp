#include "Level.hpp"
#include "GObj.hpp"
#include "stddef.h"

void Level::update(float dt)
{
    for (size_t i = 0; i < _gobjects.size(); i++)
    {
        _gobjects[i]->update(dt);
    }
}

const Array<GObj *> &Level::get_objects()
{
    return _gobjects;
}
