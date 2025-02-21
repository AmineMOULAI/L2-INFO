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

void produitMat(int**a, int**b, int**res, int n, int m, int n1, int m1)
{
    if (m == n1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m1; j++)
            {
                res[i][j] = 0;
                for (int k = 0; k < m; k++)
                {
                    res[i][j] += a[i][k] * b[k][j];
                } 
            } 
        }
    }else printf("Multiplication impossible !\n");
    
}

int main()
{
    srand(time(NULL));

    int n, m, n1, m1;

    printf("Entrer dim A (n, m) :");
    scanf("%d %d", &n, &m);

    printf("Entrer dim B (n, m) :");
    scanf("%d %d", &n1, &m1);


    int** a = NULL;
    int** b = NULL;
    int** res = NULL;

    allouer(&a, n, m);
    allouer(&b, n1, m1);
    allouer(&res, n, m1);
   

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand() % 10;
        }        
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            b[i][j] = rand() % 10;
        }        
    }
    

    produitMat(a, b, res, n, m, n1, m1);

    afficher(a, n, m);
    printf("\n");
    afficher(b, n1, m1);
    printf("\n");
    if (m == n1)
    {
        afficher(res, n, m1);
        printf("\n");
    }

    liberer(a, n, m);
    liberer(b, n1, m1);
    liberer(res, n, m1);

    return 0;
}