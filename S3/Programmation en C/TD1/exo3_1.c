#include <stdio.h>

int main()
{
    int n;

    printf("Entrer n :");
    scanf("%d", &n);

    if (n % 2 == 0)
    {
        printf("Pair !");
    }else
    {
        printf("Impair !");
    }

    return 0;
    
    
}