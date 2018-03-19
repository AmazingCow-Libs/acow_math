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
    inline Rect() noexcept;
    inline Rect(const Vec2 &topLeft, const Vec2 &bottomRight) noexcept;
    inline Rect(const Vec2 &topLeft, const Size &size) noexcept;
    inline Rect(float x, float y, float w, float h) noexcept;

    #if (ACOW_MATH_HAS_SDL_SUPPORT)
    inline explicit Rect(const SDL_Rect &sdlRect) noexcept;
    #endif // (ACOW_MATH_HAS_SDL_SUPPORT)


    //------------------------------------------------------------------------//
    // Position                                                               //
    //------------------------------------------------------------------------//
public:
    inline float GetX() const noexcept;
    inline void  SetX(float x) noexcept;

    inline float GetY() const noexcept;
    inline void  SetY(float y) noexcept;

    inline float GetLeft() const noexcept;
    inline void  SetLeft(float pos) noexcept;

    inline float GetTop() const noexcept;
    inline void  SetTop(float pos) noexcept;

    inline float GetRight() const noexcept;
    inline void  SetRight(float pos) noexcept;

    inline float GetBottom() const noexcept;
    inline void  SetBottom(float pos) noexcept;

    inline Vec2 GetCenter() const noexcept;
    inline void SetCenter(const Vec2 &p) const noexcept;


    //------------------------------------------------------------------------//
    // Origin                                                                 //
    //------------------------------------------------------------------------//
public:
    inline Vec2 GetTopLeft() const noexcept;
    inline void SetTopLeft(const Vec2 &p) noexcept;

    inline Vec2 GetBottomRight() const noexcept;
    inline void SetBottomRight(const Vec2 &p) noexcept;

    inline Vec2 GetTopRight() const noexcept;
    inline void SetTopRight(const Vec2 &p) noexcept;

    inline Vec2 GetBottomLeft() const noexcept;
    inline void SetBottomLeft(const Vec2 &p) noexcept;


    //------------------------------------------------------------------------//
    // Size                                                                   //
    //------------------------------------------------------------------------//
public:
    inline Size GetSize() const noexcept;
    inline void SetSize(const Size &s) noexcept;

    inline float GetWidth() const noexcept;
    inline void  SetWidth(float w) noexcept;

    inline float GetHeight() const noexcept;
    inline void  SetHeight(float h) noexcept;


    //------------------------------------------------------------------------//
    // Coords / Rect                                                          //
    //------------------------------------------------------------------------//
public:
    inline void SetCoords(float x1, float y1, float x2, float y2) noexcept;

    inline void SetRect(float x, float y, float w, float h) noexcept;
    inline void SetRect(const Rect &rect) noexcept;

    inline Rect GetRect() const noexcept;


    //------------------------------------------------------------------------//
    // Helper Methods                                                         //
    //------------------------------------------------------------------------//
public:
    inline bool IsEmpty() const;

    inline bool Contains(const Rect &r) const;
    inline bool Contains(const Vec2 &p) const;
    inline bool Contains(float x, float y) const;

    inline bool Intersects(const Rect &r) const noexcept;
    inline bool GetIntersection(
        const Rect &r,
        Rect *pOut_IntersectionRect) const noexcept;

    Rect GetNormalized() const noexcept;
    void Normalize() noexcept;


    //------------------------------------------------------------------------//
    // Movement                                                               //
    //------------------------------------------------------------------------//
public:
    inline void MoveTo(float x, float y) noexcept;
    inline void MoveTo(const Vec2 &p) noexcept;

    inline void MoveLeft(float pos) noexcept;
    inline void MoveTop(float pos) noexcept;
    inline void MoveRight(float pos) noexcept;
    inline void MoveBottom(float pos) noexcept;
    inline void MoveTopLeft(const Vec2 &p) noexcept;
    inline void MoveBottomRight(const Vec2 &p) noexcept;
    inline void MoveTopRight(const Vec2 &p) noexcept;
    inline void MoveBottomLeft(const Vec2 &p) noexcept;
    inline void MoveCenter(const Vec2 &p) noexcept;

    inline void Translate(float dx, float dy) noexcept;
    inline void Translate(const Vec2 &p) noexcept;

    inline Rect GetTranslated(float dx, float dy) const noexcept;
    inline Rect GetTranslated(const Vec2 &p) const noexcept;


    //------------------------------------------------------------------------//
    // Operators                                                              //
    //------------------------------------------------------------------------//
public:
    friend inline bool operator==(const Rect &lhs, const Rect &rhs) noexcept;
    friend inline bool operator!=(const Rect &lhs, const Rect &rhs) noexcept;

    #if (ACOW_MATH_HAS_SDL_SUPPORT)
    inline explicit operator SDL_Rect() noexcept;
    #endif // (ACOW_MATH_HAS_SDL_SUPPORT)

    //------------------------------------------------------------------------//
    // iVars                                                                  //
    //------------------------------------------------------------------------//
public:
    union {
        struct { float x;  float y;  };
        struct { float x1; float y1; };
    };

    float x2, y2;
}; // class Rect


//----------------------------------------------------------------------------//
//                                                                            //
// Rect Definitions                                                           //
//                                                                            //
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
// CTOR / DTOR                                                                //
//----------------------------------------------------------------------------//
inline Rect::Rect() noexcept
    : Rect(0,0,0,0)
{
    // Empty...
}

inline Rect::Rect(const Vec2 &topLeft, const Vec2 &bottomRight) noexcept
    : Rect(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y)
{
    // Empty...
}

inline Rect::Rect(const Vec2 &topLeft, const Size &size) noexcept
    : Rect(topLeft.x, topLeft.y, size.w, size.y)
{
    // Empty...
}

inline Rect::Rect(float x, float y, float w, float h) noexcept
    : x1(x), y1(y), x2(x+w), y2(y+h)
{
    // Empty...
}

#if (ACOW_MATH_HAS_SDL_SUPPORT)
inline Rect::Rect(const SDL_Rect &sdlRect) noexcept
    : Rect(sdlRect.x, sdlRect.y, sdlRect.w, sdlRect.w)
{
    // Empty...
}
#endif // (ACOW_MATH_HAS_SDL_SUPPORT)


//----------------------------------------------------------------------------//
// Position                                                                   //
//----------------------------------------------------------------------------//
inline float Rect::GetX() const noexcept  { return x1; }
inline void  Rect::SetX(float x) noexcept { x1 = x;    }

inline float Rect::GetY() const noexcept  { return y1; }
inline void  Rect::SetY(float y) noexcept { y1 = y;    }

inline float Rect::GetLeft() const noexcept    { return x1; }
inline void  Rect::SetLeft(float pos) noexcept { x1 = pos;  }

inline float Rect::GetTop() const noexcept    { return y1; }
inline void  Rect::SetTop(float pos) noexcept { y1 = pos;  }

inline float Rect::GetRight() const noexcept    { return x2; }
inline void  Rect::SetRight(float pos) noexcept { x2 = pos;  }

inline float Rect::GetBottom() const noexcept    { return y2; }
inline void  Rect::SetBottom(float pos) noexcept { y2 = pos;  }

inline Vec2 Rect::GetCenter() const noexcept
{
    // COWTODO(n2omatt): To implement...
    return Vec2();
}

inline void Rect::SetCenter(const Vec2 &p) const noexcept
{
    // COWTODO(n2omatt): To implement...
}



//----------------------------------------------------------------------------//
// Origin                                                                     //
//----------------------------------------------------------------------------//
inline Vec2 Rect::GetTopLeft() const noexcept
{
    return Vec2(x1, y1);
}

inline void Rect::SetTopLeft(const Vec2 &p) noexcept
{
    x1 = p.x;
    y1 = p.y;
}


inline Vec2 Rect::GetBottomRight() const noexcept
{
    return Vec2(x2, y2);
}

inline void Rect::SetBottomRight(const Vec2 &p) noexcept
{
    // COWTODO(n2omatt): To implement...
}


inline Vec2 Rect::GetTopRight() const noexcept
{
    return Vec2(x2, y1);
}

inline void Rect::SetTopRight(const Vec2 &p) noexcept
{

}


inline Vec2 Rect::GetBottomLeft() const noexcept
{
   return Vec2(x2, y2);
}

inline void Rect::SetBottomLeft(const Vec2 &p) noexcept
{

}


//----------------------------------------------------------------------------//
// Size                                                                       //
//----------------------------------------------------------------------------//
inline Size Rect::GetSize() const noexcept
{
    return Size(x2-x1, y2-y1);
}

inline void Rect::SetSize(const Size &s) noexcept
{
    // COWTODO(n2omatt): To implement...
}


inline float Rect::GetWidth() const noexcept
{
    return x2 - x1;
}

inline void  Rect::SetWidth(float w) noexcept
{
    // COWTODO(n2omatt): To implement...
}


inline float Rect::GetHeight() const noexcept
{
    return y2 - y1;
}

inline void  Rect::SetHeight(float h) noexcept
{
    // COWTODO(n2omatt): To implement...
}


//----------------------------------------------------------------------------//
// Coords / Rect                                                              //
//----------------------------------------------------------------------------//
inline void Rect::SetCoords(float x1, float y1, float x2, float y2) noexcept
{
    this->x1 = x1; this->y1 = y1;
    this->x2 = x2; this->y2 = y2;
}


inline void Rect::SetRect(float x, float y, float w, float h) noexcept
{
   //COWTODO(n2omatt): implement....
}

inline void Rect::SetRect(const Rect &rect) noexcept
{
    //COWTODO(n2omatt): implement....
}

inline Rect Rect::GetRect() const noexcept
{
    return *this;
}


//----------------------------------------------------------------------------//
// Helper Methods                                                             //
//----------------------------------------------------------------------------//
inline bool Rect::IsEmpty() const
{
    return (x2 - x1) == 0
        && (y2 - y1) == 0;
}

inline bool Rect::Contains(const Rect &r) const
{
    // COWTODO(n2omatt): To implement...
    return true;
}

inline bool Rect::Contains(const Vec2 &p) const
{
    // COWTODO(n2omatt): To implement...
    return true;
}

inline bool Rect::Contains(float x, float y) const
{
    // COWTODO(n2omatt): To implement...
    return true;
}


inline bool Rect::Intersects(const Rect &r) const noexcept
{
    // COWTODO(n2omatt): To implement...
    return true;
}

inline bool Rect::GetIntersection(
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
inline void Rect::MoveTo(float x, float y) noexcept
{
    x1 = x; y1 = y;
}

inline void Rect::MoveTo(const Vec2 &p) noexcept
{
    MoveTo(p.x, p.y);
}


inline void Rect::MoveLeft(float pos) noexcept
{
    // COWTODO(n2omatt): Implement...
}

inline void Rect::MoveTop(float pos) noexcept
{
    // COWTODO(n2omatt): Implement...
}

inline void Rect::MoveRight(float pos) noexcept
{
    // COWTODO(n2omatt): Implement...
}

inline void Rect::MoveBottom(float pos) noexcept
{
    // COWTODO(n2omatt): Implement...
}

inline void Rect::MoveTopLeft(const Vec2 &p) noexcept
{
    // COWTODO(n2omatt): Implement...
}

inline void Rect::MoveBottomRight(const Vec2 &p) noexcept
{
    // COWTODO(n2omatt): Implement...
}

inline void Rect::MoveTopRight(const Vec2 &p) noexcept
{
    // COWTODO(n2omatt): Implement...
}

inline void Rect::MoveBottomLeft(const Vec2 &p) noexcept
{
    // COWTODO(n2omatt): Implement...
}

inline void Rect::MoveCenter(const Vec2 &p) noexcept
{
    // COWTODO(n2omatt): Implement...
}


inline void Rect::Translate(float dx, float dy) noexcept
{
    x1 += dx;
    y1 += dy;
}

inline void Rect::Translate(const Vec2 &p) noexcept
{
    Translate(p.x, p.y);
}


inline Rect Rect::GetTranslated(float dx, float dy) const noexcept
{
    Rect other(*this);
    other.Translate(dx, dy);

    return other;
}

inline Rect Rect::GetTranslated(const Vec2 &p) const noexcept
{
    return GetTranslated(p.x, p.y);
}


//----------------------------------------------------------------------------//
// Operators                                                                  //
//----------------------------------------------------------------------------//
inline bool operator==(const Rect &lhs, const Rect &rhs) noexcept
{
    return lhs.x1 == rhs.x1
        && lhs.y1 == rhs.y1
        && lhs.x2 == rhs.x2
        && lhs.y2 == rhs.y2;
}

inline bool operator!=(const Rect &lhs, const Rect &rhs) noexcept
{
    return !(lhs == rhs);
}

#if (ACOW_MATH_HAS_SDL_SUPPORT)
inline Rect::operator SDL_Rect() noexcept
{
    return SDL_Rect{
        int(this->x),
        int(this->y),
        int(this->GetWidth ()),
        int(this->GetHeight())
    };
}
#endif // (ACOW_MATH_HAS_SDL_SUPPORT)


} // namespace math
} // namespace acow
