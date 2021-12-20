#pragma once

#include "vec2.h"

class Buffer
{
    using v2 = vec2<u8>;

private:
    u8 *_buff;
    const v2 _size;

    class Pixel
    {
    public:
        Pixel(u8 *buff, vec2<u8> buff_size, vec2<u8> pos)
        {
            _addr = buff + (buff_size.x * pos.y + pos.x) / 8;
            _mask = (1 << (pos.x % 8));
        }

        bool operator=(bool color)
        {

            if (color)
            {
                *(_addr) |= _mask;
            }
            else
            {
                *(_addr) &= ~_mask;
            }

            return color;
        }

        operator bool() const
        {
            return (*_addr) & _mask;
        }

    private:
        u8 *_addr;
        u8 _mask;
    };

public:
    Buffer(u8 *buff, v2 s)
        : _buff(buff), _size(s),
          size(_size), w(_size.x), h(_size.y)
    {
    }
    Pixel on(const v2 &coord)
    {
        return Pixel(_buff, _size, coord);
    }

    Pixel on(const v2 &&coord)
    {
        return Pixel(_buff, _size, coord);
    }

    const v2 &size;
    const u8 &w;
    const u8 &h;
};
