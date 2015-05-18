/*
 * Object.cpp
 *
 *  Created on: 18 mai 2015
 *      Author: Boris
 */
#include <cmath>
#include "Object.h"
#include"Plan.h"
#include"Sphere.h"
#include "Scene.h"
#include <typeinfo>

Object::~Object(){

}

Color Object::phongReflectionColor(const Ray &ray, const Point &P,
		const Scene &scene) const {

	Object* tempObject;
	Point tempPoint;
	double L_N, R_V_alpha;

	Vector N = normalAtPoint(P), L, R;
	Vector V = Vector(P, ray.getPoint()).normalize();

	Color ambiant = scene.getAmbiantColor(), lightColor;

	double red = Ka[0] * ambiant.R, green = Ka[1] * ambiant.G, blue = Ka[2]
			* ambiant.B;
//    std::cout << "Ka = " << Ka[0] << " Kd = " << Kd[0] << " Ks = " << Ks[0] << std::endl;

	std::set<Light>::iterator l;

	for (l = scene.lightsBegin(); l != scene.lightsEnd(); ++l) {

		L = Vector(P, l->getSource()).normalize();
		if (L * N < 0)
			continue;
		scene.firstObjectHitByRay(Ray(l->getSource(), L * (-1)), *tempObject,
				tempPoint);
		if (*tempObject != *this)
			continue;

		lightColor = l->getColor();
		R = L.reflectedBy(N);

		L_N = L * N;
		R_V_alpha = pow(R * V, alpha);

		red += lightColor.R * (Kd[0] * L_N + Ks[0] * R_V_alpha);
		green += lightColor.G * (Kd[1] * L_N + Ks[1] * R_V_alpha);
		blue += lightColor.B * (Kd[2] * L_N + Ks[2] * R_V_alpha);
	}

	return Color((red > 255) ? 255 : red, (green > 255) ? 255 : green,
			(blue > 255) ? 255 : blue);
}

bool Object::operator!=(const Object &object) const {

	//const Sphere* x = dynamic_cast<const Sphere*>(this);
	//const Sphere *y = dynamic_cast<const Sphere*>(&object);

	//if (x != NULL && y != NULL)
	if (typeid(this) == typeid(Sphere)&&typeid(object) == typeid(Sphere))
		return (*this) != object;

	else {
		//const Plan* x = dynamic_cast<const Sphere*>(this);
		//const Plan *y = dynamic_cast<const Sphere*>(&object);

		if (typeid(this) == typeid(Plan)&&typeid(object) == typeid(Plan))
			return (*this) != object;

		//if (x != NULL && y != NULL)
			//return &x != &y;
	}

	return true;
}
