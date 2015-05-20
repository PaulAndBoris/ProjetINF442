/*
 * Scene.h
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#ifndef SCENE_H_
#define SCENE_H_

#include <vector>

#include "Light.h"
#include "Color.h"

class Object;

class Scene{

private :

    std::vector<Light*> lights;
	std::vector<Object*> objects;
    
    Color ambientColor, backgroundColor;
    
    void updateAmbiantColor();

public :

    Scene(const Color &backgroundColor);
    Scene(std::vector<Object*> objects, std::vector<Light*> lights, const Color &backgroundColor);//Constructeur

    void addObject(Object* object);
    void addLight(Light* light);
    
    std::vector<Light*>::const_iterator lightsBegin() const;
    std::vector<Light*>::const_iterator lightsEnd() const;
    
    std::vector<Object*>::const_iterator objectsBegin() const;
    std::vector<Object*>::const_iterator objectsEnd() const;
    
    Color getAmbiantColor() const;
    Color getBackgroundColor() const;
    
    bool firstObjectHitByRay(const Ray &ray, Object* &object, Point &point) const;
};




#endif /* SCENE_H_ */
