// Sapin de NOËL

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int l, v, h, r, v1, p;

    printf("Entrer l, h, r et p :");
    scanf("%d%d%d%d", &l, &h, &r, &p);

    v = (l * 2 - 1) / 2; 
    v1 = ((l * 2 - 1) - (r * 2 - 1)) / 2;

    for (int i = 1; i <= l; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i * 2 - 1 ; j++)
        {
            if (rand() % 100 < p)
            { 
                printf("o");
            }else
            {
                printf("^");
            }
            
        }
        for (int j = 0; j < v; j++)
        {
            printf(" ");
        }
        v -= 1;
        printf("\n");   
        
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < v1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < r * 2 - 1; j++)
        {
            printf("+");
        }
        for (int j = 0; j < v1; j++)
        {
            printf(" ");
        }
        printf("\n");
        
        
    }
    

    return 0;
    
}