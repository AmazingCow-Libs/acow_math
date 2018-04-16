#pragma once
// std
#include <vector>
// AmazingCow Libs
#include "acow/cpp_goodies.h"


namespace acow { namespace math {

class Coord
{
    //------------------------------------------------------------------------//
    // Enums / Constants / Typedefs                                           //
    //------------------------------------------------------------------------//
public:
    ///-------------------------------------------------------------------------
    /// @brief Typedef to ease the typing of "a vector of Coords".
    typedef std::vector<Coord> Vec;


    //------------------------------------------------------------------------//
    // Static Methods                                                         //
    //------------------------------------------------------------------------//
public:
    #define DEFINE_COORD(_name_, _x_, _y_)        \
        ACOW_CONSTEXPR_STRICT inline static Coord \
        _name_() noexcept                         \
        {                                         \
            return Coord(_x_, _y_);               \
        }

        DEFINE_COORD(Up   ,  -1,  0)
        DEFINE_COORD(Down ,  +1,  0)
        DEFINE_COORD(Left ,   0, -1)
        DEFINE_COORD(Right,   0, +1)

    #undef DEFINE_COORD


    //------------------------------------------------------------------------//
    // Operators                                                              //
    //------------------------------------------------------------------------//
public:
    ///-------------------------------------------------------------------------
    /// @brief Check if two coords have the same y and x.
    ACOW_CONSTEXPR_STRICT friend inline bool
    operator ==(const Coord &lhs, const Coord rhs);

    ///-------------------------------------------------------------------------
    /// @brief Check if two coords have the different y and x.
    ACOW_CONSTEXPR_STRICT friend inline bool
    operator !=(const Coord &lhs, const Coord rhs);


    ///-------------------------------------------------------------------------
    /// @brief Adds the y and x.
    ACOW_CONSTEXPR_STRICT friend inline Coord
    operator +(const Coord &lhs, const Coord &rhs);

    ///-------------------------------------------------------------------------
    /// @brief Adds the y and x.
    ACOW_CONSTEXPR_LOOSE friend inline Coord&
    operator +=(Coord &lhs, const Coord &rhs) noexcept;


    ///-------------------------------------------------------------------------
    /// @brief Subtracts y and x.
    ACOW_CONSTEXPR_STRICT friend inline Coord
    operator -(const Coord &lhs, const Coord &rhs);

    ///-------------------------------------------------------------------------
    /// @brief Subtracts the y and x.
    ACOW_CONSTEXPR_LOOSE friend inline Coord&
    operator -=(Coord &lhs, const Coord &rhs) noexcept;


    ///-------------------------------------------------------------------------
    /// @brief Multiplies by a scalar.
    ACOW_CONSTEXPR_STRICT friend inline Coord
    operator *(const Coord &lhs, int scalar);

    ///-------------------------------------------------------------------------
    /// @brief Multiplies by a scalar.
    ACOW_CONSTEXPR_STRICT friend inline Coord
    operator *=(const Coord &lhs, int scalar);


    //------------------------------------------------------------------------//
    // CTOR/DTOR                                                              //
    //------------------------------------------------------------------------//
public:
    ///-------------------------------------------------------------------------
    /// @brief Constructs a Coord.
    /// @param y The Y coordinate - Default is 0.
    /// @param x The X coordinate - Default is 0.
    /// @note Coord is Y axis first - Take care with it.
    /// @warning Coord is Y axis first - Take care with it.
    ACOW_CONSTEXPR_STRICT inline explicit
    Coord(int y = 0, int x = 0) noexcept
        : y(y)
        , x(x)
    {
        // Empty...
    }


    //------------------------------------------------------------------------//
    // Public Methods                                                         //
    //------------------------------------------------------------------------//
public:
    ///-------------------------------------------------------------------------
    /// @brief Gets a Coord that is top of this coord.
    /// @param offset How many times it will be on top.
    /// @returns
    ///    A coord that have the y coordinate "offset" times less
    ///    than this coord.
    ACOW_CONSTEXPR_STRICT inline Coord
    GetUp(int offset = 1) const noexcept
    {
        return Coord(this->y - offset, this->x);
    }

    ///-------------------------------------------------------------------------
    /// @brief Gets a Coord that is bottom of this coord.
    /// @param offset How many times it will be on bottom.
    /// @returns
    ///    A coord that have the y coordinate "offset" times more
    ///    than this coord.
    ACOW_CONSTEXPR_STRICT inline Coord
    GetDown(int offset = 1) const
    {
        return Coord(this->y + offset, this->x);
    }

    ///-------------------------------------------------------------------------
    /// @brief Gets a Coord that is on left of this coord.
    /// @param offset How many times it will be on left.
    /// @returns
    ///    A coord that have the x coordinate "offset" times less
    ///    than this coord.
    ACOW_CONSTEXPR_STRICT inline Coord
    GetLeft(int offset = 1) const noexcept
    {
        return Coord(this->y, this->x - offset);
    }


    ///-------------------------------------------------------------------------
    /// @brief Gets a Coord that is on right of this coord.
    /// @param offset How many times it will be on right.
    /// @returns
    ///    A coord that have the x coordinate "offset" times more
    ///    than this coord.
    ACOW_CONSTEXPR_STRICT inline Coord
    GetRight(int offset = 1) const noexcept
    {
        return Coord(this->y, this->x + offset);
    }

    ///-------------------------------------------------------------------------
    /// @brief Gets a Coord that is in the middle of two coords.
    /// @param coord2 The second coord that will be compared.
    /// @returns
    ///    A coord that has the y and y coordinates specified
    ///    by formula: (c1.y + c2.y) / 2 and (c1.x + c2.x) / 2.
    ACOW_CONSTEXPR_STRICT inline Coord
    GetMiddle(const Coord &coord2) const noexcept
    {
        return Coord((this->y + coord2.y) / 2,
                     (this->x + coord2.x) / 2);
    }


    ///-------------------------------------------------------------------------
    /// @brief Gets a the orthogonal coords.
    /// @returns a vector of coords starting from top going clockwise.
    /// @see Coord::getSurrounding.
    inline Vec
    GetOrthogonal() const noexcept
    {
        return {
            GetUp   (),
            GetRight(),
            GetDown (),
            GetLeft ()
        };
    }

    ///-------------------------------------------------------------------------
    /// @brief Gets a the surrounding coords.
    /// @returns a vector of coords starting from top going clockwise.
    /// @see Coord::getSurrounding.
    inline Vec
    GetSurrounding() const noexcept
    {
        return {
            GetUp(),              // Top.
            GetUp().GetRight(),   // Top Right.

            GetRight(),           // Right.

            GetDown().GetRight(), // Bottom Right.
            GetDown(),            // Bottom.
            GetDown().GetLeft(),  // Bottom Left.

            GetLeft(),            // Left.

            GetUp().GetLeft()     // Top Left.
        };
    }


    ///-------------------------------------------------------------------------
    /// @brief Gets if the both coords have the same X coordinate.
    /// @returns True if they are at same X, false otherwise.
    /// @see isSameY().
    ACOW_CONSTEXPR_STRICT inline bool
    IsSameX(const Coord &coord2) const noexcept
    {
        return this->x == coord2.x;
    }

    ///-------------------------------------------------------------------------
    /// @brief Gets if the both coords have the same Y coordinate.
    /// @returns True if they are at same Y, false otherwise.
    /// @see isSameX().
    ACOW_CONSTEXPR_STRICT inline bool
    IsSameY(const Coord &coord2) const noexcept
    {
        return this->y == coord2.y;
    }


    ///-------------------------------------------------------------------------
    /// @brief Make the values of the Coord in range of (-1, 1).
    /// @see getUnit().
    inline void
    MakeUnit() noexcept
    {
        if(this->x != 0)
            this->x /= abs(this->x);

        if(this->y != 0)
            this->y /= abs(this->y);
    }

    ///-------------------------------------------------------------------------
    /// @brief Return a new Unit Coord with the values in range of(-1, 1).
    /// @returns A new Unit Coord.
    /// @see makeUnit();
    inline Coord
    GetUnit() const noexcept
    {
        auto ret = Coord(*this);
        ret.MakeUnit();

        return ret;
    }


    //------------------------------------------------------------------------//
    // iVars                                                                  //
    //------------------------------------------------------------------------//
public:
    i32 y, x;

}; // class Coord

//----------------------------------------------------------------------------//
// Operators                                                                  //
//----------------------------------------------------------------------------//
ACOW_CONSTEXPR_STRICT inline bool
operator ==(const Coord &lhs, const Coord rhs)
{
    return (lhs.y == rhs.y)
        && (lhs.x == rhs.x);
}

ACOW_CONSTEXPR_STRICT inline bool
operator !=(const Coord &lhs, const Coord rhs)
{
    return !(lhs == rhs);
}


ACOW_CONSTEXPR_STRICT inline Coord
operator +(const Coord &lhs, const Coord &rhs)
{
    return Coord(lhs.y + rhs.y, lhs.x + rhs.x);
}

ACOW_CONSTEXPR_LOOSE inline Coord&
operator +=(Coord &lhs, const Coord &rhs) noexcept
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;

    return lhs;
}


ACOW_CONSTEXPR_STRICT inline Coord
operator -(const Coord &lhs, const Coord &rhs)
{
    return Coord(lhs.y - rhs.y, lhs.x - rhs.x);
}

ACOW_CONSTEXPR_LOOSE inline Coord&
operator -=(Coord &lhs, const Coord &rhs) noexcept
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;

    return lhs;
}


ACOW_CONSTEXPR_STRICT inline Coord
operator *(const Coord &lhs, i32 scalar)
{
    return Coord(lhs.y * scalar, lhs.x * scalar);
}

ACOW_CONSTEXPR_LOOSE inline Coord&
operator *=(Coord &lhs, i32 scalar) noexcept
{
    lhs.x *= scalar;
    lhs.y *= scalar;

    return lhs;
}

} // namespace math
} // namespace acow
