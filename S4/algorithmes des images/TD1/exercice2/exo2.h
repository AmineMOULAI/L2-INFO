#ifndef EXO2_H
#define EXO2_H

typedef struct 
{
    unsigned char r, g, b;
}rgb_t;

typedef struct
{
    unsigned int height, width, max_value;
    rgb_t** pixels;
}ppm_t;

ppm_t* ppm_alloc(int h, int w, unsigned int max_v);
void ppm_free(ppm_t* img);
ppm_t* ppm_read_asc(const char* fname);
int ppm_write_asc(const char* fname, ppm_t* img);
void ppm_negative(ppm_t* src, ppm_t* dst);
void ppm_extract(const char* fname, ppm_t* img, int dx, int dy, int w, int h);
int** ppm_get_histrogram(ppm_t* img);
void ppm_write_histogram(const char* fname, ppm_t* img);

#endif