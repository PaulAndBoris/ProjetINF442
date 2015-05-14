/*
 * Intersection.cpp
 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */
#include <cmath>
#include "Intersection.h"

bool isIntersection(const Ray& ray, const Sphere& sphere) {

	Vector direction = ray.getDirection();
	Vector toCentre = Vector(ray.getPoint(), sphere.getCentre());
	bool result = ((direction ^ toCentre).norm() / direction.norm()
			< sphere.getRadius());

	return result;
}

//Resout la bonne équation quadratique (provient de l'équation paramétrique de la droite rayon)
bool intersection(const Ray& ray, const Sphere& sphere,
		Point& intersection_point) {

	Vector direction = ray.getDirection();
	Vector fromCentre = Vector(sphere.getCentre(), ray.getPoint());
//	Point centre = sphere.getCentre(); Non utilisé
	Point origine = ray.getPoint();

	//Coefficients de l'equation a*t^2+b*t+c=0
	double a = direction * direction;
	double b = fromCentre * direction * 2;
	double c = fromCentre * fromCentre
			- sphere.getRadius() * sphere.getRadius();

	double delta = b * b - 4 * a * c;
	bool result = (delta >= 0);

	if (result) {
		double t1 = (-b + sqrt(delta)) / (2 * a);
		double t2 = (-b - sqrt(delta)) / (2 * a);
		double t_res;

		if ((t1 > 0 && t1 < t2) || (t1 > 0 && t2 <= 0))
			t_res = t1;
		else
			t_res = t2;

		Vector vec = direction * t_res;
		intersection_point = Point(vec.getX() + origine.getX(),
				vec.getY() + origine.getY(), vec.getZ() + origine.getZ());

	}

	return result;

}
