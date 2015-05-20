/*
 * Sphere.cpp
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */

#include <cmath>

#include "Sphere.h"
#include "Ray.h"


Sphere::Sphere(const Point &centre, double radius, const Color &color, double Ks, double Kd, double Ka, double alpha, double r) :

centre(centre),
radius(radius)
{
    setColor(color, Ks, Kd, Ka, alpha, r);
}

Point Sphere::getCentre() const{
	return centre;
}

double Sphere::getRadius() const{
	return radius;
}

Vector Sphere::normalAtPoint(const Point &point) const {
    return Vector(centre, point).normalize();
}


//Resout la bonne équation quadratique (provient de l'équation paramétrique de la droite rayon)
bool Sphere::intersection(const Ray& ray,
                  Point& intersection_point) const {
    
    Vector direction = ray.getDirection();
    Vector fromCentre = Vector(centre, ray.getPoint());
    Point origine = ray.getPoint();
    
    double epsilon=0.01;

    //Coefficients de l'equation a*t^2+b*t+c=0
    double a = direction * direction;
    double b = fromCentre * direction * 2;
    double c = fromCentre * fromCentre
    - radius * radius;
    
    double delta = b * b - 4 * a * c;
    bool result = (delta >= 0);
    
    if (result) {
        double t1 = (-b + sqrt(delta)) / (2 * a);
        double t2 = (-b - sqrt(delta)) / (2 * a);
        double t_res;
        //On considère qu'il n'y a pas intersection si le rayon part d'un point de la sphère
        if (t1 > epsilon && (t1 <= t2 || t2 < 0))
            t_res = t1;
        else if (t2 > epsilon)
            t_res = t2;
        else
            return false;
        
        Vector vec = direction * t_res;
        intersection_point = Point(vec.getX() + origine.getX(),
                                   vec.getY() + origine.getY(), vec.getZ() + origine.getZ());
        
    }
    
    return result;
}
