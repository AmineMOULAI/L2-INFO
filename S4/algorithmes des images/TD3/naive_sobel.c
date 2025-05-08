#include <stdio.h>
#include <math.h>
#include "naive_sobel.h"
#include "../TD1/exercice1/exo1.h"
#include "../TD1/exercice2/exo2.h"

// Exercice 1 : Détecteurs naif et de Sobel

// Q1

unsigned char max_pgm(pgm_t* image)
{
    unsigned char max = image->pixels[0][0];

    for (int i = 0; i < image->height; i++)
    {
        for (int j = 0; j < image->width; j++)
        {
            if (max < image->pixels[i][j])
                max = image->pixels[i][j];
        }
    }
    return max; 
}

// Q2

pgm_t* naive_x(pgm_t* image)
{
    pgm_t* img_h = pgm_alloc(image->height, image->width, 0);

    int Kh[3][3] = {
        {  0, -1,  0 },
        {  0,  0,  0 },
        {  0,  1,  0 }
        };

    for (int i = 1; i < (int)image->height - 1; i++)
    {
        for (int j = 1; j < (int)image->width - 1; j++)
        {
            int res = 0;
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    res += image->pixels[i + k][j + l] * Kh[k + 1][l + 1];
                }
            }
            img_h->pixels[i][j] = (unsigned char) abs(res);
        }
    }
    return img_h;
}

pgm_t* naive_y(pgm_t* image)
{
    pgm_t* img_v = pgm_alloc(image->height, image->width, image->max_value);
    
    unsigned char Kv[3][3] = {
    {  0,  0,  0 },
    { -1,  0,  1 },
    {  0,  0,  0 }
    };

    for (int i = 1; i < image->height - 1; i++)
    {
        for (int j = 1; j < image->width - 1; j++)
        {
            int res = 0;
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    res += image->pixels[i + k][j + l] * Kv[k + 1][l + 1];
                }
            }
            img_v->pixels[i][j] = (unsigned char) abs(res);        }
    }
    return img_v;
}

pgm_t* naive_edge_detector(pgm_t* image)
{
    pgm_t* image_x = naive_x(image);
    pgm_t* image_y = naive_y(image);

    pgm_t* image_x_y = pgm_alloc(image->height, image->width, 0);
    for (int i = 0; i < image->height; i++)
    {
        for (int j = 0; j < image->width; j++)
            
            image_x_y->pixels[i][j] = sqrt(pow(image_x->pixels[i][j], 2) + pow(image_y->pixels[i][j], 2));
    }

    unsigned char M = max_pgm(image_x_y);
    
    for (int i = 0; i < image_x_y->height; i++)
    {
        for (int j = 0; j < image_x_y->width; j++)
        {
            image_x_y->pixels[i][j] = image_x_y->pixels[i][j] * 255 / M;
        }
        
    }
    
    return image_x_y;
    
}


int main()
{
    pgm_t* img = pgm_read_asc("../TD1/image2.pgm");
    unsigned char m = max_pgm(img);
    printf("max = %u\n", m);
   // print_img(img);

    pgm_t* edge_x = naive_x(img);
    printf("\n");
    print_img(edge_x);

    return 0;
}