/*
 * Camera.cpp
 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */
#include "Camera.h"

Camera::Camera(Vector eye, Vector target, Vector up, double width,
		double height) {
	this->eye = eye;
	this->target = target;
	this->up = up;
	this->width = width;
	this->height = height;
}
;

