/*
 * Scene.h
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#ifndef SCENE_H_
#define SCENE_H_

#include<set>
#include "Sphere.h"


class Scene{

private :

	std::set<Sphere> spheres;

public :

	Scene(std::set<Sphere> spheres);//Constructeur

};




#endif /* SCENE_H_ */
