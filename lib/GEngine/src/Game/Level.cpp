#include "Level.hpp"
#include "GObj.hpp"
#include "stddef.h"

void Level::update(float dt)
{

    for (size_t i = 0; i < _gobjects.size() - 1; i++)
    {
	for (size_t j = i; j < _gobjects.size(); j++)
	{
	    auto &a = _gobjects[i];
	    auto &b = _gobjects[j];
	
	    Hit hit = a->collider->collides(b->collider);
	    if (hit.is_valid)
	    {
		hit.solve(a->dynamics, b->dynamics);
	    }
	}
    }
    for (auto &gobj : _gobjects)
    {
        gobj->update(dt);
    }
}

const Vector<GObj *> &Level::get_objects()
{
    return _gobjects;
}
