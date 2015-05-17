/*
 * Camera.cpp
 *
 *  Created on: 14 mai 2015
 *      Author: Boris
 */
#include "Camera.h"

Camera::Camera(const Point &eye, const Point &target, const Vector &up,
		double width, double height, int cols, int rows, const Scene &scene,
		const int reflections) :

		eye(eye), target(target),

		up(up.normalize()), right((Vector(eye, target) ^ up).normalize()),

		width(width), height(height),

		cols(cols), rows(rows),

		reflections(reflections),

		scene(scene) {
}

Ray Camera::rayForCoordinates(int x, int y) const {

	x -= cols / 2;
	y -= rows / 2;

	Point screenPoint = target + up * (((double) y) / rows) * height
			+ right * (((double) x) / cols) * width;

	return Ray(eye, Vector(eye, screenPoint));
}

Color Camera::colorForRay(const Ray &ray, int count) const {

	Sphere sphere, rec_sphere;
	Point point, rec_point;
	bool hitByRay;

	if (scene.firstSphereHitByRay(ray, sphere, point)) {
		Ray rec_ray = Ray(point,
				ray.getDirection().reflectedBy(sphere.normalAtPoint(point))
						* (-1));
		Color color = sphere.phongReflectionColor(ray, point, scene, hitByRay);
		if (count > 0
				&& scene.firstSphereHitByRay(rec_ray, rec_sphere, rec_point)
				&& hitByRay)
			return color * (1 - sphere.r)
					+ colorForRay(rec_ray, count - 1) * sphere.r;
		else
			return color;
	} else
		return scene.getBackgroundColor();
}

//C'est probablement ici qu'il faut changer qqchose... créer récursivement le rayon réfléchi !
Color Camera::colorForCoordinates(int x, int y) const {

	return colorForRay(rayForCoordinates(x, y), reflections);
}
