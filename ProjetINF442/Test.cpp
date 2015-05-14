#include <iostream>
#include "Vector.h"
#include "Ray.h"
#include "Sphere.h"
#include "Intersection.h"

using namespace std;

int main() {

	Vector vec1 = Vector(1, 2, 3);
	Vector vec2 = Vector(2, 3, 4);
	Vector vec3 = vec1.add(vec2);

	double product = vec1 * vec2;
	std::cout << vec3;
	cout << product << endl;
	return 0;
}
