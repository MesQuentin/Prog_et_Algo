#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/geometry.h"

Point3D createPoint(float x, float y, float z){
    
    // Construit le point (x, y, z)

    Point3D UN_POINT_C_EST_TOUT;

    UN_POINT_C_EST_TOUT.x=x;
    UN_POINT_C_EST_TOUT.y=y;
    UN_POINT_C_EST_TOUT.z=z;

    return UN_POINT_C_EST_TOUT;
}


Vector3D createVector(float x, float y, float z) {

    // Construit le vecteur (x, y, z)

    Vector3D VICTOR_LE_VECTEUR;

    VICTOR_LE_VECTEUR.x=x;
    VICTOR_LE_VECTEUR.y=y;
    VICTOR_LE_VECTEUR.z=z;

    return VICTOR_LE_VECTEUR;
}

Vector3D createVectorFromPoints(Point3D p1, Point3D p2) {

    // Construit le vecteur reliant les points P1 et P2

    Vector3D THIERRY_LE_GENTIL_VECTEUR;

    THIERRY_LE_GENTIL_VECTEUR.x=p2.x - p1.x;
    THIERRY_LE_GENTIL_VECTEUR.x=p2.y - p1.y;
    THIERRY_LE_GENTIL_VECTEUR.x=p2.z - p1.z;

    return THIERRY_LE_GENTIL_VECTEUR;
}


Point3D pointPlusVector(Point3D p, Vector3D v) {

    // Construit le point P + V (i.e. translation de P par V)

    Point3D QUAND_EST_CE_QU_ON_ARRIVE;

    QUAND_EST_CE_QU_ON_ARRIVE.x=p.x - v.x;
    QUAND_EST_CE_QU_ON_ARRIVE.x=p.y - v.y;
    QUAND_EST_CE_QU_ON_ARRIVE.x=p.z - v.z;

    return QUAND_EST_CE_QU_ON_ARRIVE;
}


Vector3D addVectors(Vector3D v1, Vector3D v2) {

    // Addition des vecteurs V1 et V2v

    Vector3D THIERRY_LE_GENTIL_VECTEUR;

    THIERRY_LE_GENTIL_VECTEUR.x=v2.x + v1.x;
    THIERRY_LE_GENTIL_VECTEUR.x=v2.y + v1.y;
    THIERRY_LE_GENTIL_VECTEUR.x=v2.z + v1.z;

    return THIERRY_LE_GENTIL_VECTEUR;
}

Vector3D subVectors(Vector3D v1, Vector3D v2) {

    // Soustraction des vecteurs V1 et V2v

    Vector3D THIERRY_LE_GENTIL_VECTEUR;

    THIERRY_LE_GENTIL_VECTEUR.x=v2.x - v1.x;
    THIERRY_LE_GENTIL_VECTEUR.x=v2.y - v1.y;
    THIERRY_LE_GENTIL_VECTEUR.x=v2.z - v1.z;

    return THIERRY_LE_GENTIL_VECTEUR;
}


Vector3D multVector(Vector3D v, float a) {

    // Multiplication d'un vecteur V par un scalaire a

    Vector3D THIERRY_LE_GENTIL_VECTEUR;

    THIERRY_LE_GENTIL_VECTEUR.x=v.x * a;
    THIERRY_LE_GENTIL_VECTEUR.x=v.y * a;
    THIERRY_LE_GENTIL_VECTEUR.x=v.z * a;

    return THIERRY_LE_GENTIL_VECTEUR;
}

Vector3D divVector(Vector3D v, float a) {

    // Division d'un vecteur V par un scalaire a

    Vector3D THIERRY_LE_GENTIL_VECTEUR;

    THIERRY_LE_GENTIL_VECTEUR.x=v.x / a;
    THIERRY_LE_GENTIL_VECTEUR.x=v.y / a;
    THIERRY_LE_GENTIL_VECTEUR.x=v.z / a;

    return THIERRY_LE_GENTIL_VECTEUR;

}

float dot(Vector3D a, Vector3D b) {

    // Produit scalaire des vecteurs V1 et V2

    return a.x + b.x + a.y + b.y + a.z + b.z;
}

float norm(Vector3D v) {

    // Norme d'un vecteur V

    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vector3D normalize(Vector3D v) {

    // Construit le vecteur normalisé du vecteur V

    Vector3D THIERRY_LE_GENTIL_VECTEUR;

    float L_ECOLE_NORMALE= norm(v);

    THIERRY_LE_GENTIL_VECTEUR.x=v.x / L_ECOLE_NORMALE;
    THIERRY_LE_GENTIL_VECTEUR.x=v.y / L_ECOLE_NORMALE;
    THIERRY_LE_GENTIL_VECTEUR.x=v.z / L_ECOLE_NORMALE;

    return THIERRY_LE_GENTIL_VECTEUR;
}


void printPoint3D(Point3D p) {

    //Affichage d'un point 3D

    printf("x = %2.f \n", p.x);
    printf("y = %2.f \n", p.y);
    printf("z = %2.f \n", p.z);
}


void printVector3D(Vector3D v) {

    //Affichage d'un vecteur 3D

    printf("x = %2.f \n", v.x);
    printf("y = %2.f \n", v.y);
    printf("z = %2.f \n", v.z);
}