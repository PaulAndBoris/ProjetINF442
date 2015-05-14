/*
 * Light.h

 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */

#include "Point.h"

#ifndef LIGHT_H_
#define LIGHT_H_

class Light{

private :

	Point source;

	//Couleurs optionnelles
	int R;
	int G;
	int B;

public :

	Light(Point source);//Constructeur sans couleur spécifiée -> lumiere blanche
	Light(Point source, int R, int G, int B);//Constructeur avec couleur

};



#endif /* LIGHT_H_ */
