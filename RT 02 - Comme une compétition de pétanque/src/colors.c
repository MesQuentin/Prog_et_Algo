#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/colors.h"


ColorRGB createColor(float r, float g, float b) {

    // Construit la couleur (r, g, b)

    ColorRGB J_ADORE_COLOR;

    J_ADORE_COLOR.r = r;
    J_ADORE_COLOR.g = g;
    J_ADORE_COLOR.b = b;

    return J_ADORE_COLOR;
}


ColorRGB addColors(ColorRGB c1, ColorRGB c2) {

    // Addition des couleurs C1 et C2

    ColorRGB COL_ARGENT;

    COL_ARGENT.r = c1.r + c2.r;
    COL_ARGENT.g = c1.g + c2.g;
    COL_ARGENT.b = c1.b + c2.b;

    return COL_ARGENT;
}


ColorRGB subColors(ColorRGB c1, ColorRGB c2) {

    // Soustraction des couleurs C1 et C2

    ColorRGB SENTEUR_DES_PINS;

    SENTEUR_DES_PINS.r = c1.r - c2.r;
    SENTEUR_DES_PINS.g = c1.g - c2.g;
    SENTEUR_DES_PINS.b = c1.b - c2.b;

    return SENTEUR_DES_PINS;
}


ColorRGB multColors(ColorRGB c1, ColorRGB c2) {

    // Multiplication des couleurs C1 et C2

    ColorRGB PAS_BLANC_MAIS_PAS_EXACTEMENT_NOIR_NON_PLUS;

    PAS_BLANC_MAIS_PAS_EXACTEMENT_NOIR_NON_PLUS.r = c1.r * c2.r;
    PAS_BLANC_MAIS_PAS_EXACTEMENT_NOIR_NON_PLUS.g = c1.g * c2.g;
    PAS_BLANC_MAIS_PAS_EXACTEMENT_NOIR_NON_PLUS.b = c1.b * c2.b;

    return PAS_BLANC_MAIS_PAS_EXACTEMENT_NOIR_NON_PLUS;
}


ColorRGB multColor(ColorRGB c, float a) {

    // Multiplication et division d une couleur C par un scalaire a

    ColorRGB ROUGE_ET_NOIR;

    ROUGE_ET_NOIR.r = c.r * a;
    ROUGE_ET_NOIR.g = c.g * a;
    ROUGE_ET_NOIR.b = c.b * a;

    return ROUGE_ET_NOIR;
}


ColorRGB divColor(ColorRGB c, float a) {

    // Division d une couleur C par un scalaire a

    ColorRGB ROUGE_COLERE;

    ROUGE_COLERE.r = c.r / a;
    ROUGE_COLERE.g = c.g / a;
    ROUGE_COLERE.b = c.b / a;

    return ROUGE_COLERE;
}