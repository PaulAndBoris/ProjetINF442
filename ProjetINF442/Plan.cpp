/*
 * Plan.cpp
 *
 *  Created on: 18 mai 2015
 *      Author: Boris
 */

#include "Plan.h"
#include "Ray.h"


Plan::Plan(const Point &point, Vector normale, const Color &color, double Ks,
           double Kd, double Ka, double alpha, double r) :
point(point), normale(normale) {
    
    setColor(color, Ks, Kd, Ka, alpha, r);
}


Vector Plan::normalAtPoint(const Point &point) const {
	return normale;
}

bool Plan::intersection(const Ray& ray, Point& intersection_point) const {

	Vector direction = ray.getDirection();
	Vector N(normale);
	Point origine_ray = ray.getPoint();
	Point origine_plan = point;

	Vector toPlan = Vector(origine_ray, origine_plan);
    
    double z =  - (N * toPlan), dz = - (N * direction);

	if (z > 0 && dz > 0) {
		
        intersection_point = origine_ray + direction * (z / dz);
        return true;
        
	}
//    else if (z == 0) { NE PAS REMETTRE CA FOUT LA MERDE!
//        
//		intersection_point = origine_ray;
//		return true;
//	}

	return false;
}


//Color Plan::phongReflectionColor(const Ray &ray, const Point &P, const Scene &scene) const {
//
//    Object* tempObject;
//    Point tempPoint;
//    double L_N, R_V_alpha;
//
//    Vector N = normalAtPoint(P), L, R;
//    Vector V = Vector(P, ray.getPoint()).normalize();
//
//    Color ambiant = scene.getAmbiantColor(), lightColor;
//
//    double red = Ka[0] * ambiant.R,
//    green = Ka[1] * ambiant.G,
//    blue = Ka[2] * ambiant.B;
////    std::cout << "Ka = " << Ka[0] << " Kd = " << Kd[0] << " Ks = " << Ks[0] << std::endl;
//
//    std::set<Light>::iterator l;
//
//    for (l = scene.lightsBegin(); l != scene.lightsEnd(); ++l) {
//
//        L = Vector(P, l->getSource()).normalize();
//        if (L * N < 0) continue;
//        scene.firstObjectHitByRay(Ray(l->getSource(), L * (-1)), tempObject, tempPoint);
//        if (tempObject != this) continue;
//
//        lightColor = l->getColor();
//        R = L.reflectedBy(N);
//
//        L_N = L * N;
//        R_V_alpha = pow(R * V, alpha);
//
//        red += lightColor.R * (Kd[0] * L_N + Ks[0] * R_V_alpha);
//        green += lightColor.G * (Kd[1] * L_N + Ks[1] * R_V_alpha);
//        blue += lightColor.B * (Kd[2] * L_N + Ks[2] * R_V_alpha);
//    }
//
//    return Color((red   > 255) ? 255 : red,
//                 (green > 255) ? 255 : green,
//                 (blue  > 255) ? 255 : blue);
//}
//
//
//bool Plan::operator!=(const Plan &plan) const {
//    if (point != plan.point)
//        return true;
//    if (normale != plan.normale)
//        return true;
//    if (color != plan.color)
//        return true;
//
//    for (int i = 0; i < 3; i++) {
//        if (Ks[i] != plan.Ks[i]) return true;
//        if (Kd[i] != plan.Kd[i]) return true;
//        if (Ka[i] != plan.Ka[i]) return true;
//    }
//
//    if (alpha != plan.alpha)
//        return true;
//
//    return false;
//}
