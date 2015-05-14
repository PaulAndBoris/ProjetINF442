/*
 * Ray.h
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#include "Point.h"
#include "Vector.h"

#ifndef RAY_H_
#define RAY_H_

class Ray{

private :
	Point point;
	Vector direction;

public :

	Ray(Point point, Vector direction);//Constructeur
	Vector getDirection() const;//Accès à la direction
	Point getPoint() const;//Accès au point

};



#endif /* RAY_H_ */
