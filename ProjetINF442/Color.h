//
//  Color.h
//  Projet
//
//  Created by Paul VANHAESEBROUCK on 15/05/2015.
//  Copyright (c) 2015 PaulAndBoris. All rights reserved.
//

#ifndef __Projet__Color__
#define __Projet__Color__

#include <iostream>

class Color {
    unsigned char R, G, B;
    
public:
    
    static Color whiteColor();
    static Color blackColor();
    
    Color();
    Color(unsigned char R, unsigned char G, unsigned char B);
    
    int getR() const;
    int getG() const;
    int getB() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Color& c);
    
    bool operator<(const Color &c) const;
};

#endif /* defined(__Projet__Color__) */
