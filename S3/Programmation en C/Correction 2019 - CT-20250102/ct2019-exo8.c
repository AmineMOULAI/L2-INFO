#include <stdio.h>
#include <stdlib.h>

// ... Q1
void
transposee(int ** M, int ** T, int n)
{
  int i, j;
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
      T[i][j] = M[j][i];
}

// ... Q2
int
est_symetrique(int ** M, int n)
{
  int i, j, ret = 1;
  int ** T = (int **)malloc(n*sizeof(int*));
  for(i = 0; i < n; i++)
    T[i] = (int *)malloc(n*sizeof(int));
  // ...
  transposee(M, T, n);
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
      if(T[i][j] != M[i][j])
	ret = 0;
  // ...
  for(i = 0; i < n; i++)
    free(T[i]);
  free(T);
  return ret;
}

// ... Exemple
int
main(void)
{
  int i, j, n = 3;
  int ** M = (int **)malloc(n*sizeof(int*));
  for(i = 0; i < n; i++)
    M[i] = (int *)malloc(n*sizeof(int));
  // ...
  M[0][0] = 1;
  M[0][1] = 2;
  M[0][2] = 3;
  M[1][0] = 4;
  M[1][1] = 5;
  M[1][2] = 6;
  M[2][0] = 7;
  M[2][1] = 8;
  M[2][2] = 9;
  // ...
  printf("est_symetrique(M, n) = %d\n", est_symetrique(M, n));
  // ...
  for(i = 0; i < n; i++)
    free(M[i]);
  free(M);
  return 0;
}
