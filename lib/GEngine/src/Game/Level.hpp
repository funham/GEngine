#pragma once

#include <containers/array.hpp>

class GObj;

class Level
{
    using obj_p = GObj *;
    using obj_list_t = array<obj_p>;

public:
    void update(float);

    const obj_list_t &get_objects();
    void add_obj(obj_p);
    bool remove_obj(obj_p); // 1 -> succsess; 0 -> obj not found
    bool has_obj(obj_p);

public:
    vec2 gravity = vec2::down * 9.8f;

private:
    obj_list_t _gobjects;
};