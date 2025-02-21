// valeurs petites que n 

#include <stdio.h>

int main()
{
    const int n = 5;
    int tab[n], k,  c = 0;

    printf("Entrer k :");
    scanf("%d", &k);

    for (int i = 0; i < n; i++)
    {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        if (tab[i] < k)
        {
            c += 1;
        }
        
    }

    printf("Le nombre de valeurs petites que %d : %d", k, c);

    return 0;
    
    
}