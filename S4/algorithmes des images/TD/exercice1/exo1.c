#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
typedef struct 
{
    unsigned int height, width, max_value;
    unsigned char** pixels;
}pgm_t;

pgm_t pgm_alloc(int h, int w, unsigned int max_v)
{
    pgm_t img;
    img.height = h;
    img.width = w;
    img.max_value = max_v;
    img.pixels = (unsigned char**)malloc(h * sizeof(unsigned char*));
    if (img.pixels != NULL)
    {
        int i = 0;
        do
        {
            img.pixels[i] = (unsigned char*)malloc(w * sizeof(unsigned char));
            if(img.pixels[i] == NULL) printf("Erreur d'allocation !");
            i++;
        } while (i < (int)img.height && (int*)img.pixels[i - 1] != NULL);

        for (int i = 0; i < (int)img.height; i++)
        {
            for (int j = 0; j <(int)img.width ; j++)
                img.pixels[i][j] = img.max_value;
        }
    }else printf("Erreur d'allocation1 !");

    return img;
    
}

// 1.3
void pgm_free(pgm_t* img)
{
    for (int i = 0; i < (int)img->height; i++)
        free(img->pixels[i]);
    free(img->pixels);
    img->pixels= NULL;   
}

// 1.4
pgm_t* pgm_read_asc(const char* fname)
{
    FILE* f = fopen(fname, "r");
    if (f == NULL) printf("Erreur d'ouverture du fichier !");
    char type[3];
    
    fscanf(f, "%s", type);
    printf("%s", type);

    int c = fgetc(f);
    c = fgetc(f);
    printf("%c ", c);
    while (c == '#')
    {
        while (c != '\n' && c != EOF)
        {
            c = fgetc(f);
            printf("%c ", c);
        }
        c = fgetc(f);
        printf("%c ", c);
    }
    if (c != EOF) ungetc(c, f);

    unsigned int h, w, max_v;
    fscanf(f, "%u %u %u", &w, &h, &max_v);
    
    pgm_t image = pgm_alloc(h, w, max_v);
    
    for (int i = 0; i < (int)image.height; i++)
    {
        for (int j = 0; j < (int)image.width; j++)
        {
            int p;
            fscanf(f, "%d", &p);
            image.pixels[i][j] = p;
        }   
    }
    fclose(f);

    pgm_t* img = (pgm_t*)malloc(sizeof(pgm_t));
    *img = image;

    return img;
}

// 1.5
int pgm_write_asc(const char* fname, pgm_t* img)
{
    FILE* f = fopen(fname, "w");
    if(f == NULL)
    {
        printf("Erreur d'ouverture du fichier ");
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

// 1.6
pgm_t* pgm_read_bin(const char* fname)
{
    FILE* f = fopen(fname, "rb");
    if(f == NULL)
    {
        printf("Erreur d'ouverture du fichier !\n");
        return NULL;
    }

    char type[4];
    fread(type, sizeof(char), 3, f);
    if (strcmp(type, "P5\n"))
        return NULL;
    
    char c = '#';
    while (c != '\n')
        fread(&c, sizeof(char), 1, f);
    
    unsigned int w, h, max_v;
    fscanf(f, "%u %u %u", &w, &h, &max_v);

    pgm_t image = pgm_alloc(h, w, max_v);
    unsigned char v;
    fread(&v, sizeof(unsigned char), 1, f);
    
    for (int i = 0; i < (int)image.height; i++)
    {
        fread(image.pixels[i], sizeof(unsigned char), (int)image.width, f);        
    }
    fclose(f);
    pgm_t* img = (pgm_t*)malloc(sizeof(pgm_t));
    *img = image;

    return img;
}
int main()
{
    unsigned int h = 10, w = 15, v = 255;
    pgm_t image = pgm_alloc(h, w, v); 

    for (int i = 0; i < (int)image.height; i++)
    {
        for (int j = 0; j < (int)image.width; j++)
            printf("%3d ", image.pixels[i][j]);
        printf("\n");
        
    }

    pgm_free(&image);
    /*
    pgm_t* img1 = pgm_read_asc("eye_s_asc.pgm");
    

    for (int i = 0; i < (int)img1->height; i++)
    {
        for (int j = 0; j < (int)img1->width; j++)
            printf("%3d ", img1->pixels[i][j]);
        printf("\n");
    }
    
    int r = pgm_write_asc("image.pgm", img1);

    printf("%d\n", r);
    */
    pgm_t* img1 = pgm_read_bin("eye_s_asc.pgm");

    /*for (int j = 0; j < (int)img1->height; j++)
    {
        for (int k = 0; k < (int)img1->width; k++)
            printf("%3d ", img1->pixels[j][k]);
        printf("\n");
    }*/
    printf("%d %d %d\n", img1->width, img1->height,img1->max_value);

    
    return 0;
}