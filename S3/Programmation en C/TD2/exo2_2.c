// Nombres premiers dans [1, k] 

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int k;
    bool premier = true;

    printf("Entrer n :");
    scanf("%d", &k);


    for (int j = 1; j <= k; j++)
    {
        premier = 1;
        for (int i = 2; i < j; i++)
        {
            if (j % i == 0)
            {
                premier = false;
                break;
            }
        }

        if (premier == true)
        {
            printf("%d ", j);
        }
    }
    
    return 0;
}