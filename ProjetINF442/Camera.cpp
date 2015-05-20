/*
 * Camera.cpp
 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */
#include "Camera.h"
#include "Object.h"

Camera::Camera(const Point &eye, const Point &target,
		double width, double height, int cols, int rows, Scene* scene,
		const int reflections) :

		eye(eye), target(target),

		width(width), height(height),

		cols(cols), rows(rows),

		reflections(reflections),

		scene(scene) {
            
            Vector dir(eye, target);
            
            up = ((dir ^ Vector(0, 0, 1)) ^ dir).normalize();
            right =  (dir ^ up).normalize();
}

Ray Camera::rayForCoordinates(int x, int y) const {

	x -= cols / 2;
	y -= rows / 2;

	Point screenPoint = target + up * (((double) y) / rows) * height
			+ right * (((double) x) / cols) * width;

	return Ray(eye, Vector(eye, screenPoint));
}

Color Camera::colorForRay(const Ray &ray, int count) const {

	Object* object;
//	Object* rec_object;
	Point point, rec_point;

	if (scene->firstObjectHitByRay(ray, object, point)) {
		Ray rec_ray = Ray(point,
				ray.getDirection().reflectedBy(object->normalAtPoint(point))
						* (-1));
		if (count > 0)
//				&& scene->firstObjectHitByRay(rec_ray, rec_object, rec_point))
			return object->phongReflectionColor(ray, point, scene)
					* (1 - object->getR())
					+ colorForRay(rec_ray, count - 1) * object->getR();
		else
			return object->phongReflectionColor(ray, point, scene);
	} else
		return scene->getBackgroundColor();
}

Color Camera::colorForCoordinates(int x, int y) const {

	return colorForRay(rayForCoordinates(x, y), reflections);
}
