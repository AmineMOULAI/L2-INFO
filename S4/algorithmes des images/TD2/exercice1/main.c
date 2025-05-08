#include <stdio.h>
#include <stdlib.h>
#include "transformation.h"
#include <assert.h>

#define N 1

int main()
{
    double (*B[4])(double) = {B0, B1, B2, B3};

    double y = B[3](2.5);
    assert(y == 0);

    y = B[0](0.5);
    assert(y == 0.5);

    y = B[1](0.75);
    assert(y == 0.25);
    printf("Tous les tests sont vérifiés correctement !\n");
    pgm_t* img = pgm_read_asc("../../TD1/exercice1/image2.pgm");
    unsigned char z = interpolation_pgm(img, 0.8, 2.8);
    printf("%u\n", z);

    ppm_t* img1 = ppm_read_asc("../../TD1/exercice2/image_extracted.ppm");
    rgb_t p = interpolation_ppm(img1, 1.7, 2.3);
    printf("(%u, %u, %u)\n", p.r, p.g, p.b);
    return 0;
}