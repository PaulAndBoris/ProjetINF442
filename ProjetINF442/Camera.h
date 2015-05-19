/*
 * Camera.h
 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */
#ifndef CAMERA_H_
#define CAMERA_H_

#include "Ray.h"
#include "Color.h"
#include "Scene.h"

class Camera {
    
private :
	Point eye, target;
	Vector up, right;
	//Dimensions de l'écran
	double width, height;
    //Resolution
    int cols, rows;

    Scene* scene;
    
    //Nombre maximal de réflections
    int reflections;

public:

	Camera(const Point &eye, const Point &target, double width, double height, int cols, int rows, Scene* scene, const int reflections);//Constructeur
    
    Ray rayForCoordinates(int x, int y) const;
    Color colorForRay(const Ray &ray, int count) const;
    Color colorForCoordinates(int x, int y) const;
};



#endif /* CAMERA_H_ */
