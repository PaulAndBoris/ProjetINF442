/*
 * Scene.cpp
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */

#include <cmath>

#include "Scene.h"
#include "Object.h"

Scene::Scene(const Color &backgroundColor) :
		objects(), lights(), backgroundColor(backgroundColor) {
}

Scene::Scene(std::vector<Object*> objects, std::vector<Light*> lights,
		const Color &backgroundColor) :
		objects(objects), lights(lights), backgroundColor(backgroundColor) {
	updateAmbiantColor();
}

void Scene::addObject(Object* object) {
	objects.push_back(object);
}
void Scene::addLight(Light* light) {
	lights.push_back(light);
	updateAmbiantColor();
}

std::vector<Light*>::const_iterator Scene::lightsBegin() const {
	return lights.begin();
}

std::vector<Light*>::const_iterator Scene::lightsEnd() const {
	return lights.end();
}

std::vector<Object*>::const_iterator Scene::objectsBegin() const {
    return objects.begin();
}

std::vector<Object*>::const_iterator Scene::objectsEnd() const {
    return objects.end();
}

void Scene::updateAmbiantColor() {

	int red = 0, green = 0, blue = 0;
    
	std::vector<Light*>::const_iterator l;

	for (l = lights.begin(); l != lights.end(); ++l) {

		Color c = (*l)->getColor();

		red   += c.R;
		green += c.G;
		blue  += c.B;
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

bool Scene::firstObjectHitByRay(const Ray &ray, Object* &object,
		Point &point) const {

	bool hitOne = false;
    
	Point P, origin(ray.getPoint()), firstPoint;
	Object* firstObject = nullptr;
	double dist, minDist = INFINITY;
    
    std::vector<Object*>::const_iterator o;

    for (o = objectsBegin(); o != objectsEnd(); ++o) {
        
		if ((*o)->intersection(ray, P)) {
            
			hitOne = true;
			dist = origin.distanceTo(P);

			if (dist < minDist) {
				firstObject = *o;
				minDist = dist;
				firstPoint = P;
			}
		}
	}

	if (hitOne) {
		object = firstObject;
		point = firstPoint;
	}

	return hitOne;
}
