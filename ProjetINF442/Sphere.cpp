/*
 * Sphere.cpp
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#include <iostream>

#include "Sphere.h"


Sphere::Sphere(Point centre, double radius, int R, int G, int B, double Ks, double Kd, double Ka, double alpha) :

centre(centre),
radius(radius),
color(R, G, B),
Ks(Ks),
Kd(Kd),
Ka(Ka),
alpha(alpha)
{}

Sphere::Sphere() :

centre(),
radius(0),
color(),
Ks(0),
Kd(0),
Ka(0),
alpha(0)
{}

Point Sphere::getCentre() const{
	return centre;
}

double Sphere::getRadius() const{
	return radius;
}

Color Sphere::getColor() const {
    return color;
}

Vector Sphere::normalAtPoint(const Point &point) const {
    return Vector(centre, point).normalize();
}

bool Sphere::operator<(const Sphere &sphere) const {
    if (centre < sphere.centre)
        return true;
    if (sphere.centre < centre)
        return false;
    if (radius < sphere.radius)
        return true;
    if (radius > sphere.radius)
        return false;
    if (color < sphere.color)
        return true;
    if (sphere.color < color)
        return false;
    
    return false;
}
