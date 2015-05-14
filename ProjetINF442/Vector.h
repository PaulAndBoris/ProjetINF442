/*
 * Vector.h
 *
 *  Created on: 8 mai 2015
 *      Author: Boris
 */
#include <iostream>
#include "Point.h"
using namespace std;

#ifndef VECTOR_H_
#define VECTOR_H_

class Vector {

private:
	double x;
	double y;
	double z;

public:
	Vector(); //Constructeur par défaut
	Vector(double x, double y, double z); //Constructeur
	Vector (Point a, Point b);//Construit le vecteur ab
	~Vector(); //Destructeur

	Vector add(const Vector &vec); //Addition avec un vecteur
	double multiply(const Vector &vec); //Produit scalaire (inner product)
	Vector multiply(const double &scalar); //Multiplication par un scalaire (outer product)
	double norm();//Calcule la norme du vecteur
	Vector cross_product (const Vector& vec ); //Produit vectoriel

	void print(); //Affiche le vecteur

	Vector operator+(const Vector &vec);
	double operator*(const Vector &vec);
	Vector operator*(const double &scalar);
	Vector operator^(const Vector &vec); //Operateur produit vectoriel

	friend ostream& operator<<(ostream& os, const Vector& vec);
};

#endif /* VECTOR_H_ */
