#pragma once

// acow_math_utils
#include "Vec2.h"

namespace acow { namespace math {

class Size
{
    //------------------------------------------------------------------------//
    // CTOR / DTOR                                                            //
    //------------------------------------------------------------------------//
public:
    inline Size() noexcept;
    inline Size(const Vec2& v) noexcept;
    inline Size(float w, float h) noexcept;


    //------------------------------------------------------------------------//
    // Public Methods                                                         //
    //------------------------------------------------------------------------//
public:
    inline bool IsEmpty() const noexcept;

    inline float GetWidth () const noexcept;
    inline void SetWidth(float w) noexcept;

    inline float GetHeight() const noexcept;
    inline void SetHeight(float h) noexcept;


    //------------------------------------------------------------------------//
    // Operators                                                              //
    //------------------------------------------------------------------------//
public:
    inline explicit operator Vec2() const noexcept;

    friend inline bool operator ==(const Size &lhs, const Size &rhs) noexcept;
    friend inline bool operator !=(const Size &lhs, const Size &rhs) noexcept;


    //------------------------------------------------------------------------//
    // iVars                                                                  //
    //------------------------------------------------------------------------//
public:
    // Just to enable we to refere to the variable as we find fit.
    union {
        struct { float x;     float y;      };
        struct { float w;     float h;      };
        struct { float width; float height; };
    };

}; // class Size


//----------------------------------------------------------------------------//
//                                                                            //
//  Size Definitions                                                          //
//                                                                            //
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
// CTOR / DTOR                                                                //
//----------------------------------------------------------------------------//
inline Size::Size() noexcept
    : Size(0, 0)
{
    // Empty...
}

inline Size::Size(const Vec2& v) noexcept
    : Size(v.x, v.y)
{
    // Empty...
}

inline Size::Size(float w, float h) noexcept
    : width(w), height(h)
{
    // Empty...
}

//----------------------------------------------------------------------------//
// Public Methods                                                             //
//----------------------------------------------------------------------------//
inline bool Size::IsEmpty() const noexcept { return w == 0 && h == 0; }

inline float Size::GetWidth() const noexcept { return width; }
inline void Size::SetWidth(float w) noexcept { width = w;    }

inline float Size::GetHeight() const noexcept { return height; }
inline void Size::SetHeight(float h) noexcept { height = w;    }


//----------------------------------------------------------------------------//
// Operators                                                                  //
//----------------------------------------------------------------------------//
inline Size::operator Vec2() const noexcept { return Vec2(x, y); }

inline bool operator ==(const Size &lhs, const Size &rhs) noexcept
{
    return lhs.x == rhs.x
        && lhs.y == rhs.y;
}

inline bool operator !=(const Size &lhs, const Size &rhs) noexcept
{
    return !(lhs == rhs);
}

} // namespace math
} // namespace acow
