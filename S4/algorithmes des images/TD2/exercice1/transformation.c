#include <stdio.h>
#include <stdlib.h>
#include "transformation.h"
#include "../../TD1/exercice1/exo1.h"

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
    if(x_abs > 1) return 1.;
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