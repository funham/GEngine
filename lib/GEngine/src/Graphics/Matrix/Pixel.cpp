#include "buffer.hpp"

Buffer::Pixel::Pixel(u8 *buff,
                     u16 index)
    : _addr(buff + (index >> 3)),
      _mask(128 >> (index & 3))
{
}

Buffer::Pixel::Pixel(u8 *buff,
                     const Coord &buff_size,
                     const Coord &pos)
    : Pixel(buff, pos.index(buff_size))
{
}

template <bool v = true>
bool Buffer::Pixel::operator=(bool color) noexcept
{
    *(_addr) |= _mask;
    return color;
}

template <bool v = false>
bool Buffer::Pixel::operator=(bool color) noexcept
{
    *(_addr) &= ~_mask;
    return color;
}

Buffer::Pixel::operator bool() const noexcept
{
    return (*_addr) & _mask;
}