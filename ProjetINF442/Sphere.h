/*
 * Sphere.h
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#ifndef SPHERE_H_
#define SPHERE_H_

#include "Point.h"
#include "Vector.h"
#include "Color.h"


class Sphere{

private :

	Point centre;
	double radius;

    Color color;
    
    // shininess
    double Ks, Kd, Ka, alpha;

public :

	Sphere();//Constructeur par défaut, nécessaire pour pouvoir initialiser un set
	Sphere(Point centre, double radius, int R, int G, int B, double Ks, double Kd, double Ka, double alpha);//Constructeur
    
	Point getCentre() const;//Accès au centre
	double getRadius() const;//Accès au rayon
    Color getColor() const;
    
    Vector normalAtPoint(const Point &point) const;
    
    bool operator<(const Sphere &sphere) const;
};




#endif /* SPHERE_H_ */
