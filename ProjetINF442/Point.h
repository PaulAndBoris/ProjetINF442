/*
 * Point.h
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#include<iostream>
using namespace std;

#ifndef POINT_H_
#define POINT_H_

class Point {

private:

	double x;
	double y;
	double z;

public:
	Point();//Constructeur par défaut
	Point(double x, double y, double z); //Constructeur
	friend ostream& operator<<(ostream& os, const Point& p);

	//Accesseurs :
	double getX();
	double getY();
	double getZ();

};
#endif /* POINT_H_ */
