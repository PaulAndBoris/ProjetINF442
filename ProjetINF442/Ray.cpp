/*
 * Ray.cpp
 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */
#include "Ray.h"

Ray::Ray(Point point, Vector direction){
	this->point = point;
	this->direction = direction;
};

Vector Ray::getDirection() const{
	return this->direction;
}

Point Ray::getPoint() const{
	return this->point;
}
