/*
 * Objet.h
 *
 *  Created on: 18 mai 2015
 *      Author: Boris
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include "Color.h"
#include "Ray.h"
#include "Scene.h"


class Object {

private:
//	virtual ~Object();
    
//    Color color;

    // shininess
    double Ks[3], Kd[3], Ka[3], alpha;
    
    //reflection coefficient
    double r;
    
protected:
    
    Object();
    
public:
    
    double getR() const;
    
    void setColor(const Color &color, double Ks, double Kd, double Ka, double alpha, double r);
    
    Color phongReflectionColor(const Ray &ray, const Point &P, Scene* scene) const;
    
	virtual Vector normalAtPoint(const Point &point) const = 0;
	virtual bool intersection(const Ray& ray, Point& intersection_point) const = 0;

//    bool operator!=(const Object &object) const;
};

#endif /* OBJECT_H_ */
