/*
 * Scene.h
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#ifndef SCENE_H_
#define SCENE_H_

#include <set>
#include "Sphere.h"
#include "Light.h"


class Scene{

private :

    std::set<Light> lights;
	std::set<Sphere> spheres;
    
    Color ambientColor, backgroundColor;
    
    void updateAmbiantColor();

public :

    Scene(const Color &backgroundColor);
    Scene(std::set<Sphere> spheres, std::set<Light> lights, const Color &backgroundColor);//Constructeur

    void addSphere(Sphere sphere);
    void addLight(Light light);
    
    std::set<Light>::iterator lightsBegin() const;
    std::set<Light>::iterator lightsEnd() const;
    
    Color getAmbiantColor() const;
    Color getBackgroundColor() const;
    
    bool firstSphereHitByRay(const Ray &ray, Sphere &sphere, Point &point) const;
};




#endif /* SCENE_H_ */
