#include <iostream>
#include <fstream>
#include "mpi.h"
#include "CImg.h"

#include "Camera.h"
#include "Scene.h"
#include "Sphere.h"
#include "Plan.h"

using namespace cimg_library;
using namespace std;

int main(int argc, char * argv[]) {

//	int cols = 960, rows = 720;
//	Color pixelColor;
//	double Ks = 0.3, Kd = 0.7, Ka = 0.4, alpha = 20, r = 0.2;
//
//	int reflections = 5;
//
//	Point eye(-10, 0, 2), sphereCenter(-0.5, -0.5, 0), sphereCenter2(3.5, 0.5, 0.5),
//			sphereCenter3(2, -3.5, 0), lightCenter(-2, -1.8, -0.5),
//			lightCenter2(0, 0, 50);
//
//	Light light(lightCenter), light2(lightCenter2, Color(200, 0, 200));
//	Sphere sphere(sphereCenter, 0.7, Color(240, 50, 50), Ks, Kd, Ka, alpha, r),
//			sphere2(sphereCenter2, 2.6, Color(50, 50, 255), Ks, Kd, Ka, alpha,
//					r), sphere3(sphereCenter3, 1, Color(50, 240, 50), Ks, Kd,
//					Ka, alpha, r);
//    Plan plan(Point(0, 0, -3), Vector(0,0,1), Color::whiteColor(),  Ks,  Kd,  Ka,  alpha,  r);
//
//	Scene scene(Color::blackColor());
//	scene.addLight(light);
//	scene.addLight(light2);
//	scene.addObject(&sphere);
//	scene.addObject(&sphere2);
//	scene.addObject(&sphere3);
//    scene.addObject(&plan);
//
//	Point barycentre = sphereCenter2; // + Vector(sphereCenter2, sphereCenter) * 0.3;
//	Point target = eye + Vector(eye, barycentre).normalize() * 2;
//
//	Camera cam(eye, target, 2, 1.5 , cols, rows, scene, reflections);
    
    
    int myrank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    
    if (argc != 2) {
        if (myrank == 0)
            cout << "Usage: mpirun projet.app [input file]" << endl;
        
        MPI_Finalize();
        return 0;
    }
    
    // ====================
    //  PARSING INPUT FILE
    // ====================
    
    ifstream ifs (argv[1], ifstream::in);
    
    //    Point point;
    int count, rows, cols, reflections, R, G, B;
    float x, y, z, dx, dy, dz, radius, width, height, Ks, Kd, Ka, alpha, r;
//    unsigned char R, G, B;
    
    // SCENE // Format : backgroundColor
    
    ifs >> R >> G >> B;
    Scene scene(Color(R, G, B));
    
    
    // CAMERA // Format : "eye" "target" width height cols rows reflections
    
    ifs >> x >> y >> z;
    Point eye(x, y, z);
    ifs >> x >> y >> z;
    Point target(x, y, z);
    ifs >> width >> height >> cols >> rows >> reflections;
    Camera cam(eye, target, width, height, cols, rows, &scene, reflections);
    
    
    // LIGHTS // Format : numberOfLights \n point color \n ...
    
    ifs >> count;
    for (int i = 0; i < count; i++) {
        ifs >> x >> y >> z >> R >> G >> B;
        scene.addLight(new Light(Point(x, y, z), Color(R, G, B)));
    }
    
    
    // SPHERES // Format : numberOfSpheres \n point radius color Ks Kd Ka alpha r \n ...
    
    ifs >> count;
    for (int i = 0; i < count; i++) {
        ifs >> x >> y >> z >> radius >> R >> G >> B >> Ks >> Kd >> Ka >> alpha >> r;
        scene.addObject(new Sphere(Point(x, y, z), radius, Color(R, G, B), Ks, Kd, Ka, alpha, r));
    }
    
    
    // PLANS // Format : numberOfPlans \n point normal color Ks Kd Ka alpha r \n ...
    
    ifs >> count;
    for (int i = 0; i < count; i++) {
        ifs >> x >> y >> z >> dx >> dy >> dz >> R >> G >> B >> Ks >> Kd >> Ka >> alpha >> r;
        scene.addObject(new Plan(Point(x, y, z), Vector(dx, dy, dz), Color(R, G, B), Ks, Kd, Ka, alpha, r));
    }
    
    ifs.close();
    
    
    // Début des calculs
    
    Color pixelColor;
    
    int begin = myrank * cols / size, end = (myrank + 1) * cols / size, index = 0;
    count = (end - begin) * rows * 3;
    unsigned char data[count];
    
    cout << "Node " << myrank << " computing from " << begin << " to " << end << endl;
    
    for (int x = begin; x < end; x++) {
        for (int y = 0; y < rows; y++) {
            
            pixelColor = cam.colorForCoordinates(x, y);
            
            data[index] = pixelColor.R;
            data[index+1] = pixelColor.G;
            data[index+2] = pixelColor.B;
            
            index += 3;
        }
    }
    
    
    if (myrank != 0) {
        MPI_Send(data, count, MPI_UNSIGNED_CHAR, 0, myrank, MPI_COMM_WORLD);
    } else {
        
        CImg<unsigned char> image(cols, rows, 1, 3, 255);
        
        unsigned char *buffer;
        
        for (int rank = 0; rank < size; rank++) {
            
            if (rank != 0) {
                
                begin = rank * cols / size; end = (rank + 1) * cols / size;
                count = (end - begin) * rows * 3;
            
                buffer = new unsigned char[count];
            
                MPI_Recv(buffer, count, MPI_UNSIGNED_CHAR, rank, rank, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            }
            else
                buffer = data;
            
            index = 0;
            
            for (int x = begin; x < end; x++) {
                for (int y = 0; y < rows; y++) {
                    
                    *image.data(x, rows - y - 1, 0, 0) = buffer[index];
                    *image.data(x, rows - y - 1, 0, 1) = buffer[index+1];
                    *image.data(x, rows - y - 1, 0, 2) = buffer[index+2];
                    
                    index += 3;
                }
            }
            
            if (myrank != 0)
                delete[] buffer;
            
        }
        
        CImgDisplay disp(image, "resultat");
        
        while (!disp.is_closed())
            disp.wait();
        
    }
    
    MPI_Finalize();

	return 0;
}
