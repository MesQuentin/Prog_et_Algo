#ifndef RAYTRACING_H
#define RAYTRACING_H
#include "geometry.h"
#include "colors.h"
#include "shape.h"
#include "sdl_tools.h"

typedef struct Ray {
    Point3D pos;
    Vector3D vec;
} Ray;

typedef struct Intersection {
    Point3D pos;
    ColorRGB col;
} Intersection;

typedef struct Scene {
    int compt;
    Sphere tab[80];
} Scene;

// Construit le rayon (pos, vec) 
Ray createRay(Point3D pos, Vector3D pos);

// Test si le rayon intersecte une sphère
int intersectsSphere(Ray r, Sphere s,
    Intersection* intersection, float* t);

// Construit une scene et l'initialise
Scene createScene();

// Rajoute une sphere à la scene
void addSphereToScene(Scene* scene, Sphere s);

// Trouve l'intersection la plus proche entre le rayon donné et la scene
int throwRayThroughScene(Ray r, Scene scene, 
    Intersection* intersectionNearest);


// Calcul le rayon R puis envoie le rayon dans la scene
void simpleRaytracing(const Scene* scene, SDL_Surface* framebuffer);

#endif