//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Operations.h                                                  //
//  Project   : Cooper                                                        //
//  Date      : Nov 17, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// std
#include <cmath>
// AmazingCow Libs
#include "acow/cpp_goodies.h"


namespace acow { namespace math {

//----------------------------------------------------------------------------//
// Clamp                                                                      //
//----------------------------------------------------------------------------//
template <typename T> inline ACOW_CONSTEXPR_STRICT T 
Clamp(const T &v, const T &_min, const T &_max)
{
    //COWTODO(n2omatt): We might use std::min, std::max.
    //  So search about perfomance (I saw something on CPPCon...)
    if(v < _min) return _min;
    if(v > _max) return _max;

    return v;
}


//----------------------------------------------------------------------------//
// Lerp                                                                       //
//----------------------------------------------------------------------------//
ACOW_CONSTEXPR_STRICT inline float
Lerp(float s, float e, float t) noexcept
{
    //Precise formula from wikipedia:
    //  https://en.wikipedia.org/wiki/Linear_interpolation
    return (1.0f - t) * s + (t * e);
}


//----------------------------------------------------------------------------//
// Power of Two                                                               //
//----------------------------------------------------------------------------//
ACOW_CONSTEXPR_STRICT inline bool
IsPOT(unsigned int value) noexcept
{
    //--------------------------------------------------------------------------
    // Thanks to seander:
    //   https://graphics.stanford.edu/~seander/bithacks.html
    return (value && !(value & (value - 1)));
}

ACOW_CONSTEXPR_LOOSE inline unsigned int
ClosestPOT(unsigned int value) noexcept
{
    value--;
    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    value |= value >> 16;
    value++;

    return value;
}

//----------------------------------------------------------------------------//
// Min / Max                                                                  //
// Taken from seander's bitchacks:                                            //
//   https://graphics.stanford.edu/~seander/bithacks.html                     //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// Min
ACOW_CONSTEXPR_STRICT inline int
Min(int x, int y) noexcept
{
    return (y ^ ((x ^ y) & -(x < y)));
}

ACOW_CONSTEXPR_STRICT inline unsigned int
Min(unsigned int x, unsigned int y) noexcept
{
    return (y ^ ((x ^ y) & -(x < y)));
}

template <typename T> inline ACOW_CONSTEXPR_STRICT T
Min(T& x, T& y) noexcept
{
    return (x < y) ? x : y;
}

//------------------------------------------------------------------------------
// Max
ACOW_CONSTEXPR_STRICT inline int
Max(int x, int y) noexcept
{
    return (x ^ ((x ^ y) & -(x < y)));
}

ACOW_CONSTEXPR_STRICT inline unsigned int
Max(unsigned int x, unsigned int y) noexcept
{
    return (x ^ ((x ^ y) & -(x < y)));
}

template <typename T, typename U> inline ACOW_CONSTEXPR_STRICT T
Max(T& x, U& y) noexcept
{
    return (x > y) ? x : y;
}


} // namespace math
} // namespace acow
