/*
 * Plan.h
 *
 *  Created on: 18 mai 2015
 *      Author: Boris
 */

#ifndef PLAN_H_
#define PLAN_H_

#include "Object.h"

class Plan : public Object {

private :

    Point point;
	Vector normale;


public :

	Plan(const Point &point, Vector normal, const Color &color, double Ks, double Kd, double Ka, double alpha, double r);//Constructeur

	Point getPoint() const;//Accès au centre

    Vector normalAtPoint(const Point &point) const;

    //Renvoie un boolean indiquant s'il y a intersection entre un rayon et un plan
    //Le cas échéant stocke le point d'intersection dans la référence intersection_point
    bool intersection(const Ray& ray, Point& intersection_point) const;

};




#endif /* PLAN_H_ */
