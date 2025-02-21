// permutation

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, e;
    bool permut = false, trouve = false;

    printf("Entrer n:");
    scanf("%d", &n);

    int tab[n];

    for (int i = 0; i < n; i++)
    {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }
    printf("\n");


    while (e < n && permut == 1)
    {
        trouve == 0;
        for (int j = 0; j < n; j++)
        {
            if (tab[j] == e) trouve == 1;
        
        }
        if (!trouve) permut == 0;
    }

    if (permut == 1)
    {
        printf("Permutation !");
    }else
    {
        printf("Pas une permutation !");
    }
    
    

    return 0;
    
    
}