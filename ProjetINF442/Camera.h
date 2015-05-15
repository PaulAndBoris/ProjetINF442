/*
 * Camera.h
 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */
#ifndef CAMERA_H_
#define CAMERA_H_

#include "Ray.h"

class Camera {
    
private :
	Point eye, target;
	Vector up, right;
	//Dimensions de l'écran
	double width, height;
    //Resolution
    int cols, rows;

public:

	Camera(Point eye, Point target, Vector up, double width, double height, int cols, int rows);//Constructeur
    
    Ray rayForCoordinates(int x, int y) const;

};



#endif /* CAMERA_H_ */
