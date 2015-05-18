/*
 * Objet.h
 *
 *  Created on: 18 mai 2015
 *      Author: Boris
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include "Vector.h"
#include "Ray.h"
#include "Color.h"

class Scene;

class Object {

public:

	virtual ~Object();
    // shininess
     double Ks[3], Kd[3], Ka[3], alpha;

    //reflection coefficient
    double r;

	virtual Vector normalAtPoint(const Point &point) const = 0;
	virtual Color phongReflectionColor(const Ray &ray, const Point &P,const Scene &scene) const = 0;
	virtual bool intersection(const Ray& ray, Point& intersection_point) const = 0;

    bool operator!=(const Object &object) const;
};

#endif /* OBJECT_H_ */
