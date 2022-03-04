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
 * \brief       The setter for `Ellipse :: normal`.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        set_normal.cpp
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * Since `normal` is a private attribute, it should be set exclusively using
 * this method.
 */

/******************************************************************************/

/*
 * Includes.
 */

#include "Ellipse.hpp"



/**
 * \brief   Reset this ellipse's normal.
 *
 * Set this ellipse's normal to `0.f, 1.f, 0.f`.
 */

inline void Ellipse :: set_normal (void)
{
    this -> set_normal (0.f, 1.f, 0.f);
    return;
}



/**
 * \brief   The setter method for `Ellipse :: normal`.
 * \param   normal  This ellipse's normal.
 *
 * Since `normal` is a private attribute, it should be set exclusively using
 * this method.
 */

void Ellipse :: set_normal (const vector <float> & normal)
{
    switch (normal.size ())
    {
        case 0x0:
            this -> set_normal ();
            break;

        case 0x1:
            this -> set_normal (normal[0x0], 0.f, 0.f);
            break;

        case 0x2:
            this -> set_normal (normal[0x0], normal[0x1], 0.f);
            break;

        default:
            this -> set_normal (normal[0x0], normal[0x1], normal[0x2]);
            break;
    };

    return;
}



/**
 * \brief   The setter method for `Ellipse :: normal`.
 * \param   x   This ellipse's normal's x component.
 * \param   y   This ellipse's normal's y component.
 * \param   z   This ellipse's normal's z component.
 *
 * Since `normal` is a private attribute, it should be set exclusively using
 * this method.
 */

inline void Ellipse :: set_normal (const float x, const float y, const float z)
{
    this -> normal[0x0] = x;
    this -> normal[0x1] = y;
    this -> normal[0x2] = z;
    return;
}

/******************************************************************************/
