/*
 * Scene.h
 *
 *  Created on: 12 mai 2015
 *      Author: Boris
 */
#include<set>
#include "Sphere.h"

#ifndef SCENE_H_
#define SCENE_H_

class Scene{

private :

	std::set<Sphere> spheres;

public :

	Scene();//Constructeur par défaut
	Scene(std::set<Sphere> spheres);//Constructeur

};




#endif /* SCENE_H_ */
