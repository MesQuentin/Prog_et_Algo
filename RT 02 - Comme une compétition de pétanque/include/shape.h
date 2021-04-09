#ifndef SHAPE_H
#define SHAPE_H
#include "geometry.h"
#include "colors.h"

typedef struct Sphere {
    Point3D cent;
    float ray;
    ColorRGB col;
} Sphere;

// Construit la sphere (cent, ray, col)
Sphere createSphere(Point3D cent, float ray, ColorRGB col);

#endif