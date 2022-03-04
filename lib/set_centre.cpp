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
 * \brief       The setter for `Ellipse :: centre`.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        set_centre.cpp
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * Since `centre` is a private attribute, it should be set exclusively using
 * this method.
 */

/******************************************************************************/

/*
 * Includes.
 */

#include "Ellipse.hpp"



/**
 * \brief   Reset this ellipse's centre.
 *
 * Set this ellipse's centre to `0.f, 0.f, 0.f`.
 */

inline void Ellipse :: set_centre (void)
{
    this -> set_centre (0.f, 0.f, 0.f);
    return;
}



/**
 * \brief   The setter method for `Ellipse :: centre`.
 * \param   centre  This ellipse's centre.
 *
 * Since `centre` is a private attribute, it should be set exclusively using
 * this method.
 */

inline void Ellipse :: set_centre (const vector <float> & centre)
{
    switch (centre.size ())
    {
        case 0x0:
            this -> set_centre ();
            break;

        case 0x1:
            this -> set_centre (centre[0x0], 0.f, 0.f);
            break;

        case 0x2:
            this -> set_centre (centre[0x0], centre[0x1], 0.f);
            break;

        default:
            this -> set_centre (centre[0x0], centre[0x1], centre[0x2]);
            break;
    };

    return;
}



/**
 * \brief   The setter method for `Ellipse :: centre`.
 * \param   x   This ellipse's centre's x component.
 * \param   y   This ellipse's centre's y component.
 * \param   z   This ellipse's centre's z component.
 *
 * Since `centre` is a private attribute, it should be set exclusively using
 * this method.
 */

inline void Ellipse :: set_centre (const float x, const float y, const float z)
{
    this -> centre[0x0] = x;
    this -> centre[0x1] = y;
    this -> centre[0x2] = z;
    return;
}

/******************************************************************************/
