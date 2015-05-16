#include <iostream>
#include <CImg.h>

#include "Camera.h"
#include "Sphere.h"

using namespace cimg_library;
using namespace std;

int main() {

    int cols = 640, rows = 480;
    Color pixelColor;
    double Ks = 0.3, Kd = 0.7, Ka = 0.4, alpha = 20;
    
    Point eye(-10, 0, 2),
    sphereCenter(0, -0.5, 0),
    sphereCenter2(3.5, 1, 0.5),
    lightCenter(-1, -1.8, -0.5),
    lightCenter2(0, 0, 50);
    
    Light light(lightCenter), light2(lightCenter2, Color(200, 200, 0));
    Sphere sphere(sphereCenter, 0.7, Color(240, 50, 50), Ks, Kd, Ka, alpha),
    sphere2(sphereCenter2, 2.6, Color(50, 50, 255), Ks, Kd, Ka, alpha);
    
    Scene scene(Color::blackColor());
    scene.addLight(light);
    scene.addLight(light2);
    scene.addSphere(sphere);
    scene.addSphere(sphere2);
    
    
    Point barycentre = sphereCenter2;// + Vector(sphereCenter2, sphereCenter) * 0.3;
    Point target = eye + Vector(eye, barycentre).normalize() * 2;
    Vector dir(eye, target);
    Vector up = (dir^Vector(0,0,1))^dir;
    
    Camera cam(eye, target, up, 4.0/3, 1, cols, rows, scene);
    
    CImg<unsigned char> image(cols, rows, 1, 3, 255);
    
    for (int x = 0; x < cols; x++) {
        for (int y = 0; y < rows; y++) {
            
            pixelColor = cam.colorForCoordinates(x, y);
            
            *image.data(x, rows - y - 1, 0, 0) =  pixelColor.R;
            *image.data(x, rows - y - 1, 0, 1) =  pixelColor.G;
            *image.data(x, rows - y - 1, 0, 2) =  pixelColor.B;
        }
    }
    
    CImgDisplay disp(image, "resultat");
    
    while (!disp.is_closed() )
        disp.wait();
    
	return 0;
}
