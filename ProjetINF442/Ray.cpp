/*
 * Ray.cpp
 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */
#include "Ray.h"

Ray::Ray(const Point &point, const Vector &direction) : point(point), direction(direction) {}

Vector Ray::getDirection() const{
	return direction;
}

Point Ray::getPoint() const{
	return point;
}
