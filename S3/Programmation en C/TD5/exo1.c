#include <stdio.h>
#include <stdlib.h>

int* allouer(int n)
{
    int* tab = (int*)malloc(n * sizeof(int));
    if (tab != NULL)
    {
        for (int i = 0; i < n; i++)
            tab[i] = 0;
    }

    return tab;
    
}


int main()
{

    int n;
    
    printf("Entrer n :");
    scanf("%d", &n);

    int* t = allouer(n);

    for (int i = 0; i < n; i++)
        printf("%d ", *(t + i));
    printf("\n");
    
    free(t);
    return 0;
}