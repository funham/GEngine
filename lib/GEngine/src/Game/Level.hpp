#pragma once

#include "utils/Array.hpp"

class GObj;

class Level
{
private:
    // Game object array
    Array<GObj *> _gobjects;

public:
    // updates all objects or smth like that
    void update(float);

    // operations with Game objects
    const Array<GObj *> &get_objects();
    void add_obj(GObj *);
    void remove_obj(GObj *);
    bool has_obj(GObj *);
};