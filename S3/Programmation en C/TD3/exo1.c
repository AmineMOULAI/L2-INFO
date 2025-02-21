// Afficher le contenu d'un tableau

#include <stdio.h>


int main()
{
    const int n = 5;
    int tab[n];

    for (int i = 0; i < n; i++)
    {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ",tab[i]);
    }

    return 0;
    
    
}