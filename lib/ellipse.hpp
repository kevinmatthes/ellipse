/*
 * Copyright (C) 2021 Kevin Matthes
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/**
 * \file    ellipse.hpp
 * \brief   Introducing the `Ellipse' class.
 *
 * \author      Kevin Matthes
 * \copyright   (C) 2021 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2021
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 */

/******************************************************************************/

/*
 * Security settings.
 */

#pragma once
#ifndef __ELLIPSE_HPP__
#define __ELLIPSE_HPP__



/*
 * Includes.
 */

#include <functional>
#include <math>

using std::cosf;
using std::function;
using std::sinf;



/*
 * Class definition.
 */

class Ellipse
{
    private:
        float   major   {0.};
        float   minor   {0.};

        function <float (const float)>  x
            {[] (const float t) -> float {return major * cosf (t);};};

        function <float (const float)>  y
            {[] (const float t) -> float {return minor * sinf (t);};};

        function <float (const float)>  z
            {[] (const float t) -> float {return 0.f * t;};};

    public:
        Ellipse ( const float r     = 0.f
                , const float e     = 0.f
                , const float cx    = 0.f
                , const float cy    = 0.f
                , const float cz    = 0.f
                , const float tx    = 0.f
                , const float ty    = 0.f
                , const float tz    = 0.f
                , const float nx    = 0.f
                , const float ny    = 0.f
                , const float nz    = 0.f
                );

        vector <float> eval (const float t = 0.f);
};



/*
 * End of header.
 */

// Tidying up.
#ifndef __ELLIPSE_INTERNAL__
#endif  // ! __ELLIPSE_INTERNAL__

// Leaving the header.
#endif  // ! __ELLIPSE_HPP__

/******************************************************************************/
