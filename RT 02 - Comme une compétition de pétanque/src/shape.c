#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/shape.h"
#include "../include/geometry.h"
#include "../include/colors.h"


Sphere createSphere(Point3D cent, float ray, ColorRGB col) {

    // Construit la sphere (cent, ray, col)

    Sphere NO_SPHERE_ATU;

    NO_SPHERE_ATU.cent = cent;
    NO_SPHERE_ATU.ray = ray;
    NO_SPHERE_ATU.col = col;

    return NO_SPHERE_ATU;
}