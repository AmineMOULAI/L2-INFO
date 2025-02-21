#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** allouer(int n, int m)
{
    int** M = (int**)malloc(n * sizeof(int*));

    if (M != NULL)
    {
        int i = 0;
        do
        {
            M[i] = (int*)malloc(m * sizeof(int));
            i++;
        } while (i < n && M[i - 1] != NULL);

    }

    return M;
    
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

    int n, m;
    int** a = allouer(n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand() % 10;
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    liberer(a, n, m);

    
    
    return 0;
}