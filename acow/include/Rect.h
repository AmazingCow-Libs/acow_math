//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Rect.h                                                        //
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

// AmazingCow Libs
#include "acow/cpp_goodies.h"
// acow_math_goodies
#include "LibrarySupport.h"
#include "Vec2.h"
#include "Size.h"


namespace acow { namespace math {

class Rect
{
    //------------------------------------------------------------------------//
    // Static Methods                                                         //
    //------------------------------------------------------------------------//
public:
    #define DEFINE_RECT(_name_, _x_, _y_, _w_, _h_) \
        ACOW_CONSTEXPR_STRICT inline static Rect    \
        _name_() noexcept                           \
        {                                           \
            return Rect(_x_, _y_, _w_, _h_);        \
        }

    DEFINE_RECT(Empty, 0, 0, 0, 0)
    DEFINE_RECT(One,   1, 1, 1, 1)

    #undef DEFINE_RECT


    //------------------------------------------------------------------------//
    // CTOR / DTOR                                                            //
    //------------------------------------------------------------------------//
public:
    ACOW_CONSTEXPR_STRICT inline
    Rect() noexcept;

    ACOW_CONSTEXPR_STRICT inline
    Rect(const Vec2 &topLeft, const Size &size) noexcept;

    ACOW_CONSTEXPR_STRICT inline
    Rect(float x, float y, float w, float h) noexcept;

    #if (ACOW_MATH_HAS_SDL_SUPPORT)
    ACOW_CONSTEXPR_STRICT inline
    explicit Rect(const SDL_Rect &sdlRect) noexcept;
    #endif // (ACOW_MATH_HAS_SDL_SUPPORT)


    //------------------------------------------------------------------------//
    // Position                                                               //
    //------------------------------------------------------------------------//
public:
    ACOW_CONSTEXPR_STRICT inline float GetX() const noexcept;
    inline void  SetX(float x) noexcept;

    ACOW_CONSTEXPR_STRICT inline float GetY() const noexcept;
    inline void  SetY(float y) noexcept;

    ACOW_CONSTEXPR_STRICT inline float GetLeft() const noexcept;
    inline void  SetLeft(float pos) noexcept;

    ACOW_CONSTEXPR_STRICT inline float GetTop() const noexcept;
    inline void  SetTop(float pos) noexcept;

    ACOW_CONSTEXPR_STRICT inline float GetRight() const noexcept;
    inline void  SetRight(float pos) noexcept;

    ACOW_CONSTEXPR_STRICT inline float GetBottom() const noexcept;
    inline void  SetBottom(float pos) noexcept;

    ACOW_CONSTEXPR_STRICT inline Vec2 GetCenter() const noexcept;
    inline void SetCenter(const Vec2 &p) noexcept;


    //------------------------------------------------------------------------//
    // Origin                                                                 //
    //------------------------------------------------------------------------//
public:
    ACOW_CONSTEXPR_STRICT inline Vec2 GetTopLeft() const noexcept;
    inline void SetTopLeft(const Vec2 &p) noexcept;

    ACOW_CONSTEXPR_STRICT inline Vec2 GetBottomRight() const noexcept;
    inline void SetBottomRight(const Vec2 &p) noexcept;

    ACOW_CONSTEXPR_STRICT inline Vec2 GetTopRight() const noexcept;
    inline void SetTopRight(const Vec2 &p) noexcept;

    ACOW_CONSTEXPR_STRICT inline Vec2 GetBottomLeft() const noexcept;
    inline void SetBottomLeft(const Vec2 &p) noexcept;


    //------------------------------------------------------------------------//
    // Size                                                                   //
    //------------------------------------------------------------------------//
public:
    ACOW_CONSTEXPR_STRICT inline Size GetSize() const noexcept;
    inline void SetSize(const Size &s) noexcept;

    ACOW_CONSTEXPR_STRICT inline float GetWidth() const noexcept;
    inline void  SetWidth(float w) noexcept;

    ACOW_CONSTEXPR_STRICT inline float GetHeight() const noexcept;
    inline void  SetHeight(float h) noexcept;


    //------------------------------------------------------------------------//
    // Coords / Rect                                                          //
    //------------------------------------------------------------------------//
public:
    inline void SetCoords(float x1, float y1, float x2, float y2) noexcept;

    inline void SetRect(float x, float y, float w, float h) noexcept;
    inline void SetRect(const Rect &rect) noexcept;

    ACOW_CONSTEXPR_STRICT inline Rect GetRect() const noexcept;


    //------------------------------------------------------------------------//
    // Helper Methods                                                         //
    //------------------------------------------------------------------------//
public:
    ACOW_CONSTEXPR_STRICT inline bool IsEmpty() const;

    ACOW_CONSTEXPR_STRICT inline bool Contains(const Rect &r) const;
    ACOW_CONSTEXPR_STRICT inline bool Contains(const Vec2 &p) const;
    ACOW_CONSTEXPR_STRICT inline bool Contains(float x, float y) const;

    ACOW_CONSTEXPR_STRICT inline bool Intersects(const Rect &r) const noexcept;

    ACOW_CONSTEXPR_STRICT inline bool GetIntersection(
        const Rect &r,
        Rect *pOut_IntersectionRect) const noexcept;

    ACOW_CONSTEXPR_LOOSE Rect GetNormalized() const noexcept;
    void Normalize() noexcept;


    //------------------------------------------------------------------------//
    // Movement                                                               //
    //------------------------------------------------------------------------//
public:
    inline void MoveTo(float x, float y) noexcept;
    inline void MoveTo(const Vec2 &p) noexcept;

    inline void MoveLeft  (float delta) noexcept;
    inline void MoveTop   (float delta) noexcept;
    inline void MoveRight (float delta) noexcept;
    inline void MoveBottom(float delta) noexcept;

    inline void MoveTopLeft    (const Vec2 &delta) noexcept;
    inline void MoveBottomRight(const Vec2 &delta) noexcept;
    inline void MoveTopRight   (const Vec2 &delta) noexcept;
    inline void MoveBottomLeft (const Vec2 &delta) noexcept;
    inline void MoveCenter     (const Vec2 &delta) noexcept;

    inline void Translate(float dx, float dy) noexcept;
    inline void Translate(const Vec2 &delta) noexcept;

    inline Rect
    GetTranslated(float dx, float dy) const noexcept;

    inline Rect
    GetTranslated(const Vec2 &delta) const noexcept;


    //------------------------------------------------------------------------//
    // Operators                                                              //
    //------------------------------------------------------------------------//
public:
    ACOW_CONSTEXPR_STRICT friend inline bool
    operator==(const Rect &lhs, const Rect &rhs) noexcept;

    ACOW_CONSTEXPR_STRICT friend inline bool
    operator!=(const Rect &lhs, const Rect &rhs) noexcept;

    #if (ACOW_MATH_HAS_SDL_SUPPORT)
    ACOW_CONSTEXPR_STRICT inline
    explicit operator SDL_Rect() noexcept;
    #endif // (ACOW_MATH_HAS_SDL_SUPPORT)

    //------------------------------------------------------------------------//
    // iVars                                                                  //
    //------------------------------------------------------------------------//
public:
    float x; float y;
    float w; float h;

}; // class Rect


//----------------------------------------------------------------------------//
//                                                                            //
// Rect Definitions                                                           //
//                                                                            //
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
// CTOR / DTOR                                                                //
//----------------------------------------------------------------------------//
ACOW_CONSTEXPR_STRICT inline
Rect::Rect() noexcept
    : Rect(0,0,0,0)
{
    // Empty...
}

ACOW_CONSTEXPR_STRICT inline
Rect::Rect(const Vec2 &topLeft, const Size &size) noexcept
    : Rect(topLeft.x, topLeft.y, size.x, size.y)
{
    // Empty...
}


ACOW_CONSTEXPR_STRICT inline
Rect::Rect(float x, float y, float w, float h) noexcept
    : x(x), y(y), w(w), h(h)
{
    // Empty...
}

#if (ACOW_MATH_HAS_SDL_SUPPORT)
ACOW_CONSTEXPR_STRICT inline
Rect::Rect(const SDL_Rect &sdlRect) noexcept
    : Rect(sdlRect.x, sdlRect.y, sdlRect.w, sdlRect.w)
{
    // Empty...
}
#endif // (ACOW_MATH_HAS_SDL_SUPPORT)


//----------------------------------------------------------------------------//
// Position                                                                   //
//----------------------------------------------------------------------------//
// X
ACOW_CONSTEXPR_STRICT inline float
Rect::GetX() const noexcept  { return x; }

inline void
Rect::SetX(float x) noexcept { this->x = x; }

// Y
ACOW_CONSTEXPR_STRICT inline float
Rect::GetY() const noexcept  { return y; }

inline void
Rect::SetY(float y) noexcept { this-> y= y; }

// Left
ACOW_CONSTEXPR_STRICT inline float
Rect::GetLeft() const noexcept { return x; }

inline void
Rect::SetLeft(float pos) noexcept { x = pos; }

// Top
ACOW_CONSTEXPR_STRICT inline float
Rect::GetTop() const noexcept { return y; }

inline void
Rect::SetTop(float pos) noexcept { y = pos; }

// Right
ACOW_CONSTEXPR_STRICT inline float
Rect::GetRight() const noexcept { return (x + w); }

inline void
Rect::SetRight(float pos) noexcept { x = (pos - w); }

// Bottom
ACOW_CONSTEXPR_STRICT inline float
Rect::GetBottom() const noexcept { return (y + h); }

inline void
Rect::SetBottom(float pos) noexcept { y = (pos - h); }

// Center
ACOW_CONSTEXPR_STRICT inline Vec2
Rect::GetCenter() const noexcept
{
    return Vec2(x * (0.5f + w), y + (h * 0.5f));
}

inline void
Rect::SetCenter(const Vec2 &p) noexcept
{
    x = p.x - (w * 0.5f);
    y = p.y - (h * 0.5f);
}



//----------------------------------------------------------------------------//
// Origin                                                                     //
//----------------------------------------------------------------------------//
// Top Left
ACOW_CONSTEXPR_STRICT inline Vec2
Rect::GetTopLeft() const noexcept
{
    return Vec2(x, y);
}

inline void
Rect::SetTopLeft(const Vec2 &p) noexcept
{
    x = p.x;
    y = p.y;
}

// Bottom Right
ACOW_CONSTEXPR_STRICT inline Vec2
Rect::GetBottomRight() const noexcept { return Vec2(x + w, y + h); }

inline void
Rect::SetBottomRight(const Vec2 &p) noexcept
{
    SetRight (p.x);
    SetBottom(p.y);
}

// Top Right
ACOW_CONSTEXPR_STRICT inline Vec2
Rect::GetTopRight() const noexcept { return Vec2(x + w, y); }

inline void
Rect::SetTopRight(const Vec2 &p) noexcept
{
    SetRight(p.x);
    SetTop  (p.y);
}

// Bottom Left
ACOW_CONSTEXPR_STRICT inline Vec2
Rect::GetBottomLeft() const noexcept { return Vec2(x, y + h); }

inline void
Rect::SetBottomLeft(const Vec2 &p) noexcept
{
    SetLeft  (p.x);
    SetBottom(p.y);
}


//----------------------------------------------------------------------------//
// Size                                                                       //
//----------------------------------------------------------------------------//
// Size
ACOW_CONSTEXPR_STRICT inline Size
Rect::GetSize() const noexcept
{
    return Size(w, h);
}

inline void
Rect::SetSize(const Size &s) noexcept
{
    w = s.x;
    h = s.y;
}


// Width
ACOW_CONSTEXPR_STRICT inline float
Rect::GetWidth() const noexcept { return w; }

inline void
Rect::SetWidth(float w) noexcept { this->w = w; }


// Height
ACOW_CONSTEXPR_STRICT inline float
Rect::GetHeight() const noexcept { return h; }

inline void
Rect::SetHeight(float h) noexcept { this->h = h; }


//----------------------------------------------------------------------------//
// Coords / Rect                                                              //
//----------------------------------------------------------------------------//
// Coords
inline void
Rect::SetCoords(float x1, float y1, float x2, float y2) noexcept
{
    this->x = x1;       this->y = y1;
    this->w = x2 - x1 ; this->h = y2 - y1;
}

// Rect
inline void
Rect::SetRect(float x, float y, float w, float h) noexcept
{
   this->x = x; this->y = y;
   this->w = w; this->h = h;
}

inline void
Rect::SetRect(const Rect &rect) noexcept
{
    SetRect(rect.x, rect.y, rect.w, rect.h);
}

ACOW_CONSTEXPR_STRICT inline Rect
Rect::GetRect() const noexcept
{
    return *this;
}


//----------------------------------------------------------------------------//
// Helper Methods                                                             //
//----------------------------------------------------------------------------//
ACOW_CONSTEXPR_STRICT inline bool
Rect::IsEmpty() const
{
    return (w == 0) && (h == 0);
}

ACOW_CONSTEXPR_STRICT inline bool
Rect::Contains(const Rect &r) const
{
    // COWTODO(n2omatt): To implement...
    return true;
}

ACOW_CONSTEXPR_STRICT inline bool
Rect::Contains(const Vec2 &p) const
{
    // COWTODO(n2omatt): To implement...
    return true;
}

ACOW_CONSTEXPR_STRICT inline bool
Rect::Contains(float x, float y) const
{
    // COWTODO(n2omatt): To implement...
    return true;
}

ACOW_CONSTEXPR_STRICT inline bool
Rect::Intersects(const Rect &r) const noexcept
{
    // COWTODO(n2omatt): To implement...
    return true;
}

ACOW_CONSTEXPR_STRICT inline bool
Rect::GetIntersection(
    const Rect &r,
    Rect *pOut_IntersectionRect) const noexcept
{
    // COWTODO(n2omatt): To implement...
    return true;
}

//
//Rect Rect::GetNormalized() const noexcept
//{
//    Rect other(*this);
//    other.Normalize();
//
//    return other;
//}
//
//void Rect::Normalize() noexcept
//{
//    // COWTODO(n2omatt): To implement...
//}


//----------------------------------------------------------------------------//
// Movement                                                                   //
//----------------------------------------------------------------------------//
inline void
Rect::MoveTo(float x, float y) noexcept
{
    this->x = x;
    this->y = y;
}

inline void
Rect::MoveTo(const Vec2 &p) noexcept
{
    MoveTo(p.x, p.y);
}


inline void
Rect::MoveLeft(float delta) noexcept { this->x += delta; }

inline void
Rect::MoveTop(float delta) noexcept { this->y += delta; }

inline void
Rect::MoveRight(float delta) noexcept { this->x += delta; }

inline void
Rect::MoveBottom(float delta) noexcept { this->y = delta; }

inline void
Rect::MoveTopLeft(const Vec2 &delta) noexcept
{
    MoveLeft(delta.y);
    MoveTop (delta.y);
}

inline void
Rect::MoveBottomRight(const Vec2 &delta) noexcept
{
    MoveRight (delta.y);
    MoveBottom(delta.y);
}

inline void
Rect::MoveTopRight(const Vec2 &delta) noexcept
{
    MoveRight(delta.x);
    MoveTop  (delta.y);
}

inline void
Rect::MoveBottomLeft(const Vec2 &delta) noexcept
{
    MoveLeft  (delta.x);
    MoveBottom(delta.y);
}

inline void
Rect::MoveCenter(const Vec2 &delta) noexcept
{
    SetCenter(GetCenter() + delta);
}


inline void
Rect::Translate(float dx, float dy) noexcept
{
    x += dx;
    y += dy;
}

inline void
Rect::Translate(const Vec2 &delta) noexcept
{
    Translate(delta.x, delta.y);
}


inline Rect
Rect::GetTranslated(float dx, float dy) const noexcept
{
    Rect other(*this);
    other.Translate(dx, dy);

    return other;
}

inline Rect
Rect::GetTranslated(const Vec2 &p) const noexcept
{
    return GetTranslated(p.x, p.y);
}


//----------------------------------------------------------------------------//
// Operators                                                                  //
//----------------------------------------------------------------------------//
ACOW_CONSTEXPR_STRICT inline bool
operator==(const Rect &lhs, const Rect &rhs) noexcept
{
    return lhs.x == rhs.x
        && lhs.y == rhs.y
        && lhs.w == rhs.w
        && lhs.h == rhs.h;
}

ACOW_CONSTEXPR_STRICT inline bool
operator!=(const Rect &lhs, const Rect &rhs) noexcept
{
    return !(lhs == rhs);
}

#if (ACOW_MATH_HAS_SDL_SUPPORT)
ACOW_CONSTEXPR_STRICT inline
Rect::operator SDL_Rect() noexcept
{
    return SDL_Rect{
        i32(this->x),
        i32(this->y),
        i32(this->w),
        i32(this->h)
    };
}
#endif // (ACOW_MATH_HAS_SDL_SUPPORT)

} // namespace math
} // namespace acow
