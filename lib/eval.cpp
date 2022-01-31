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
 * \brief       Evaluate curve points for the considered ellipse.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        eval.cpp
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 * \sa          Ellipse
 *
 * Since the `Ellipse` class models an ellipse by a parametrisation, it can be
 * evaluated for certain parameter values.  This parameter value needs to be
 * passed to this method, `eval`.
 *
 * Sometimes, the parameter value shall be evaluated with a certain offset.
 * Therefore, this file defines a set of overloads.
 */

/******************************************************************************/

/*
 * Includes.
 */

#include "Ellipse.hpp"



/**
 */



/******************************************************************************/
