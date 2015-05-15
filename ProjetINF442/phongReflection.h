//
//  phongReflection.h
//  Projet
//
//  Created by Paul VANHAESEBROUCK on 15/05/2015.
//  Copyright (c) 2015 PaulAndBoris. All rights reserved.
//

#ifndef __Projet__phongReflection__
#define __Projet__phongReflection__

#include "Ray.h"
#include "Light.h"

/**
 *  Retourne la couleur noire si pas d'intersection entre la phère et le rayon.
 */
Color phongReflectionColor(const Point& P, const Color &pointColor, const Ray &ray, const Vector &N, const Light &light, double Ks, double Kd, double Ka, double alpha);
#endif /* defined(__Projet__phongReflection__) */
