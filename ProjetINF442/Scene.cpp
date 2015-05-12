/*
 * Scene.cpp
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#include "Scene.h"

using namespace std;

Scene::Scene() {
	this->spheres = set<Sphere>();
}
;

Scene::Scene(set<Sphere> spheres) {
	this->spheres = spheres;
}
;

Scene::~Scene() {
	delete[] &this->spheres;
}
;
