/*
 * Object.cpp
 *
 *  Created on: 18 mai 2015
 *      Author: Boris
 */

#include <cmath>

#include "Object.h"

//Object::~Object(){
//
//}
Object::Object() {
    
    this->alpha = 0;
    this->r = 0;
    
    // Définition des coefficients en fonction de la couleur de la surface (expérimental)
    this->Ka[0] = 0;
    this->Ka[1] = 0;
    this->Ka[2] = 0;
    
    this->Kd[0] = 0;
    this->Kd[1] = 0;
    this->Kd[2] = 0;
    
    this->Ks[0] = 0;//(color.R * Ks) / 255.0,
    this->Ks[1] = 0,//(color.G * Ks) / 255.0,
    this->Ks[2] = 0;//(color.B * Ks) / 255.0;
}

void Object::setColor(const Color &color, double Ks, double Kd, double Ka, double alpha, double r) {
    
    this->alpha = alpha;
    this->r = r;
    
    // Définition des coefficients en fonction de la couleur de la surface (expérimental)
    this->Ka[0] = (color.R * Ka) / 255.0;
    this->Ka[1] = (color.G * Ka) / 255.0;
    this->Ka[2] = (color.B * Ka) / 255.0;
    
    this->Kd[0] = (color.R * Kd) / 255.0;
    this->Kd[1] = (color.G * Kd) / 255.0;
    this->Kd[2] = (color.B * Kd) / 255.0;
    
    this->Ks[0] = Ks;//(color.R * Ks) / 255.0,
    this->Ks[1] = Ks,//(color.G * Ks) / 255.0,
    this->Ks[2] = Ks;//(color.B * Ks) / 255.0;
}

double Object::getR() const {
    return r;
}

Color Object::phongReflectionColor(const Ray &ray, const Point &P, Scene* scene) const {

	Object* tempObject;
	Point tempPoint;
	double L_N, R_V_alpha;

	Vector N = normalAtPoint(P), L, R;
	Vector V = Vector(P, ray.getPoint()).normalize();

	Color ambiant = scene->getAmbiantColor(), lightColor;

	double red = Ka[0] * ambiant.R,
    green = Ka[1] * ambiant.G,
    blue  = Ka[2] * ambiant.B;

//	std::set<Light*>::iterator l;
    std::vector<Light*>::const_iterator l;

	for (l = scene->lightsBegin(); l != scene->lightsEnd(); ++l) {

		L = Vector(P, (*l)->getSource()).normalize();
		if (L * N < 0)
			continue;
		scene->firstObjectHitByRay(Ray((*l)->getSource(), L * (-1)), tempObject,
				tempPoint);
		if (tempObject != this)
			continue;

		lightColor = (*l)->getColor();
		R = L.reflectedBy(N);

		L_N = L * N;
		R_V_alpha = pow(R * V, alpha);

		red   += lightColor.R * (Kd[0] * L_N + Ks[0] * R_V_alpha);
		green += lightColor.G * (Kd[1] * L_N + Ks[1] * R_V_alpha);
		blue  += lightColor.B * (Kd[2] * L_N + Ks[2] * R_V_alpha);
	}

	return Color((red > 255) ? 255 : red, (green > 255) ? 255 : green,
			(blue > 255) ? 255 : blue);
}

//bool Object::operator!=(const Object &object) const {
//
//	//const Sphere* x = dynamic_cast<const Sphere*>(this);
//	//const Sphere *y = dynamic_cast<const Sphere*>(&object);
//
//	//if (x != NULL && y != NULL)
//	if (typeid(this) == typeid(Sphere)&&typeid(object) == typeid(Sphere))
//		return (*this) != object;
//
//	else {
//		//const Plan* x = dynamic_cast<const Sphere*>(this);
//		//const Plan *y = dynamic_cast<const Sphere*>(&object);
//
//		if (typeid(this) == typeid(Plan)&&typeid(object) == typeid(Plan))
//			return (*this) != object;
//
//		//if (x != NULL && y != NULL)
//			//return &x != &y;
//	}
//
//	return true;
//}
