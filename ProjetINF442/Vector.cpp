/*
 * Vector.cpp
 *
 *  Created on: 8 mai 2015
 *      Author: Boris
 */
#include <cmath>

#include "Vector.h"
#include "Point.h"

Vector::Vector(double x, double y, double z) :
		x(x), y(y), z(z) {
}

Vector::Vector() :
		x(0), y(0), z(0) {
}

Vector::Vector(Point a, Point b) :
		x(b.getX() - a.getX()), y(b.getY() - a.getY()), z(b.getZ() - a.getZ()) {
}

double Vector::getX() const {
	return (this->x);
}

double Vector::getY() const {
	return (this->y);
}

double Vector::getZ() const {
	return (this->z);
}

Vector Vector::add(const Vector &vec) const {
	return Vector(this->x + vec.x, this->y + vec.y, this->z + vec.z);
}

Vector Vector::substract(const Vector &vec) const {
	return Vector(this->x - vec.x, this->y - vec.y, this->z - vec.z);
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
	double x = this->y * vec.z - this->z * vec.y;
	double y = this->z * vec.x - this->x * vec.z;
	double z = this->x * vec.y - this->y * vec.x;

	return Vector(x, y, z);
}

Vector Vector::normalize() const {
	double n = norm();
	return Vector(x / n, y / n, z / n);
}

Vector Vector::reflectedBy(const Vector &normal) const {
	return normal * 2 * (*this * normal) - (*this);
}

void Vector::print() {
	std::cout << "x : " << this->x << " y : " << this->y << " z : " << this->z
			<< std::endl;
}

//Surcharge de l'opérateur +
Vector Vector::operator+(const Vector &vec) const {
	return this->add(vec);
}

//Surcharge de l'opérateur -
Vector Vector::operator-(const Vector &vec) const {
	return this->substract(vec);
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

//bool Vector::operator!=(const Vector &vector) const {
//
//	return ((this->x - vector.x) * (this->y - vector.y) * (this->z - vector.z)
//			!= 0);
//}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
	os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")" << std::endl;
	return os;
}
