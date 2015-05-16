/*
 * Scene.cpp
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#include "Scene.h"
#include <cmath>
#include "Ray.h"



Scene::Scene(const Color &backgroundColor) : spheres(), lights(), backgroundColor(backgroundColor) {}


Scene::Scene(std::set<Sphere> spheres, std::set<Light> lights, const Color &backgroundColor) :
spheres(spheres),
lights(lights),
backgroundColor(backgroundColor)
{
    updateAmbiantColor();
}

void Scene::addSphere(Sphere sphere) {
    spheres.insert(sphere);
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
    
    int n = (int)lights.size();

    ambientColor = Color(red/n, green/n, blue/n);
}

Color Scene::getAmbiantColor() const {
    return ambientColor;
}

Color Scene::getBackgroundColor() const {
    return backgroundColor;
}

bool Scene::firstSphereHitByRay(const Ray &ray, Sphere &sphere, Point &point) const {
    
    bool hitOne = false;
    Point P, origin(ray.getPoint()), firstPoint;
    Sphere firstSphere;
    double dist, minDist = INFINITY;
    
    std::set<Sphere>::iterator s;
    
    for (s = spheres.begin(); s != spheres.end(); ++s) {
        if (s->intersection(ray, P)) {
            hitOne = true;
            
            dist = origin.distanceTo(P);
            
            if (dist < minDist) {
                firstSphere = Sphere(*s);
                minDist = dist;
                firstPoint = P;
            }
        }
    }
    
    if (hitOne) {
        sphere = firstSphere;
        point = firstPoint;
    }
    
    return hitOne;
}