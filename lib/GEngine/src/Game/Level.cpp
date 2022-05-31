#include "Level.hpp"
#include "Entity/GObj.hpp"

#include "stddef.h"

void Level::update(float dt)
{
	// TODO: detect collisions
	// TODO: solve collisions
	// TODO: update every element

	for (auto &gobj : _gobjects)
	{
		gobj->update(dt);
	}
}

const Level::obj_list_t &Level::get_objects()
{
	return _gobjects;
}

void Level::add_obj(Level::obj_p p)
{
	_gobjects.append(p);
}

bool Level::remove_obj(Level::obj_p p)
{
	auto it = _gobjects.find(p);

	if (it == _gobjects.end())
		return false; // bad ext_code

	_gobjects.erase(it);
	return true;
}

bool Level::has_obj(Level::obj_p p)
{
	return _gobjects.find(p) != _gobjects.end();
}
