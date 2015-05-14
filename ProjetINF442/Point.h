/*
 * Point.h
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#include<iostream>

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
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    bool operator<(const Point &point) const;
	//Accesseurs :
	double getX() const;
	double getY() const;
	double getZ() const;

};
#endif /* POINT_H_ */
