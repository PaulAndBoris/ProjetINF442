#include <iostream>
#include <CImg.h>

#include "phongReflection.h"
#include "Intersection.h"
#include "Camera.h"
#include "Sphere.h"

using namespace cimg_library;
using namespace std;

int main() {

    int cols = 640, rows = 480;
    int R = 100, G = 40, B = 150;
    double Ks = 0.3, Kd = 0.7, Ka = 0.3, alpha = 20;
    
    Point eye(-0.5, 0, 0), sphereCenter(2, 0, 0), lightCenter(0.5, 1, -0.3);
    Light light(lightCenter, 255, 255, 255, 255, 255, 255);
    Sphere sphere(sphereCenter, 0.9, R, G, B, Ks, Kd, Ka, alpha);
    Camera cam(eye, Point(), Vector(0,0,1) , 4.0/3, 1, cols, rows);
    
    CImg<unsigned char> image(cols, rows, 1, 3, 255);
    
    for (int x = 0; x < cols; x++) {
        for (int y = 0; y < rows; y++) {
            
            Ray ray(cam.rayForCoordinates(x,y));
            Point I;
            
            if (intersection(ray, sphere, I)) {
                Color color(phongReflectionColor(I, sphere.getColor(), ray, sphere.normalAtPoint(I), light, Ks, Kd, Ka, alpha));
                
                *image.data(x, y, 0, 0) =  color.getR();
                *image.data(x, y, 0, 1) =  color.getG();
                *image.data(x, y, 0, 2) =  color.getB();
            }
        }
    }
    
    CImgDisplay disp(image, "resultat");
    
    while (!disp.is_closed() )
        disp.wait();
    
	return 0;
}
