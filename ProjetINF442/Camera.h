/*
 * Camera.h
 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */
#include "Vector.h"
#include "Point.h"


#ifndef CAMERA_H_
#define CAMERA_H_

class Camera{

private :
	Vector eye;
	Vector target;
	Vector up;
	//Dimensions de l'écran
	double width;
	double height;

public:

	Camera(Vector eye, Vector target, Vector up, double width, double height);//Constructeur

};



#endif /* CAMERA_H_ */
