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

bool Light::operator<(const Light& c) const {
    if (source < c.source)
        return true;
    if (c.source < source)
        return false;
    if (color < c.color)
        return true;
    if (c.color < color)
        return false;
    
    return false;
}