/*
 * Vector.cpp
 *
 *  Created on: 8 mai 2015
 *      Author: Boris
 */
#include <iostream>
#include "Vector.h"

using namespace std;

Vector::Vector(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;

	//friend std::ostream& operator<<(std::ostream& os,const Vector& vec);
}
;

Vector Vector::add(const Vector &vec) {
	return Vector(this->x + vec.x, this->y + vec.y, this->z + vec.z);
}

Vector Vector::multiply(const double& scalar) {
	return Vector(scalar * this->x, scalar * this->y, scalar * this->z);
}

double Vector::multiply(const Vector& vec) {
	return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}

void Vector::print(){
	std::cout<<"x : "<<this->x<<" y : "<<this->y<<"z : "<<this->z<<std::endl;
}

//Surcharge de l'opérateur +
Vector Vector::operator+(const Vector &vec){
	return this->add(vec);
}

//Surcharges de l'opérateur *
double Vector::operator*(const Vector &vec){
	return this->multiply(vec);
}

Vector Vector::operator*(const double &scalar){
	return this->multiply(scalar);
}

std::ostream& operator<<(std::ostream& os,const Vector& vec){
	os<<"("<<vec.x<<", "<<vec.y<<", "<<vec.z<<")"<<std::endl;
	return os;
}
