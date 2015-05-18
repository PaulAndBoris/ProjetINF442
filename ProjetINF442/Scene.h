/*
 * Scene.h
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#ifndef SCENE_H_
#define SCENE_H_

#include <set>
#include <vector>
#include "Sphere.h"
#include "Light.h"
#include "Scene.h"

class Scene{

private :

    std::set<Light> lights;
	std::vector<Object*> objects;
    
    Color ambientColor, backgroundColor;
    
    void updateAmbiantColor();

public :

    Scene(const Color &backgroundColor);
    Scene(std::vector<Object*> objects, std::set<Light> lights, const Color &backgroundColor);//Constructeur

    void addObject(Object* object);
    void addLight(Light light);
    
    std::set<Light>::iterator lightsBegin() const;
    std::set<Light>::iterator lightsEnd() const;
    
    Color getAmbiantColor() const;
    Color getBackgroundColor() const;
    
    bool firstObjectHitByRay(const Ray &ray, Object &object, Point &point) const;
};




#endif /* SCENE_H_ */
