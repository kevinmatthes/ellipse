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

#include "Ellipse.hpp"



/*
 * Class definition.
 */

Ellipse :: Ellipse  ( const float r
                    , const float e
                    , const float cx
                    , const float cy
                    , const float cz
                    , const float tx
                    , const float ty
                    , const float tz
                    , const float nx
                    , const float ny
                    , const float nz
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

    const float alpha   = acos (abs (nz) / sqrt (nx * nx + ny * ny + nz * nz));
    const float beta    = acos (abs (tx) / sqrt (tx * tx + ty * ty + tz * tz));

    const float major   {this -> major};
    const float minor   {this -> minor};

    this -> x   = [=] (const float t) -> float {return major * cos (t);};
    this -> y   = [=] (const float t) -> float {return minor * sin (t);};
    this -> z   = [=] (const float t) -> float {return 0x0 * t;};

    return;

    float   none    = 0.f;

    none = bx;
    none = by;
    none = bz;

    none = cx_;
    none = cy_;
    none = cz_;

    none = alpha;
    none = beta;

    none = none;
}

vector <float> Ellipse :: eval (const float t, const float offset)
{
    vector <float>  ret {};

    ret.push_back (this -> x (t + offset));
    ret.push_back (this -> y (t + offset));
    ret.push_back (this -> z (t + offset));

    return ret;
}

inline vector <float> Ellipse :: eval (const float t)
{
    return Ellipse :: eval (t, 0x0);
}

/******************************************************************************/
