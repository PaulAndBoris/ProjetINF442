/*
 * Point.cpp
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#include "Point.h"
#include "Vector.h"
#include <cmath>

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


bool Point::operator!=(const Point &point) const {
    if (x != point.x)
        return true;
    if (y != point.y)
        return true;
    if (z != point.z)
        return true;
    
    return false;
}