#include <stdio.h>

int main()
{
    int a, b;

    printf("Entrer a :");
    scanf("%d", &a);

    printf("Entrer b :");
    scanf("%d", &b);

    if (a > 0 && b > 0)
    {
        printf("Positif !");
    }else
    {
        printf("Négatif !");
    }

    return 0;
    
}