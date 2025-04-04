#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include "../../TD1/exercice1/exo1.h"
#include "../../TD1/exercice2/exo2.h"

    double B0(double x);
    double B1(double x);
    double B2(double x);
    double B3(double x);
    unsigned char interpolation_pgm(pgm_t* image, double x, double y);
    rgb_t interpolation_ppm(ppm_t* image, double x, double y);

#endif