//
//  Color.cpp
//  Projet
//
//  Created by Paul VANHAESEBROUCK on 15/05/2015.
//  Copyright (c) 2015 PaulAndBoris. All rights reserved.
//

#include "Color.h"

Color::Color() : R(255), G(255), B(255) {}

Color Color::whiteColor() {
    return Color(255, 255, 255);
}

Color Color::blackColor() {
    return Color(0, 0, 0);
}

Color::Color(unsigned char R, unsigned char G, unsigned char B) : R(R), G(G), B(B) {}


int Color::getR() const {
    return R;
}

int Color::getG() const {
    return G;
}

int Color::getB() const {
    return B;
}


std::ostream& operator<<(std::ostream& os, const Color& c) {
    return os << "Color(" << c.R << ", " << c.G << ", " << c.B << ")" << std::endl;
}


bool Color::operator<(const Color &c) const {
    if (R < c.R)
        return true;
    if (R > c.R)
        return false;
    if (G < c.G)
        return true;
    if (G > c.G)
        return false;
    if (B < c.B)
        return true;
    if (B > c.B)
        return false;
    
    return false;
}