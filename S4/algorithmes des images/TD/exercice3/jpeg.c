#include <stdio.h>
#include <stdlib.h>
#include "jpeg.h"
#include "exo1.h"

void pgm_extract_blk(pgm_t* inpgm, double blk[8][8], int i, int j)
{
    for (int x = 0; x < (int)inpgm->height; x++)
    {
        for (int y = 0; y < (int)inpgm->width; y++)
        {
            blk[i][j] = inpgm->pixels[x + i][y + j]; 
        }  
    }
}

void print(double blk[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%lf ", blk[i][j]);
        }
    }
    
}
int main()
{
    unsigned int h = 10, w = 15, v = 255;
    pgm_t* image = pgm_alloc(h, w, v);
    double bloc[8][8];

    pgm_extract_blk(image, bloc, 0, 0);

    print(bloc);

    return 0;
}