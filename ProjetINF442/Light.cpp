/*
 * Light.cpp
 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */
#include "Light.h"

// Lumière blanche
Light::Light(const Point &source) :

source(source),
color(Color::whiteColor())
{}


Light::Light(const Point &source, const Color &color) :

source(source),
color(color)
{}


Point Light::getSource() const {
    return source;
}

Color Light::getColor() const {
    return color;
}

