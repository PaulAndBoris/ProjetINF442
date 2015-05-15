/*
 * Light.cpp
 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */
#include "Light.h"

// Lumière blanche
Light::Light(Point source) :

source(source),
color(Color::whiteColor()),
ambientColor(Color::whiteColor())
{}


Light::Light(Point source, int R, int G, int B, int ambR, int ambG, int ambB) :

source(source),
color(R, G, B),
ambientColor(ambR, ambG, ambB)
{}


Point Light::getSource() const {
    return source;
}

Color Light::getColor() const {
    return color;
}

Color Light::getAmbientColor() const {
    return ambientColor;
}

