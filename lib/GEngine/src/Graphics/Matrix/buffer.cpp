#include "buffer.hpp"

Buffer::Buffer(u8 *buff, Coord s) : _buff(buff), size(s)
{
}

u8 Buffer::w() const noexcept { return size.x; }
u8 Buffer::h() const noexcept { return size.y; }

Buffer::Pixel Buffer::on(const Coord &coord) noexcept
{
    return Buffer::Pixel(_buff, size, coord);
}

Buffer::Pixel Buffer::on(u16 x, u16 y) noexcept
{
    return Buffer::Pixel(_buff, Coord::index(x, y, size));
}

Buffer::Pixel Buffer::on(u16 index) noexcept
{
    return Buffer::Pixel(_buff, index);
}

Buffer::Pixel Buffer::operator[](const Coord &coord) noexcept
{
    return Buffer::on(coord);
}

Buffer::Pixel Buffer::operator[](u16 index) noexcept
{
    return on(index);
}