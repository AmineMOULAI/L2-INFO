// Sapin de NOËL

#include <stdio.h>

int main()
{
    int l, v, h, r, v1;

    printf("Entrer l, h et r :");
    scanf("%d%d%d", &l, &h, &r);

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
            printf("^");
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