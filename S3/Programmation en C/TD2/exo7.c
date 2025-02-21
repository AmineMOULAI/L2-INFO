// Valeurs d'une suite 

#include <stdio.h>

int main()
{
    int k, a, u;

    printf("Entrer k et a:");
    scanf("%d%d", &k, &a);

    u = a;
    printf("U0 = %d\n", a);
    
    for (int i = 1; i <= k; i++)
    {
        if (u % 2 == 0)
        {
            u = u / 2;
        }else
        {
            u = 3 * u + 1;
        }

        printf("U%d = %d\n", i, u);
    }


    return 0;

}