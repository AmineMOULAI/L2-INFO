#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "jpeg.h"
#include "exo1.h"

#define N 8
#define M_PI 3.14159265358979323846

void pgm_extract_blk(pgm_t* inpgm, double blk[N][N], int i, int j)
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            blk[x][y] = inpgm->pixels[x + i][y + j]; 
        }  
    }
}

void print(double blk[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%.2lf ", blk[i][j]);
        }
        printf("\n");
    }
}

double sum(double blocInput[N][N],int i, int j)
{
    double res = 0.0;

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            res += blocInput[x][y] * cos(((2 * x + 1) * i * M_PI) / (2.0 * N)) * cos(((2 * y + 1) * j * M_PI) / (2.0 * N));
    }
    return res;
}

void pgm_dct(double bloc[N][N])
{
    double DCT[N][N];
    double c0 = 1.0 / sqrt(2), ci = 1.0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0 && j == 0) DCT[i][j] = round((2 / sqrt(N * N)) * c0 * c0 * sum(bloc, i, j));
            else if(i == 0 || j == 0) DCT[i][j] = round((2 / sqrt(N * N)) * c0 * ci * sum(bloc, i, j));
            else DCT[i][j] = round((2 / sqrt(N * N)) * ci * ci * sum(bloc, i, j));
        } 
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            bloc[i][j] = DCT[i][j];
    }
    
}

void pgm_quantify(double blk[N][N], double Q[N][N])
{
    double DCT_quantified[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            DCT_quantified[i][j] = round(blk[i][j] / Q[i][j]);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            blk[i][j] = DCT_quantified[i][j];
    }
}

void pgm_zigzag_extract(double blk[N][N], int zgzg[64])
{
    int l = 0, c = 0, d = 1;
    for (int i = 0; i < N * N; i++)
    {
        zgzg[i] = blk[l][c];

        if (d == 1)
        {
            if (c == N - 1)
            {
                l++;
                d = -1;
            }
            else if (l == 0)
            {
                c++;
                d = -1;
            }else
            {
                l--;
                c++;
            }
        }else
        {
            if (l == N - 1)
            {
                c++;
                d = 1;
            }
            else if (c == 0)
            {
                l++;
                d = 1;
            }else
            {
                l++;
                c--;
            }
        }   
    }    
}

void pgm_rle(FILE* fd, int zgzg[N * N])
{
    if (fd != NULL)
    {
        int i = 0, c = 1;
        while(i < N * N)
        {
            if (zgzg[i] == 0)
            {
                while(i + c < N * N && zgzg[i] == zgzg[i + 1])
                    c++;
    
                if(c >= 2) fprintf(fd, "%d\n", c);
                else fprintf(fd, "%d\n", zgzg[i]);
                i += c;
            }else
            {
                fprintf(fd, "%d\n", zgzg[i]);
                i++;
            } 
        }
    }
}

void pgm_to_jpeg(pgm_t* in_pgm, char* fname)
{
    double Q[N][N] = {
        {16, 11, 10, 16, 24, 40, 51, 61},
        {12, 12, 14, 19, 26, 58, 60, 55},
        {14, 13, 16, 24, 40, 57, 69, 56},
        {14, 17, 22, 29, 51, 87, 80, 62},
        {18, 22, 37, 56, 68, 109, 103, 77},
        {24, 35, 55, 64, 81, 104, 113, 92},
        {49, 64, 78, 87, 103, 121, 120, 101},
        {72, 92, 95, 98, 112, 100, 103, 99}
    };

    FILE* f = fopen(fname, "w");
    
    if (f != NULL)
    {
        fprintf(f, "JPEG\n");
        fprintf(f, "%d %d\n", in_pgm->width, in_pgm->width);
        for (int i = 0; i < (int)in_pgm->height; i += N)
        {
            for (int j = 0; j <(int)in_pgm->width; j += N)
            {
                double bloc[N][N];
                int z[N * N];
                pgm_extract_blk(in_pgm, bloc, i, j);
                pgm_dct(bloc);
                pgm_quantify(bloc, Q);
                pgm_zigzag_extract(bloc, z);
                pgm_rle(f, z);
            }
               
        }
        fclose(f); 
    }else
    {
        printf("Error !\n");
        exit(1);
    }   
}

unsigned int fsize(char* fname)
{
    FILE* f = fopen(fname, "r");
    if (f != NULL)
    {
        fseek(f, 0L, SEEK_END);
        unsigned int s = ftell(f);
        fclose(f);
        return s;
    }else
    {
        return -1;
    }
    
    
}


int main()
{
    /*pgm_t* image = pgm_read_asc("../exercice1/eye_s_asc.pgm");

    
    double bloc[N][N];

    pgm_extract_blk(image, bloc, 0, N * 4);
    print(bloc);
    
    double blocIn[N][N] = {
    {139, 144, 149, 153, 155, 155, 155, 155},
    {144, 151, 153, 156, 159, 156, 156, 156},
    {150, 155, 160, 163, 158, 156, 156, 156},
    {159, 161, 162, 160, 160, 159, 159, 159},
    {159, 160, 161, 162, 162, 155, 155, 155},
    {161, 161, 161, 161, 160, 157, 157, 157},
    {162, 162, 161, 163, 162, 157, 157, 157},
    {162, 162, 161, 161, 163, 158, 158, 158}
    };

    double Q[N][N] = {
        {16, 11, 10, 16, 24, 40, 51, 61},
        {12, 12, 14, 19, 26, 58, 60, 55},
        {14, 13, 16, 24, 40, 57, 69, 56},
        {14, 17, 22, 29, 51, 87, 80, 62},
        {18, 22, 37, 56, 68, 109, 103, 77},
        {24, 35, 55, 64, 81, 104, 113, 92},
        {49, 64, 78, 87, 103, 121, 120, 101},
        {72, 92, 95, 98, 112, 100, 103, 99}
    };

    pgm_dct(blocIn);
    pgm_quantify(blocIn, Q);
    print(blocIn);
    int z[64] = {0};
    pgm_zigzag_extract(blocIn, z);
    printf("\n");
    for (int i = 0; i < N * N; i++)
        printf("%d ", z[i]);
    printf("\n");
    FILE* f = fopen("rle_compression.txt", "w");
    pgm_rle(f, z);*/

    pgm_t* in_pgm = pgm_read_asc("../exercice1/image2.pgm");
    pgm_to_jpeg(in_pgm, "jpeg.txt");
    printf("%d\n", fsize("jpeg.txt"));
    unsigned int taille_pgm = fsize("../exercice1/image2.pgm") / 1024;
    unsigned int taille_jpeg = fsize("jpeg.txt") / 1024;

    double facteur_compression = (double)taille_pgm / taille_jpeg;
    double reduction_pourcentage = (1 - ((double)taille_jpeg / taille_pgm)) * 100;

    printf("Taille du fichier PGM   : %u ko\n", taille_pgm);
    printf("Taille du fichier JPEG  : %u ko\n", taille_jpeg);
    printf("Facteur de compression  : %.2f\n", facteur_compression);
    printf("Réduction en pourcentage: %.2f%%\n", reduction_pourcentage);    
    return 0;
}