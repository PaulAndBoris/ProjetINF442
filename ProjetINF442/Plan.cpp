/*
 * Plan.cpp
 *
 *  Created on: 18 mai 2015
 *      Author: Boris
 */

#include "Plan.h"
#include "Ray.h"


Plan::Plan(const Point &point, Vector normale, const Color &color, double Ks,
           double Kd, double Ka, double alpha, double r) :
point(point), normale(normale) {
    
    setColor(color, Ks, Kd, Ka, alpha, r);
}


Vector Plan::normalAtPoint(const Point &point) const {
	return normale;
}

bool Plan::intersection(const Ray& ray, Point& intersection_point) const {

	Vector direction = ray.getDirection();
	Vector N(normale);
	Point origine_ray = ray.getPoint();
	Point origine_plan = point;

	Vector toPlan = Vector(origine_ray, origine_plan);
    
    double z =  - (N * toPlan), dz = - (N * direction);

	if (z > 0 && dz > 0) {
		
        intersection_point = origine_ray + direction * (z / dz);
        return true;
        
	}

	return false;
}

