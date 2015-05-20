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

Color Color::operator*(const double r) {
	return Color((unsigned char)(this->R*r),
				 (unsigned char)(this->G*r),
				 (unsigned char)(this->B*r));
}

Color Color::operator+(const Color &color){
	return Color(this->R+color.R,this->G+color.G, this->B+color.B);
}
