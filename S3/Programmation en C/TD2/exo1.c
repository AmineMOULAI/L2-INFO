// 1. Factorielle 

#include <stdio.h>

int main()
{
    int n, f = 1;

    printf("Entrer n :");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        f = f * i;
    }
    
    printf("%d! = %d", n, f);

    return 0;
}