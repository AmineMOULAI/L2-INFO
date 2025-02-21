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


int main()
{
    int n = 5;
    int* tab;

    allouer(&tab, n);

    for (int i = 0; i < n; i++)
        printf("%d ", tab[i]);

    free(tab);

    return 0;
}