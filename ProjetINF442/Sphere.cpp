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

/*Sphere::~Sphere() {
	delete[] &this->centre;
	delete[] &this->radius = 0;
	delete[] &this->R = 0;
	delete[] &this->G = 0;
	delete[] this->B = 0;

}*/

