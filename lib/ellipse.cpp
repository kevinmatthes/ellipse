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
 * \file    ellipse.cpp
 * \brief   Defining the `Ellipse' class.
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
 * Includes.
 */

#include "ellipse.hpp"



/*
 * Class definition.
 */

Ellipse :: Ellipse  ( const float r     = 0.f
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
                    )
{
    this -> major   = r + e;
    this -> minor   = r;

    const float bx  {ty * nz - tz * ny};
    const float by  {tz * nx - tx * nz};
    const float bz  {tx * ny - ty * nx};

    const float cx_ {cx + e};
    const float cy_ {cy + e};
    const float cz_ {cz + e};

    return;
}

vector <float> Ellipse :: eval (const float t = 0.f)
{
    vector <float>  ret {};

    ret.push_back (this -> x (t));
    ret.push_back (this -> y (t));
    ret.push_back (this -> z (t));

    return ret;
}

/******************************************************************************/
