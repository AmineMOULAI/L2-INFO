#include <stdio.h>
#include <stdlib.h>
#include "exo1.h"


pgm_t* pgm_alloc(int h, int w, unsigned int max_v)
{
    pgm_t* img = (pgm_t*)malloc(sizeof(pgm_t));
    img->height = h;
    img->width = w;
    img->max_value = max_v;
    img->pixels = (unsigned char**)malloc(h * sizeof(unsigned char*));
    if (img->pixels != NULL)
    {
        int i = 0;
        do
        {
            img->pixels[i] = (unsigned char*)malloc(w * sizeof(unsigned char));
            if(img->pixels[i] == NULL) printf("Erreur d'allocation !");
            i++;
        } while (i < (int)img->height && (int*)img->pixels[i - 1] != NULL);

        for (int i = 0; i < (int)img->height; i++)
        {
            for (int j = 0; j <(int)img->width ; j++)
                img->pixels[i][j] = img->max_value;
        }
    }else printf("Erreur d'allocation1 !");

    return img;
    
}

// 1->3
void pgm_free(pgm_t* img)
{
    for (int i = 0; i < (int)img->height; i++)
        free(img->pixels[i]);
    free(img->pixels);
    img->pixels= NULL;   
}

// 1->4
pgm_t* pgm_read_asc(const char* fname)
{
    FILE* f = fopen(fname, "r");
    if (f == NULL) printf("Erreur d'ouverture du fichier !");
    char type[3];
    
    fscanf(f, "%s", type);

    int c = fgetc(f);
    c = fgetc(f);
    while (c == '#')
    {
        while (c != '\n' && c != EOF)
        {
            c = fgetc(f);
        }
        c = fgetc(f);
    }
    if (c != EOF) ungetc(c, f);

    unsigned int h, w, max_v;
    fscanf(f, "%u %u %u", &w, &h, &max_v);
    
    pgm_t* image = pgm_alloc(h, w, max_v);
    
    for (int i = 0; i < (int)image->height; i++)
    {
        for (int j = 0; j < (int)image->width; j++)
        {
            int p;
            fscanf(f, "%d", &p);
            image->pixels[i][j] = p;
        }   
    }
    fclose(f);

    return image;
}

int pgm_write_asc(const char* fname, pgm_t* img)
{
    FILE* f = fopen(fname, "w");
    if(f == NULL)
    {
        printf("Erreur d'ouverture du fichier1 ");
        return 1;
    }
    char type[4] = "P2\n";
    fprintf(f, "%s", type);
    fprintf(f, "%u %u\n%u\n", img->width, img->height, img->max_value);
    for (int i = 0; i < (int)img->height; i++)
    {
        for (int j = 0; j < (int)img->width; j++)
            fprintf(f, "%d\n", (int)img->pixels[i][j]);
        
    }
    fclose(f);
     return 0;
}

void pgm_negative(pgm_t* scr, pgm_t** dst)
{
    *dst = pgm_alloc(scr->height, scr->width, scr->max_value);

    for (int i = 0; i < (int)scr->height; i++)
    {
        for (int j = 0; j < (int)scr->width; j++)
            (*dst)->pixels[i][j] = 255 - scr->pixels[i][j];
        
    }
    
}

void print_img(pgm_t* img)
{
    for (int i = 0; i < (int)img->height; i++)
    {
        for (int j = 0; j < (int)img->width; j++)
            printf("%3d ", img->pixels[i][j]);
        printf("\n");
    }
}

void pgm_extract(const char* fname, pgm_t* img, int dx, int dy, int width, int height)
{
    if ((int)img->height - (int)dx < (int)height || (int)img->width - (int)dy < (int)width)
    {
        printf("Extraction impossible !");
        return;
    }
    
    pgm_t* extracted_img = pgm_alloc(height, width, img->max_value);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            extracted_img->pixels[i][j] = img->pixels[dx + i][dy + j];
    }
    
    int q = pgm_write_asc(fname, extracted_img);
    printf("%d\n", q);
    free(extracted_img);
}

int* get_histogram(pgm_t* img)
{
    int* max_v = (int*)malloc(255 * sizeof(int));
    for (int i = 0; i < 256; i++)
        max_v[i] = 0; 
    
    for (unsigned int i = 0; i < img->height; i++)
    {
        for (unsigned int j = 0; j < img->width; j++)
            max_v[img->pixels[i][j]]++;
    }
    return max_v;    
}

void pgm_write_histogram(const char* fname, pgm_t* img)
{
    int* max_v = get_histogram(img);
    FILE* f = fopen(fname, "w");
    fprintf(f, "Ceci est un histogramme\n");
    for (int i = 0; i < 256; i++)
    {
        fprintf(f, "%d %d\n", i, max_v[i]);
    }
    fclose(f);
}
/*
int main()
{
    unsigned int h = 10, w = 15, v = 255;
    pgm_t* image = pgm_alloc(h, w, v); 

    for (int i = 0; i < (int)image->height; i++)
    {
        for (int j = 0; j < (int)image->width; j++)
            printf("%3d ", image->pixels[i][j]);
        printf("\n");
        
    }

    pgm_free(image);

    pgm_t* img1 = pgm_read_asc("eye_s_asc.pgm");
    //print_img(img1);
    
    int r = pgm_write_asc("image.pgm", img1);
    printf("%d\n", r);

    pgm_t* dist = NULL;
    pgm_negative(img1, &dist);
    //print_img(dist);

    pgm_extract("image2.pgm", img1, 0, 0, 256, 256);

    pgm_write_histogram("histogram.pgm", img1);

    return 0;
}
*/