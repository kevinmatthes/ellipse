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
 * \brief       Initiliase a new ellipse.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        init.cpp
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This is a private member function in addition to the constructors.  It will
 * initialise the held vectors.
 */

/******************************************************************************/

/*
 * Includes.
 */

#include "Ellipse.hpp"



/**
 * \brief   Initialise the held vectors.
 *
 * When creating a new ellipse from scratch, the held vectors will not contain
 * any elements, yet.  In order to avoid unintended side effects from this fact,
 * this function will assign initial elements to them.
 */

void Ellipse :: init (void)
{
    this -> centre  = vector <float> (0x3);
    this -> normal  = vector <float> (0x3);
    this -> tangent = vector <float> (0x3);

    this -> set_centre ();
    this -> set_normal ();
    this -> set_tangent ();

    return;
}

/******************************************************************************/
