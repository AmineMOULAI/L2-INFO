#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "transformation.h"
#include "../../TD1/exercice1/exo1.h"
#include "../../TD1/exercice2/exo2.h"

#define N 1

double B0(double x)
{
    double x_abs = fabs(x);
    if(x_abs > 0.5) return 0.;
    else if(x_abs < 0.5) return 1.;
    else return 0.5;
}

double B1(double x)
{
    double x_abs = fabs(x);
    if(x_abs > 1) return 0.;
    else if(x >= -1 && x <= 0) return x + 1;
    else return 1 - x;
}

double B2(double x)
{
    double x_abs = fabs(x);
    if(x_abs > 1.5) return 0;
    else if(x >= -1.5 && x <= -0.5) return 0.5 * (x + 1.4) * (x + 1.4);
    else if(x >= -0.5 && x <= 0.5) return 0.75 - x*x;
    else if(x >= 0.5 && x <= 1.5) return 0.5 * (x - 1.5) * (x - 1.5);
}

double B3(double x)
{
    double x_abs = fabs(x);
    if( x_abs > 2) return 0;
    else if(x_abs >= 0 && x_abs <= 1) return (1/2) * (x_abs*x_abs*x_abs) - x*x + 2/3;
    else if(x_abs >= 1 && x_abs <= 2) return (1/6)*(2 - x_abs)*(2 - x_abs)*(2 - x_abs);
}

double (*B[4])(double) = {B0, B1, B2, B3};

unsigned char interpolation_pgm(pgm_t* image, double x, double y)
{
    double px = 0.;

    for (int i = 0; i < (int)image->height; i++)
    {
        for (int j = 0; j < (int)image->width; j++)
        {
            px += B[N](x - i) * B[N](y - j) * image->pixels[i][j];        
        }
    }
    return (unsigned char)round(px);
}

rgb_t interpolation_ppm(ppm_t* image, double x, double y)
{
    rgb_t px;

    for (int i = 0; i < (int)image->height; i++)
    {
        for (int j = 0; j < (int)image->width; j++)
        {
            px.r += B[N](x - i) * B[N](y - j) * image->pixels[i][j].r;        
            px.g += B[N](x - i) * B[N](y - j) * image->pixels[i][j].g;        
            px.b += B[N](x - i) * B[N](y - j) * image->pixels[i][j].b;        
        }
    }
    printf("%u, %u, %u\n", px.r, px.g, px.b);
    return px;
}

pgm_t* rotation_pgm(pgm_t* image, double theta, int x0, int y0)
{
    pgm_t* rotated_img = pgm_alloc(image->height, image->width, image->max_value);
    for (int i = 0; i < (int)image->height; i++)
    {
        for (int j = 0; j < (int)image->width; j++)
        {
            double dx = x0 + (i - x0) * cos(-theta) - (j - y0) * sin(-theta);
            double dy = y0 + (i - x0) * sin(-theta) - (j - y0) * cos(-theta);

            unsigned char z = interpolation_pgm(image, dx, dy);
            rotated_img->pixels[i][j] = z;
        }   
    }
    return rotated_img;
        
}
