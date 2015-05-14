/*
 * Vector.cpp
 *
 *  Created on: 8 mai 2015
 *      Author: Boris
 */
#include <cmath>
#include <iostream>
#include "Vector.h"

using namespace std;

Vector::Vector(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;

}
;

Vector::Vector(){
	this->x = 0;
	this->y = 0;
	this->z = 0;
};

Vector::Vector(Point a, Point b){
	this->x = b.getX()-a.getX();
	this->y = b.getY()-a.getY();
	this->z = b.getZ()-a.getZ();
};


double Vector::getX() const{
	return (this->x);
}

double Vector::getY() const{
	return (this->y);
}

double Vector::getZ() const{
	return (this->z);
}

Vector Vector::add(const Vector &vec) const {
	return Vector(this->x + vec.x, this->y + vec.y, this->z + vec.z);
}

Vector Vector::multiply(const double& scalar) const {
	return Vector(scalar * this->x, scalar * this->y, scalar * this->z);
}

double Vector::multiply(const Vector& vec) const {
	return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}

double Vector::norm() const {
	return sqrt(this->multiply(*this));
}

Vector Vector::cross_product(const Vector&vec) const {
	double x = this->y*vec.z - this->z*vec.y;
	double y = this->z*vec.x - this->x*vec.z;
	double z = this->x*vec.y - this->y*vec.x;

	return Vector(x,y,z);
}
void Vector::print() {
	std::cout << "x : " << this->x << " y : " << this->y << "z : " << this->z
			<< std::endl;
}

//Surcharge de l'opérateur +
Vector Vector::operator+(const Vector &vec) const {
	return this->add(vec);
}

//Surcharges de l'opérateur *
double Vector::operator*(const Vector &vec) const {
	return this->multiply(vec);
}

Vector Vector::operator*(const double &scalar) const {
	return this->multiply(scalar);
}

Vector Vector::operator^(const Vector& vec) const {
	return this->cross_product(vec);
}

ostream& operator<<(ostream& os, const Vector& vec) {
	os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")" << std::endl;
	return os;
}
