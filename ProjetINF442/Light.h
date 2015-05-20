/*
 * Light.h

 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */
#ifndef LIGHT_H_
#define LIGHT_H_

#include "Color.h"
#include "Ray.h"

class Light{

private :

	Point source;

    Color color;

public :

	Light(const Point &source);//Constructeur sans couleur spécifiée -> lumiere blanche
	Light(const Point &source, const Color &color);//Constructeur avec couleur
    
    Point getSource() const;
    Color getColor() const;

};



#endif /* LIGHT_H_ */
