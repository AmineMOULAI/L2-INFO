#include <stdio.h>
#include <stdlib.h>
#include "jpeg.h"
#include "exo1.h"

void pgm_extract_blk(pgm_t* inpgm, double blk[8][8], int i, int j)
{
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            blk[x][y] = inpgm->pixels[x + i][y + j]; 
        }  
    }
}

void print(double blk[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%.2lf ", blk[i][j]);
        }
        printf("\n");
    }
}

void pgm_dct(double bloc[8][8])
{
    
}
int main()
{
    pgm_t* image = pgm_read_asc("../exercice1/eye_s_asc.pgm");

    
    double bloc[8][8];

    pgm_extract_blk(image, bloc, 20, 25);

    print(bloc);

    return 0;
}