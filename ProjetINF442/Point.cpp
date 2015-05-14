/*
 * Point.cpp
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#include <iostream>
#include "Point.h"

using namespace std;

Point::Point(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
;

Point::Point() {
	this->x = 0.;
	this->y = 0.;
	this->z = 0.;
}
;

double Point::getX() const{
	return (this->x);
}

double Point::getY() const{
	return (this->y);
}

double Point::getZ() const{
	return (this->z);
}


ostream& operator<<(ostream& os, const Point& p) {
	os << "(" << p.x << ", " << p.y << ", " << p.z << ")" << endl;
	return os;
}

bool Point::operator<(const Point &point) const {
    if (x < point.x)
        return true;
    if (x > point.x)
        return false;
    if (y < point.y)
        return true;
    if (y > point.y)
        return false;
    if (z < point.z)
        return true;
    if (z > point.z)
        return false;
    
    return false;
}