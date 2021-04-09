#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/raytracer.h"
#include "../include/geometry.h"
#include "../include/colors.h"
#include "../include/shape.h"
#include "../include/sdl_tools.h"


Ray createRay(Point3D pos, Vector3D vec ) {

    // Construit le rayon (pos, vec)

    Ray RAY_MAN;

    RAY_MAN.pos = pos;
    RAY_MAN.vec = vec;

    return RAY_MAN;
}

int intersectsSphere(Ray r, Sphere s, Intersection* intersection, float* t) {

    // Test si le rayon intersecte la sphere. Crée l'Intersection si oui.

    Vector3D DISTANCE_TERRE_SOLEIL = createVectorFromPoints(r.pos, s.cent);
    Point3D CA_FAIT_CHBOUM_LA_DEDANS;
    float TOUCHE, COULE;

    float FIRST_ONE = dot(r.vec, r.vec);
    float SECOND_ONE = -2 * dot(r.vec, DISTANCE_TERRE_SOLEIL);
    float LAST_ONE = dot(DISTANCE_TERRE_SOLEIL, DISTANCE_TERRE_SOLEIL) - dot(s.ray, s.ray);

    float DETERMINANT_SOCIAL = SECOND_ONE * SECOND_ONE - 4 * FIRST_ONE * LAST_ONE;


    if (DETERMINANT_SOCIAL < 0) {
        return 0;
    }

    else {
        
        TOUCHE = (- SECOND_ONE + sqrt(DETERMINANT_SOCIAL)) / (2 * FIRST_ONE);
        COULE = (- SECOND_ONE - sqrt(DETERMINANT_SOCIAL)) / (2 * FIRST_ONE);

        if (TOUCHE * COULE < 0.) {
            *t = max(TOUCHE, COULE)
        }

        else if (TOUCHE < 0.) {
            return 0;
        }

        else {
            *t = min(TOUCHE, COULE);
        }

        CA_FAIT_CHBOUM_LA_DEDANS = pointPlusVector(r.pos, mltVector(r.vec, t));
        intersection.pos = CA_FAIT_CHBOUM_LA_DEDANS;
        intersection.col = s.col;
    }

    return 1;

}

Scene createScene() {

    // Construit une scene et l'initialise

    Scene EL_THEATRE;

    EL_THEATRE.compt = 0;

    return EL_THEATRE;
}

void addSphereToScene(Scene* scene, Sphere s) {

    // Rajoute une sphere à la scene

    scene->tab[scene->compt] = s;
    scene->compt ++;
}

int throwRayThroughScene(Ray r, Scene scene, Intersection* intersectionNearest) {

    // Trouve l'intersection la plus proche entre le rayon donné et la scene

    float t;
    float DISANCE = -1;

    Intersection GARO_AUTO;

    for (int k=0; k < scene.compt; k++) {
        
        if (intersectsSphere(r, scene.tab[k], GARO_AUTO, t) && DISANCE > t) {
            intersectionNearest = GARO_AUTO;
            DISANCE = t;
        }
    }

    if (DISANCE = -1) {
        return 0;
    }
    
    return 1;
}


void simpleRaytracing(const Scene* scene, SDL_Surface* framebuffer) {

    // Calcul le rayon R puis envoie le rayon dans la scene

    float x;
    float y;
    float z = -1;

    Point3D ORGIN = createPoint(0, 0, 0);
    Intersection * YOUI;

    for (int k = 0; k < framebuffer->w; k++) {
        for (int i = 0; i < framebuffer->h; i++) {
            
            x = 1 + 2 * (k/framebuffer->w);
            y = -(1 + 2 * (i/framebuffer->h));
            Vector3D VICIEUX = createVector(x, y , z);
            Ray MAGIQUE = createRay(ORGIN, VICIEUX);

            if (throwRayThroughScene(MAGIQUE, scene, YOUI)) {
                
            }
        }
    }
}
