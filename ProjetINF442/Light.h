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

	Light(Point source);//Constructeur sans couleur spécifiée -> lumiere blanche et pas de lumière ambiante
	Light(Point source, int R, int G, int B, int ambR = 0, int ambG = 0, int ambB = 0);//Constructeur avec couleur
    
    Point getSource() const;
    Color getColor() const;
    Color getAmbientColor() const;

};



#endif /* LIGHT_H_ */
