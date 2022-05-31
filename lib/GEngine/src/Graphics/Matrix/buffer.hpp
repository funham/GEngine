#pragma once

#include "utils/types.hpp"
#include "Coord.hpp"

class Buffer
{
    class Pixel
    {
    public:
        Pixel(u8 *, u16);
        Pixel(u8 *, const Coord &, const Coord &);

        template <bool v>
        bool operator=(bool) noexcept;
        operator bool() const noexcept;

        // TODO next(), prev(), etc.

    private:
        u8 *_addr;
        const u8 _mask;
    };

public:
    Buffer(u8 *buff, Coord s) noexcept;

    u8 w() const noexcept;
    u8 h() const noexcept;

    Pixel on(const Coord &coord) noexcept;
    Pixel on(u16 x, u16 y) noexcept;
    Pixel on(u16 index) noexcept;

    Pixel operator[](const Coord &coord) noexcept;
    Pixel operator[](u16 index) noexcept;

    const Coord size;

private:
    u8 *_buff;
};
