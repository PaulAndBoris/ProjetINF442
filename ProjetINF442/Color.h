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
    
public:
    
    unsigned char R, G, B;
    
    static Color whiteColor();
    static Color blackColor();
    
    Color();
    Color(unsigned char R, unsigned char G, unsigned char B);
    
    friend std::ostream& operator<<(std::ostream& os, const Color& c);
    
    bool operator<(const Color &c) const;
    bool operator!=(const Color &color) const;
};

#endif /* defined(__Projet__Color__) */
