/*
 * Vector.h
 *
 *  Created on: 8 mai 2015
 *      Author: Boris
 */

#ifndef VECTOR_H_
#define VECTOR_H_

class Vector{

private :
	double x;
	double y;
	double z;

public :
	Vector (double x, double y, double z); //Constructeur
 //	~Vector(); //Destructeur : en a-t-on besoin ?

	Vector add(const Vector &vec); //Addition avec un vecteur
	double multiply(const Vector &vec); //Produit scalaire (inner product)
	Vector multiply(const double &scalar); //Multiplication par un scalaire (outer product)

	void print(); //Affiche le vecteur

	Vector operator+(const Vector &vec);
	double operator*(const Vector &vec);
	Vector operator*(const double &scalar);

	friend std::ostream& operator<<(std::ostream& os,const Vector& vec);
};




#endif /* VECTOR_H_ */
