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

//Color Sphere::getColor() const {
//    return color;
//}

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

/**
 *  Modèle de réflection Phong pour la sphère.
 */
//Color Sphere::phongReflectionColor(const Ray &ray, const Point &P, const Scene &scene) const {
//    
//    Object* tempObject;
//    Point tempPoint;
//    double L_N, R_V_alpha;
//    
//    Vector N = normalAtPoint(P), L, R;
//    Vector V = Vector(P, ray.getPoint()).normalize();
//    
//    Color ambiant = scene.getAmbiantColor(), lightColor;
//    
//    double red = Ka[0] * ambiant.R,
//    green = Ka[1] * ambiant.G,
//    blue = Ka[2] * ambiant.B;
////    std::cout << "Ka = " << Ka[0] << " Kd = " << Kd[0] << " Ks = " << Ks[0] << std::endl;
//
//    std::set<Light>::iterator l;
//    
//    for (l = scene.lightsBegin(); l != scene.lightsEnd(); ++l) {
//        
//        L = Vector(P, l->getSource()).normalize();
//        if (L * N < 0) continue;
//        scene.firstObjectHitByRay(Ray(l->getSource(), L * (-1)), tempObject, tempPoint);
//        if (tempObject != this) continue;
//        
//        lightColor = l->getColor();
//        R = L.reflectedBy(N);
//        
//        L_N = L * N;
//        R_V_alpha = pow(R * V, alpha);
//        
//        red += lightColor.R * (Kd[0] * L_N + Ks[0] * R_V_alpha);
//        green += lightColor.G * (Kd[1] * L_N + Ks[1] * R_V_alpha);
//        blue += lightColor.B * (Kd[2] * L_N + Ks[2] * R_V_alpha);
//    }
//    
//    return Color((red   > 255) ? 255 : red,
//                 (green > 255) ? 255 : green,
//                 (blue  > 255) ? 255 : blue);
//}



//bool Sphere::operator<(const Sphere &sphere) const {
//    if (centre < sphere.centre)
//        return true;
//    if (sphere.centre < centre)
//        return false;
//    if (radius < sphere.radius)
//        return true;
//    if (radius > sphere.radius)
//        return false;
//    if (color < sphere.color)
//        return true;
//    if (sphere.color < color)
//        return false;
//    
//    return false;
//}
//
//
//bool Sphere::operator!=(const Sphere &sphere) const {
//    if (centre != sphere.centre)
//        return true;
//    if (radius != sphere.radius)
//        return true;
//    if (color != sphere.color)
//        return true;
//    
//    for (int i = 0; i < 3; i++) {
//        if (Ks[i] != sphere.Ks[i]) return true;
//        if (Kd[i] != sphere.Kd[i]) return true;
//        if (Ka[i] != sphere.Ka[i]) return true;
//    }
//    
//    if (alpha != sphere.alpha)
//        return true;
//    
//    return false;
//}

