//
//  phongReflection.cpp
//  Projet
//
//  Created by Paul VANHAESEBROUCK on 15/05/2015.
//  Copyright (c) 2015 PaulAndBoris. All rights reserved.
//

#include <cmath>

#include "phongReflection.h"


Color phongReflectionColor(const Point& P, const Color &pointColor, const Ray &ray, const Vector &N, const Light &light, double Ks, double Kd, double Ka, double alpha) {
    
    Vector L = Vector(P, light.getSource()).normalize();
    if (L*N < 0) { L = Vector(); }
    Vector V = Vector(P, ray.getPoint()).normalize();
    Vector R = L.reflectedBy(N);
    
    // Définition des coefficients en fonction de la couleur de la surface (expérimental)
    double
    Ka_R = (pointColor.getR() * Ka) / 255.0,
    Ka_G = (pointColor.getG() * Ka) / 255.0,
    Ka_B = (pointColor.getB() * Ka) / 255.0,
    
    Kd_R = (pointColor.getR() * Kd) / 255.0,
    Kd_G = (pointColor.getG() * Kd) / 255.0,
    Kd_B = (pointColor.getB() * Kd) / 255.0,
    
    Ks_R = (pointColor.getR() * Ks) / 255.0,
    Ks_G = (pointColor.getG() * Ks) / 255.0,
    Ks_B = (pointColor.getB() * Ks) / 255.0;
    
    double L_N = L * N, R_V_alpha = pow(R * V, alpha);
    
    double red = Ka_R * light.getAmbientColor().getR() + (Kd_R * L_N + Ks_R * R_V_alpha) * light.getColor().getR(),
    green = Ka_G * light.getAmbientColor().getG() + (Kd_G * L_N + Ks_G * R_V_alpha) * light.getColor().getG(),
    blue = Ka_B * light.getAmbientColor().getB() + (Kd_B * L_N + Ks_B * R_V_alpha) * light.getColor().getB();
    
    return Color((red > 255) ? 255 : red, (green > 255) ? 255 : green, (blue > 255) ? 255 : blue);
}
