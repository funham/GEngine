#include "PostFX.hpp"
#include "Graphics/buffer.hpp"
#include "Graphics/Shape/Shape.h"

void Overlay::apply(Buffer *buff)
{
    for (size_t i = 0; i < _shapes.size(); i++)
    {
        _shapes[i]->draw(buff);
    }
}
