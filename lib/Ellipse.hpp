/*
 * Copyright (C) 2021─2022 Kevin Matthes
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
 * \brief       Introducing the `Ellipse` class.
 * \copyright   (C) 2021--2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2021--2022
 * \file        Ellipse.hpp
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This is the main header of the repository introducing the `Ellipse` class.
 *
 * The introduced class is intended to model ellipses by a parametrisation for
 * 3D spaces.  The created ellipses are oriented by a normal and a tangent.
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

#include <cmath>
#include <functional>
#include <vector>

using std :: abs;
using std :: acos;
using std :: cos;
using std :: function;
using std :: sin;
using std :: sqrt;
using std :: vector;



/*
 * Settings.
 */

#ifdef  __WINDOWS__
#ifdef  __MAKE_DLL__
#define EXPORT __declspec (dllexport)
#else
#define EXPORT __declspec (dllimport)
#endif  // ! __MAKE_DLL__
#else
#define EXPORT
#endif  // ! __WINDOWS__



/**
 * \brief   A simple ellipse class.
 *
 * This class represents an ellipse in a 3D space, oriented by a normal and a
 * tangent.  The model will be a curve parametrised by time.
 *
 * The ellipse is assumed to be embedded into a plane whose normal will be used
 * in order to determine the orientation of the ellipse regarding front and back
 * faces.
 *
 * Since the ellipse can be rotated arbitrarily within its plane, a second
 * vector is required in order to determine which direction is up.  This
 * information is provided by the tangent.
 */

class Ellipse
{
    private:
        float                           eccentricity;
        float                           major;
        float                           minor;
        float                           radius;
        function <float (const float)>  x;
        function <float (const float)>  y;
        function <float (const float)>  z;
        vector <float>                  centre;
        vector <float>                  normal;
        vector <float>                  tangent;

        EXPORT  float                           get_eccentricity    (void);
        EXPORT  float                           get_major           (void);
        EXPORT  float                           get_minor           (void);
        EXPORT  float                           get_radius          (void);
        EXPORT  function <float (const float)>  get_x               (void);
        EXPORT  function <float (const float)>  get_y               (void);
        EXPORT  function <float (const float)>  get_z               (void);
        EXPORT  vector <float>                  get_centre          (void);
        EXPORT  vector <float>                  get_normal          (void);
        EXPORT  vector <float>                  get_tangent         (void);

        EXPORT  void    set_eccentricity    (void);
        EXPORT  void    set_eccentricity    (const float eccentricity);

        EXPORT  void    set_major   (void);
        EXPORT  void    set_major   (const float major);

        EXPORT  void    set_minor   (void);
        EXPORT  void    set_minor   (const float minor);

        EXPORT  void    set_radius  (void);
        EXPORT  void    set_radius  (const float radius);

        EXPORT  void    set_centre  (void);
        EXPORT  void    set_centre  (const vector <float> & centre);
        EXPORT  void    set_centre  ( const float x
                                    , const float y
                                    , const float z
                                    );


    public:
        EXPORT  Ellipse (void);
        EXPORT  Ellipse ( const float r
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
                        );

        EXPORT  vector <float> eval (const float t, const float offset);
        EXPORT  vector <float> eval (const float t);
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
