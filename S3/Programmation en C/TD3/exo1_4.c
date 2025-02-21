// rotation de k rangs

#include <stdio.h>

int main()
{
    const int n = 7;
    int tab[n], tab1[n], k, p, tmp;

    printf("Entrer p :");
    scanf("%d", &p);

    for (int i = 0; i < n; i++)
    {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        k = i + 3;
        if (k < n)
        {
            tab1[k] = tab[i];
        }else
        {
            tab1[k - n] = tab[i];
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",tab1[i]);
    }

    return 0;
    
    
}