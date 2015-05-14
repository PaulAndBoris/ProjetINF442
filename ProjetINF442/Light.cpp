/*
 * Light.cpp
 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */
#include "Light.h"

Light::Light(Point source){ //Lumiere blanche
	this->source = source;
	this->R = 255;
	this->G = 255;
	this->B = 255;
};


Light::Light(Point source, int R, int G, int B){
	this->source = source;
	this->R = R;
	this->G = G;
	this->B = B;
};



