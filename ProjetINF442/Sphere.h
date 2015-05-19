/*
 * Sphere.h
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#ifndef SPHERE_H_
#define SPHERE_H_

#include "Object.h"

class Sphere : public Object {

private :
//public:
	Point centre;
	double radius;

//    Color color;
    
    // shininess
//    double Ks[3], Kd[3], Ka[3], alpha;

public :
    
    //reflection coefficient
//    double r;

//	Sphere();//Constructeur par défaut, nécessaire pour pouvoir initialiser un set
	Sphere(const Point &centre, double radius, const Color &color, double Ks, double Kd, double Ka, double alpha, double r);//Constructeur
    
	Point getCentre() const;//Accès au centre
	double getRadius() const;//Accès au rayon
//    Color getColor() const;
    
    
    // Fonctions héritées
    
    virtual Vector normalAtPoint(const Point &point) const;
//    virtual Color phongReflectionColor(const Ray &ray, const Point &P,const Scene &scene) const;
    
    //Renvoie un boolean indiquant s'il y a intersection entre un rayon et une sphere
    //Le cas échéant stocke le point d'intersection dans la référence intersection_point
    virtual bool intersection(const Ray& ray, Point& intersection_point) const;
    
    
//    bool operator<(const Sphere &sphere) const;
//    bool operator!=(const Sphere &sphere) const;
};




#endif /* SPHERE_H_ */
