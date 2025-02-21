// l'indice de la valeur min et max

#include <stdio.h>



int main()
{
    const int n = 10;
    int tab[20], min, max, indx_max, indx_min;

    for (int i = 0; i < n; i++)
    {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }
    printf("\n");

    min = tab[0];
    max = tab[0];

    for (int i = 0; i < n; i++)
    {
        if (min > tab[i])
        {
            min = tab[i];
            indx_min = i;
        }
        if (max < tab[i])
        {
            max = tab[i];
            indx_max = i;
        }
        
    }

    printf("L'indice de min (%d) : %d\n",min, indx_min);
    printf("L'indice de max (%d) : %d",max, indx_max);


    return 0;
    
    
}