#include <stdio.h>
#include <stdlib.h>
#include "transformation.h"

#define N 1

int main()
{
    double (*B[4])(double) = {B0, B1, B2, B3};

    double y = B[0](1.5);
    printf("%lf\n", y);
    return 0;
}