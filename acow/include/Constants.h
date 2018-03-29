//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Constants.h                                                   //
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

namespace acow { namespace math {

//----------------------------------------------------------------------------//
// Constants                                                                  //
//----------------------------------------------------------------------------//
constexpr static float kPI              = float(3.14159265358979323846264338327950288);
constexpr static float k2PI             = float(kPI * 2.0f);
constexpr static float kDegrees2Radians = (kPI / 180.0f);
constexpr static float kRadians2Degrees = (180.0f / kPI);

} // namespace math
} // namespace acow
