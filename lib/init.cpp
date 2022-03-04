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
 * \brief   Evaluate this ellipse for a certain parameter value.
 * \param   t       The point of time to evaluate this ellipse for.
 * \param   offset  The temporal offset regarding the evaluation.
 * \return  The evaluated curve point.
 *
 * This implementation of the evaluation method takes the point of time for
 * which the considered ellipse shall be evaluated as well as the temporal
 * offset.
 *
 * The point of time to evaluate the ellipse for could be the passed time since
 * the application was started, for instance.  In order to achieve a fixed
 * offset for the evaluation, `offset` can be provided.  In case it should be
 * omitted, another overload for this method is provided whose `offset` is set
 * to zero, by default.
 *
 * The returned curve point is stored as a `std :: vector` which contains the
 * x, y and z coordinates of the determined curve point in this order.
 */

vector <float> Ellipse :: eval (const float t, const float offset)
{
    vector <float>  ret {};

    ret.push_back (this -> x (t + offset));
    ret.push_back (this -> y (t + offset));
    ret.push_back (this -> z (t + offset));

    return ret;
}



/**
 * \brief   Evaluate this ellipse without any offset.
 * \param   t   The point of time to evaluate this ellipse for.
 * \return  The evaluated curve point.
 * \sa      eval (const float t, const float offset)
 *
 * This implementation of the evaluation method calls the other one with
 * `offset` being set to zero, by default.  Thus, this method will determine
 * the intended curve point without any offset.
 */

inline vector <float> Ellipse :: eval (const float t)
{
    return Ellipse :: eval (t, 0x0);
}


/******************************************************************************/
