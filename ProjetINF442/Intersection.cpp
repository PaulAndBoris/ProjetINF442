/*
 * Intersection.cpp
 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */

#include "Intersection.h"

bool intersection(const Ray& ray, const Sphere& sphere,
		Point& intersection_point) {

	Vector direction = ray.getDirection();
	Vector toCentre = Vector(ray.getPoint(), sphere.getCentre());
	bool result = ((direction ^ toCentre).norm() / direction.norm()
			< sphere.getRadius());

	return result;
}

