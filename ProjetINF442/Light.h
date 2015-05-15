/*
 * Light.h

 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */
#ifndef LIGHT_H_
#define LIGHT_H_

#include "Point.h"
#include "Color.h"

class Light{

private :

	Point source;

	//Couleurs optionnelles
    Color color, ambientColor;

public :

	Light(Point source);//Constructeur sans couleur spécifiée -> lumiere blanche
	Light(Point source, int R, int G, int B, int ambR = 255, int ambG = 255, int ambB = 255);//Constructeur avec couleur
    
    Point getSource() const;
    Color getColor() const;
    Color getAmbientColor() const;

};



#endif /* LIGHT_H_ */
