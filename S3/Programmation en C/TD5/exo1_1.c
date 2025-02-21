#include <stdio.h>
#include <stdlib.h>

int* allouer(int n)
{
    int* t = malloc(n * sizeof(int));
    if (t!=NULL)
    {
        for (int i = 0; i < n; i++)
            t[i] = 0;
    }

    return t;
}


int main()
{
    int n = 5;
    
    int* tab = allouer(n);

    for (int i = 0; i < n; i++)
        printf("%d ", *(tab + i));
    
    free(tab);

    return 0;
}