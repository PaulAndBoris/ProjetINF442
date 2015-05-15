/*
 * Vector.h
 *
 *  Created on: 8 mai 2015
 *      Author: Boris
 */
#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

class Point;

class Vector {

private:
	double x;
	double y;
	double z;

public:
	Vector(); //Constructeur par défaut
	Vector(double x, double y, double z); //Constructeur
	Vector (Point a, Point b);//Construit le vecteur ab

	//Accesseurs
	double getX() const;
	double getY() const;
	double getZ() const;

    Vector add(const Vector &vec) const; //Addition avec un vecteur
    Vector substract(const Vector &vec) const; //Soustraction avec un vecteur
	double multiply(const Vector &vec) const; //Produit scalaire (inner product)
	Vector multiply(const double &scalar) const; //Multiplication par un scalaire (outer product)
	double norm() const;//Calcule la norme du vecteur
	Vector cross_product (const Vector& vec ) const; //Produit vectoriel
    Vector normalize() const;
    
    // normal should be a unit vector!
    Vector reflectedBy(const Vector &normal) const;

	void print(); //Affiche le vecteur

	Vector operator+(const Vector &vec) const;
    Vector operator-(const Vector &vec) const;
	double operator*(const Vector &vec) const;
	Vector operator*(const double &scalar) const;//NB : on doit écrire vecteur*scalaire et pas l'inverse
	Vector operator^(const Vector &vec) const; //Operateur produit vectoriel

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
};

#endif /* VECTOR_H_ */
