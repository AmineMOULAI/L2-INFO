#ifndef EXO1_H
#define EXO1_H

typedef struct 
{
    unsigned int height, width, max_value;
    unsigned char** pixels;
}pgm_t;

pgm_t* pgm_alloc(int h, int w, unsigned int max_v);
void pgm_free(pgm_t* img);
pgm_t* pgm_read_asc(const char* fname);
int pgm_write_asc(const char* fname, pgm_t* img);
void pgm_negative(pgm_t* scr, pgm_t** dst);
void print_img(pgm_t* img);
void pgm_extract(const char* fname, pgm_t* img, int dx, int dy, int width, int height);
int* get_histogram(pgm_t* img);
void pgm_write_histogram(const char* fname, pgm_t* img);

#endif