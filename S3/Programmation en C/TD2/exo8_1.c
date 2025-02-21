// Sapin de NOËL

#include <stdio.h>

int main()
{
    int l, v;

    printf("Entrer l :");
    scanf("%d", &l);

    v = (l * 2 - 1) / 2;

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

    return 0;
    
}