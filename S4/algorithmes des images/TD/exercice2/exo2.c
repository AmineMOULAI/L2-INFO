#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    unsigned char r, g, b;
}rgb_t;

typedef struct
{
    unsigned int height, width, max_value;
    rgb_t** pixels;
}ppm_t;

ppm_t ppm_alloc(int w, int h, unsigned int max_v)
{
    ppm_t img;
    img.height = h;
    img.width = w;
    img.max_value = max_v;
    img.pixels = (rgb_t**)malloc(h * sizeof(rgb_t*));
    if (img.pixels != NULL)
    {
        int i = 0;
        do
        {
            img.pixels[i] = (rgb_t*)malloc(w * sizeof(rgb_t));
            if(img.pixels[i] == NULL) printf("Erreur d'allocation !");
            i++;
        } while (i < (int)img.height && (int*)img.pixels[i - 1] != NULL);

        for (int i = 0; i < (int)img.height; i++)
        {
            for (int j = 0; j <(int)img.width ; j++)
            {
                img.pixels[i][j].r = img.max_value;
                img.pixels[i][j].g = img.max_value;  
                img.pixels[i][j].b = img.max_value;                  
            }
        }
    }else printf("Erreur d'allocation1 !");

    return img;
}

void ppm_free(ppm_t* image)
{
    for(int i = 0; i < (int)image->height; i++)
        free(image->pixels[i]);
    free(image->pixels);
    image->pixels = NULL;
    printf("Libération de l'image !\n");
}

ppm_t* ppm_read_asc(const char* fname)
{
    FILE* f = fopen(fname, "r");
    if (f == NULL) printf("Erreur d'ouverture du fichier !");
    char type[4];
    fscanf(f, "%s", type);

    int c = fgetc(f);
    c = fgetc(f);
    while (c == '#')
    {
        while (c != '\n' && c != EOF)
            c = fgetc(f);
        c = fgetc(f);
    }
    if(c != EOF) ungetc(c, f);

    int w, h, max_v;
    fscanf(f, "%u %u %u", &w, &h, &max_v);

    ppm_t img = ppm_alloc(w, h, max_v);

    for (int i = 0; i < (int)img.height; i++)
    {
        for (int j = 0; j < (int)img.width; j++)
        {
            unsigned int vr, vg, vb;
            fscanf(f, "%u %u %u", &vr, &vg, &vb);
            img.pixels[i][j].r = vr;
            img.pixels[i][j].g = vg;
            img.pixels[i][j].b = vb;
        }
    }
    fclose(f);

    ppm_t* image = (ppm_t*)malloc(sizeof(ppm_t));
    *image = img;
    
    return image;
}

int ppm_write_asc(const char* fname, ppm_t* img)
{
    FILE* f = fopen(fname, "w");
    if(f == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }
    char type[4] = "P3\n";
    fprintf(f, "%s", type);
    char comment[50] = "# Created by GIMP version 2.10.36 PNM plug-in\n";
    fprintf(f, "%s", comment);
    fprintf(f, "%u %u\n%u\n", img->width, img->height, img->max_value);
    for (int i = 0; i < (int)img->height; i++)
    {
        for (int j = 0; j < (int)img->width; j++)
            fprintf(f, "%d\n%d\n%d\n", img->pixels[i]->r, img->pixels[i]->g, img->pixels[i]->b);
        
    }
    fclose(f);
    return 0;
}

// 1.8

void ppm_negative(ppm_t* src, ppm_t* dst)
{
    for (int i = 0; i < (int)src->height; i++)
    {
        for (int j = 0; j < (int)src->width; j++)
        {
            dst->pixels[i]->r = src->max_value - src->pixels[i]->r;
            dst->pixels[i]->g = src->max_value - src->pixels[i]->g;
            dst->pixels[i]->b = src->max_value - src->pixels[i]->b;
        }
    }
    
}
int main()
{
    unsigned int h = 10, w = 15, v = 255;

    ppm_t image = ppm_alloc(h, w, v);

    /*for (int i = 0; i < (int)image.height; i++)
    {
        for (int j = 0; j < (int)image.width; j++)
            printf("(%3d, %3d, %3d) ", image.pixels[i][j].r, image.pixels[i][j].g, image.pixels[i][j].b);
        printf("\n");
    }*/
    ppm_free(&image);

    ppm_t* image1 = ppm_read_asc("eye_s_asc.ppm");

    /*for (int i = 0; i < (int)image1->height; i++)
    {
        for (int j = 0; j < (int)image1->width; j++)
            printf("(%3d, %3d, %3d)\n", image1->pixels[i][j].r, image1->pixels[i][j].g, image1->pixels[i][j].b);
        printf("\n");
    }*/

    int r = ppm_write_asc("image.ppm", image1);
    ppm_t res = ppm_alloc(image1->width, image1->height, image1->max_value);
    ppm_negative(image1, &res);

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
            printf("(%3d, %3d, %3d)\n", res.pixels[i][j].r, image1->pixels[i][j].g, image1->pixels[i][j].b);
        printf("\n");
    }

    return 0;
}