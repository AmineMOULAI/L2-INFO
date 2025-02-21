#include <stdio.h>
#include <stdlib.h>

void allouer(int** t, int n)
{
    *t = malloc(n * sizeof(int));

    if (t!=NULL)
    {
        for (int i = 0; i < n; i++)
        (*t)[i] = 0;
    }
}

void modifier_taille(int* t, int n, int n1)
{
    int* t1;
    allouer(&t1, n1);

    for (int i = 0; i < n; i++)
        t1[i] = t[i];

    for (int i = n; i < n1; i++)
        t1[i] = 0;
    
    
}


int main()
{
    int n = 5;
    int* tab;

    allouer(&tab, n);

    for (int i = 0; i < n; i++)
        printf("%d ", tab[i]);

    printf("\n");

    modifier_taille(&tab, n, n + 5);
    for (int i = 0; i < n; i++)
        printf("%d ", tab[i]);


    free(tab);

    return 0;
}