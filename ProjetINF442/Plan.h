/*
 * Plan.h
 *
 *  Created on: 18 mai 2015
 *      Author: Boris
 */

#ifndef PLAN_H_
#define PLAN_H_

#include "Vector.h"
#include "Object.h"
#include "Color.h"

class Point;

class Plan : public Object{

//private :
public:
	Point point;
	Vector normale;

    Color color;

    // shininess
    double Ks[3] = {0}, Kd[3] = {0}, Ka[3] = {0}, alpha;

    //reflection coefficient
    double r;

public :

	Plan();//Constructeur par défaut, nécessaire pour pouvoir initialiser un set
	Plan(const Point &point, Vector normal, const Color &color, double Ks, double Kd, double Ka, double alpha, double r);//Constructeur

	Point getPoint() const;//Accès au centre
    Color getColor() const;

    Vector normalAtPoint(const Point &point) const;

    //Renvoie un boolean indiquant s'il y a intersection entre un rayon et un plan
    //Le cas échéant stocke le point d'intersection dans la référence intersection_point
    bool intersection(const Ray& ray, Point& intersection_point) const;

    Color phongReflectionColor(const Ray &ray, const Point &P, const Scene &scene) const;

    bool operator<(const Plan &plan) const;
    bool operator!=(const Plan &plan) const;
};




#endif /* PLAN_H_ */
