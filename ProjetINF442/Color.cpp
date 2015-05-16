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


std::ostream& operator<<(std::ostream& os, const Color& c) {
    return os << "Color(" << (int)c.R << ", " << (int)c.G << ", " << (int)c.B << ")" << std::endl;
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

bool Color::operator!=(const Color &color) const {
    if (R != color.R)
        return true;
    if (G != color.G)
        return true;
    if (B != color.B)
        return true;
    
    return false;
}