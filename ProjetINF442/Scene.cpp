/*
 * Scene.cpp
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#include "Scene.h"
#include "Object.h"
#include <cmath>
#include <vector>
#include "Ray.h"

Scene::Scene(const Color &backgroundColor) :
		objects(), lights(), backgroundColor(backgroundColor) {
}

Scene::Scene(std::vector<Object*> objects, std::set<Light> lights,
		const Color &backgroundColor) :
		objects(objects), lights(lights), backgroundColor(backgroundColor) {
	updateAmbiantColor();
}

void Scene::addObject(Object* object) {
	objects.push_back(object);
}
void Scene::addLight(Light light) {
	lights.insert(light);
	updateAmbiantColor();
}

std::set<Light>::iterator Scene::lightsBegin() const {
	return lights.begin();
}

std::set<Light>::iterator Scene::lightsEnd() const {
	return lights.end();
}

void Scene::updateAmbiantColor() {

	int red = 0, green = 0, blue = 0;
	std::set<Light>::iterator l;

	for (l = lights.begin(); l != lights.end(); ++l) {

		Color c = l->getColor();

		red += c.R;
		green += c.G;
		blue += c.B;
	}

	int n = (int) lights.size();

	ambientColor = Color(red / n, green / n, blue / n);
}

Color Scene::getAmbiantColor() const {
	return ambientColor;
}

Color Scene::getBackgroundColor() const {
	return backgroundColor;
}

bool Scene::firstObjectHitByRay(const Ray &ray, Object &object,
		Point &point) const {

	bool hitOne = false;
	Point P, origin(ray.getPoint()), firstPoint;
	Object* firstObject;
	double dist, minDist = INFINITY;

	for (int i = 0; i < objects.size(); ++i) {
		if (objects[i]->intersection(ray, P)) {
			hitOne = true;

			dist = origin.distanceTo(P);

			if (dist < minDist) {
				firstObject = (objects[i]);
				minDist = dist;
				firstPoint = P;
			}
		}
	}

	if (hitOne) {
		object = *firstObject;
		point = firstPoint;
	}

	return hitOne;
}
