//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Vec2.h                                                        //
//  Project   : acow_math_goodies                                             //
//  Date      : Feb 23, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// std
#include <cmath>
// AmazingCow Libs
#include "acow/cpp_goodies.h"
// acow_math_goodies
#include "Constants.h"


namespace acow { namespace math {

struct Vec2
{
    //------------------------------------------------------------------------//
    // Static Functions                                                       //
    //------------------------------------------------------------------------//
public:
    #define DEFINE_VEC2(_name_, _x_, _y_)        \
        ACOW_CONSTEXPR_STRICT inline static Vec2 \
        _name_() noexcept                        \
        {                                        \
            return Vec2(_x_, _y_);               \
        }

    DEFINE_VEC2(Zero, 0.0f, 0.0f)
    DEFINE_VEC2(One , 1.0f, 1.0f)
    DEFINE_VEC2(Half, 0.5f, 0.5f)

    DEFINE_VEC2(Left ,  -1.0f,  0.0f)
    DEFINE_VEC2(Right,  +1.0f,  0.0f)
    DEFINE_VEC2(Up   ,   0.0f, -1.0f)
    DEFINE_VEC2(Down ,   0.0f, +1.0f)

    #undef DEFINE_VEC2


    //-------------------------------------------------------------------------//
    // Public Vars                                                             //
    //-------------------------------------------------------------------------//
public:
    union {
        struct { float data[2];    };
        struct { float x; float y; };
        struct { float w; float h; };
    };


    //------------------------------------------------------------------------//
    // CTOR / DTOR                                                            //
    //------------------------------------------------------------------------//
public:
    ACOW_CONSTEXPR_STRICT explicit
    Vec2(float x = 0.0f, float y = 0.0f) noexcept
        : x(x), y(y)
    {
        // Empty...
    }


    //------------------------------------------------------------------------//
    // Magnitude                                                              //
    //------------------------------------------------------------------------//
public:
    ACOW_CONSTEXPR_LOOSE float
    Magnitude() const noexcept
    {
        return sqrtf(x*x + y*y);
    }

    ACOW_CONSTEXPR_STRICT float
    MagnitudeSqr() const noexcept
    {
        return (x*x) + (y*y);
    }


    //------------------------------------------------------------------------//
    // Distance                                                               //
    //------------------------------------------------------------------------//
public:
    ACOW_CONSTEXPR_LOOSE inline float
    Distance(const Vec2 v2) const noexcept
    {
        return sqrtf(
            (x - v2.x) * (x - v2.x) +
            (y - v2.y) * (y - v2.y)
        );
    }

    ACOW_CONSTEXPR_STRICT inline float
    DistanceSqr(const Vec2 v2) const noexcept
    {
        return (x - v2.x) * (x - v2.x)
             + (y - v2.y) * (y - v2.y);
    }


    //------------------------------------------------------------------------//
    // Normalize                                                              //
    //------------------------------------------------------------------------//
public:
    ACOW_CONSTEXPR_LOOSE inline
    void Normalize() noexcept
    {
        auto magnitude = Magnitude();
        x /= magnitude; y /= magnitude;
    }

    ACOW_CONSTEXPR_LOOSE inline Vec2
    Normalized() const noexcept
    {
        auto vec2 = Vec2(*this);
        vec2.Normalize();

        return vec2;
    }


    //------------------------------------------------------------------------//
    // Rotation                                                               //
    //------------------------------------------------------------------------//
public:
    ACOW_CONSTEXPR_LOOSE inline void
    Rotate(float degrees) noexcept
    {
        auto r = (degrees * math::kDegrees2Radians);
        auto s = sinf(r);
        auto c = cosf(r);

        x = (x * c - y * s);
        y = (x * s + y * c);
    }

    ACOW_CONSTEXPR_LOOSE inline Vec2
    Rotated(float degrees) const noexcept
    {
        auto vec2 = Vec2(*this);
        vec2.Rotate(degrees);

        return vec2;
    }


    //------------------------------------------------------------------------//
    // Operators                                                              //
    //------------------------------------------------------------------------//
public:
    friend ACOW_CONSTEXPR_STRICT Vec2
    operator +(const Vec2 &lhs, const Vec2 &rhs) noexcept;

    friend ACOW_CONSTEXPR_STRICT Vec2
    operator -(const Vec2 &lhs, const Vec2 &rhs) noexcept;

    friend ACOW_CONSTEXPR_STRICT Vec2
    operator *(const Vec2 &lhs, const Vec2 &rhs) noexcept;

    friend ACOW_CONSTEXPR_STRICT Vec2
    operator /(const Vec2 &lhs, const Vec2 &rhs) noexcept;


    friend ACOW_CONSTEXPR_LOOSE Vec2&
    operator +=(Vec2 &lhs, const Vec2 &rhs) noexcept;

    friend ACOW_CONSTEXPR_LOOSE Vec2&
    operator -=(Vec2 &lhs, const Vec2 &rhs) noexcept;

    friend ACOW_CONSTEXPR_LOOSE Vec2&
    operator *=(Vec2 &lhs, const Vec2 &rhs) noexcept;

    friend ACOW_CONSTEXPR_LOOSE Vec2&
    operator /=(Vec2 &lhs, const Vec2 &rhs) noexcept;


    friend ACOW_CONSTEXPR_STRICT Vec2
    operator*(const Vec2 &lhs, float scalar) noexcept;

    friend ACOW_CONSTEXPR_STRICT Vec2
    operator*(float scalar, const Vec2 &rhs) noexcept;

}; //struct Vec2


//----------------------------------------------------------------------------//
// Operators Implementation.                                                  //
//----------------------------------------------------------------------------//
ACOW_CONSTEXPR_STRICT inline Vec2
operator +(const Vec2 &lhs, const Vec2 &rhs) noexcept
{
    return Vec2(lhs.x + rhs.x, lhs.y + rhs.y);
}

ACOW_CONSTEXPR_STRICT inline Vec2
operator -(const Vec2 &lhs, const Vec2 &rhs) noexcept
{
    return Vec2(lhs.x - rhs.x, lhs.y - rhs.y);
}

ACOW_CONSTEXPR_STRICT inline Vec2
operator *(const Vec2 &lhs, const Vec2 &rhs) noexcept
{
    return Vec2(lhs.x * rhs.x, lhs.y * rhs.y);
}

ACOW_CONSTEXPR_STRICT inline Vec2
operator /(const Vec2 &lhs, const Vec2 &rhs) noexcept
{
    return Vec2(lhs.x / rhs.x, lhs.y / rhs.y);
}


ACOW_CONSTEXPR_LOOSE inline Vec2&
operator +=(Vec2 &lhs, const Vec2 &rhs) noexcept
{
    lhs.x += rhs.x; lhs.y += rhs.y;
    return lhs;
}

ACOW_CONSTEXPR_LOOSE inline Vec2&
operator -=(Vec2 &lhs, const Vec2 &rhs) noexcept
{
    lhs.x -= rhs.x; lhs.y -= rhs.y;
    return lhs;
}

ACOW_CONSTEXPR_LOOSE inline Vec2&
operator *=(Vec2 &lhs, const Vec2 &rhs) noexcept
{
    lhs.x *= rhs.x; lhs.y *= rhs.y;
    return lhs;
}

ACOW_CONSTEXPR_LOOSE inline Vec2&
operator /=(Vec2 &lhs, const Vec2 &rhs) noexcept
{
    lhs.x /= rhs.x; lhs.y /= rhs.y;
    return lhs;
}


ACOW_CONSTEXPR_STRICT inline Vec2
operator*(const Vec2 &lhs, float scalar) noexcept
{
    return Vec2(lhs.x * scalar, lhs.y * scalar);
}

ACOW_CONSTEXPR_STRICT inline Vec2
operator*(float scalar, const Vec2 &rhs) noexcept
{
    return rhs * scalar;
}

} // namespace math
} // namespace acow
