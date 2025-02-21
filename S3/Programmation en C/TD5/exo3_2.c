#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void allouer(int*** M, int n, int m)
{
    *M = (int**)malloc(n * sizeof(int*));

    if (*M != NULL)
    {
        int i = 0;
        do
        {
            (*M)[i] = (int*)malloc(m * sizeof(int));
            i++;
        } while (i < n && (*M)[i - 1] != NULL);
    }
}

void afficher(int** M, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }
}

void liberer(int** M, int n, int m)
{
    if (M != NULL)
    {
        for (int j = 0; j < m; j++)
            free(M[j]);
        free(M);
    }
}


int main()
{
    srand(time(NULL));

    int n = 3, m = 2;
    int** a = NULL;
    
    allouer(&a, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand() % 10;
        }        
    }
    
    afficher(a, n, m);
    liberer(a, n, m);

    return 0;
}