/*
 * Point.cpp
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#include <cmath>

#include "Point.h"
#include "Vector.h"


Point::Point() : x(0), y(0), z(0) {}

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

double Point::getX() const{
	return (this->x);
}

double Point::getY() const{
	return (this->y);
}

double Point::getZ() const{
	return (this->z);
}

double Point::distanceTo(const Point &p) const {
    double dx = p.x - x,
    dy = p.y - y,
    dz = p.z - z;
    
    return sqrt(dx*dx + dy*dy + dz*dz);
}

Point Point::operator+(const Vector &vec) const {
    return Point(x + vec.getX(), y + vec.getY(), z + vec.getZ());
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ", " << p.z << ")" << std::endl;
	return os;
}
