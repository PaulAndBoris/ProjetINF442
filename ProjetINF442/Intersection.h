/*
 * Intersection.h
 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */
#ifndef INTERSECTION_H_
#define INTERSECTION_H_

class Ray;
class Sphere;
class Point;

//Renvoie un boolean indiquant s'il y a intersection entre un rayon et une sphere
//Obsolète par rapport à intersection
bool isIntersection(const Ray& ray, const Sphere& sphere);

//Renvoie un boolean indiquant s'il y a intersection entre un rayon et une sphere
//Le cas échéant stocke le point d'intersection dans la référence intersection_point
bool intersection(const Ray& ray, const Sphere& sphere, Point& intersection_point);

#endif /* INTERSECTION_H_ */
