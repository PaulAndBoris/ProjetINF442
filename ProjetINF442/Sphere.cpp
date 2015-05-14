/*
 * Sphere.cpp
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#include <iostream>
#include "Sphere.h"

Sphere::Sphere(Point centre, double radius, int R, int G, int B) {
	this->centre = centre;
	this->radius = radius;
	this->R = R;
	this->G = G;
	this->B = B;
}
;

Sphere::Sphere() {
	this->centre = Point();
	this->radius = 0;
	this->R = 0;
	this->G = 0;
	this->B = 0;

}
;

Point Sphere::getCentre() const{
	return this->centre;
}

double Sphere::getRadius() const{
	return this->radius;
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
    if (R < sphere.R)
        return true;
    if (R > sphere.R)
        return false;
    if (G < sphere.G)
        return true;
    if (G > sphere.G)
        return false;
    if (B < sphere.B)
        return true;
    if (B > sphere.B)
        return false;
    
    return false;
}
