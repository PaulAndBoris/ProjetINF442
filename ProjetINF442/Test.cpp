#include <iostream>
#include "Vector.h"
#include "Ray.h"
#include "Sphere.h"
#include "Intersection.h"

using namespace std;

int main() {

	Vector vec1 = Vector(1, 2, 0);
	Point p = Point(0, 0, 0);
	Ray ray = Ray(p, vec1);

	Point c = Point(4, 4, 0);
	Sphere sphere = Sphere(c, 2, 0, 0, 0);

	Point i = Point();

	cout << intersection(ray, sphere, i) << endl;

	cout << i << endl;

	return 0;
}
