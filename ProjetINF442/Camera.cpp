/*
 * Camera.cpp
 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */
#include "Camera.h"

Camera::Camera(Point eye, Point target, Vector up, double width, double height, int cols, int rows) :

eye(eye),
target(target),

up(up.normalize()),
right((Vector(eye, target)^up).normalize()),

width(width),
height(height),

cols(cols),
rows(rows)
{}


Ray Camera::rayForCoordinates(int x, int y) const {
    
    x -= cols/2;
    y -= rows/2;
    
    Point screenPoint = target
                        + up    * (((double)y) / rows) * height
                        + right * (((double)x) / cols) * width;
    
    return Ray(eye, Vector(eye, screenPoint));
}
