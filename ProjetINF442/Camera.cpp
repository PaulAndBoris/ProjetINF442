/*
 * Camera.cpp
 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */
#include "Camera.h"

Camera::Camera(const Point &eye, const Point &target, const Vector &up, double width, double height, int cols, int rows, const Scene &scene) :

eye(eye),
target(target),

up(up.normalize()),
right((Vector(eye, target)^up).normalize()),

width(width),
height(height),

cols(cols),
rows(rows),

scene(scene)
{}


Ray Camera::rayForCoordinates(int x, int y) const {
    
    x -= cols/2;
    y -= rows/2;
    
    Point screenPoint = target
                        + up    * (((double)y) / rows) * height
                        + right * (((double)x) / cols) * width;
    
    return Ray(eye, Vector(eye, screenPoint));
}


Color Camera::colorForRay(const Ray &ray) const {
    
    Sphere sphere;
    Point point;
    
    if (scene.firstSphereHitByRay(ray, sphere, point))
        return sphere.phongReflectionColor(ray, point, scene);
    else
        return scene.getBackgroundColor();
}

Color Camera::colorForCoordinates(int x, int y) const {
    
    return colorForRay(rayForCoordinates(x, y));
}