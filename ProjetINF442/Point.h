/*
 * Point.h
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#ifndef POINT_H_
#define POINT_H_

#include<iostream>

class Vector;

class Point {

private:

	double x, y, z;

public:
    
	Point();//Constructeur par défaut
	Point(double x, double y, double z); //Constructeur
    
    double distanceTo(const Point &p) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    Point operator+(const Vector &vec) const;
    
//    bool operator<(const Point &point) const;
//    bool operator!=(const Point &point) const;
	//Accesseurs :
	double getX() const;
	double getY() const;
	double getZ() const;

};
#endif /* POINT_H_ */
