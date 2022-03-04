/*
 * Copyright (C) 2022 Kevin Matthes
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
 * \author      Kevin Matthes
 * \brief       Construct a new ellipse.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        Ellipse.cpp
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This source file defines the constructor of the `Ellipse` class.
 */

/******************************************************************************/

/*
 * Includes.
 */

#include "Ellipse.hpp"



/**
 * \brief   The default constructor.
 *
 * This constructor will create an empty ellipse which contains just default
 * values.
 */

Ellipse :: Ellipse (void)
{
    this -> set_centre ();
    this -> set_eccentricity ();
    this -> set_major ();
    this -> set_minor ();
    this -> set_radius ();

    this -> x   = {[=] (const float t) -> float {return cos (t);}};
    this -> y   = {[=] (const float t) -> float {return sin (t);}};
    this -> z   = {[=] (const float t) -> float {return 0.f * t;}};

    return;
}



/**
 * \brief   Construct a new `Ellipse` instance from the given data.
 * \param   r   The radius.
 * \param   e   The eccentricity.
 * \param   cx  The x coordinate of the centre.
 * \param   cy  The y coordinate of the centre.
 * \param   cz  The z coordinate of the centre.
 * \param   tx  The x component of the tangent (Up Vector).
 * \param   ty  The y component of the tangent (Up Vector).
 * \param   tz  The z component of the tangent (Up Vector).
 * \param   nx  The x component of the normal (front face indication).
 * \param   ny  The y component of the normal (front face indication).
 * \param   nz  The z component of the normal (front face indication).
 *
 * This constructor will create a new ellipse from its radius, eccentricity,
 * centre, tangent and normal.  Thereby, the new ellipse is oriented in space
 * by the normal and the tangent.
 *
 * The normal is the normal of the plane the ellipse is situated in.  Hence, it
 * determines which side of the ellipse is a front face.  This information is
 * important for optimisation techniques such as Backface Culling.
 *
 * The tangent of the ellipse is one of the vectors which span the plane the
 * ellipse is embedded in.  Furthermore, the tangent acts as the ellipse's Up
 * Vector.  This aspect is required in order to transform the ellipse properly.
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
    this -> set_centre (cx, cy, cz);

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
    this -> z   = [=] (const float t) -> float {return 0.f * t;};

    return;

    float none = 0.f;

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

/******************************************************************************/
