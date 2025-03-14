#ifndef JPEG_H
#define JPEG_H
#include "exo1.h"
#define N 8 
void pgm_extract_blk(pgm_t* inpgm, double blk[N][N], int i, int j);
void print(double blk[N][N]);
double sum(double blocInput[N][N],int i, int j);
void pgm_dct(double bloc[N][N]);
void pgm_quantify(double blk[N][N], double Q[N][N]);
void pgm_zigzag_extract(double blk[N][N], int zgzg[64]);
void pgm_rle(FILE* fd, int zgzg[N * N]);
void pgm_to_jpeg(pgm_t* in_pgm, char* fname);







#endif