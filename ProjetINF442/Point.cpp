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
	this->x = 0;
	this->y = 0;
	this->z = 0;
}
;

ostream& operator<<(ostream& os, const Point& p) {
	os << "(" << p.x << ", " << p.y << ", " << p.z << ")" << endl;
	return os;
}

