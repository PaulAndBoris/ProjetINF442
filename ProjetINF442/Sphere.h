/*
 * Sphere.h
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#include "Point.h"

#ifndef SPHERE_H_
#define SPHERE_H_

class Sphere{

private :

	Point centre;
	double radius;


	//Couleurs, doivent être comprises entre 0 et 255
	int R;
	int G;
	int B;

public :

	Sphere();//Constructeur par défaut, nécessaire pour pouvoir initialiser un set
	Sphere(Point centre, double radius, int R, int G, int B);//Constructeur
	~Sphere();//Destructeur

};




#endif /* SPHERE_H_ */
