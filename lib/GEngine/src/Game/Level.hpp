#pragma once

#include "utils/Vector.hpp"

class GObj;

class Level
{
private:
    // Game object array
    Vector<GObj *> _gobjects;

public:
    // updates all objects or smth like that
    void update(float);

    // operations with Game objects
    const Array<GObj *> &get_objects();
    void add_obj(GObj *);
    void remove_obj(GObj *);
    bool has_obj(GObj *);
};