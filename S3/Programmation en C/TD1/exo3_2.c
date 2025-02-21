#include <stdio.h>

int main()
{
    int a, b;

    printf("Entrer a :");
    scanf("%d", &a);

    printf("Entrer b :");
    scanf("%d", &b);


    if (a >= b)
    {
        printf("%d, %d", a, b);
    }else
    {
        printf("%d, %d", b, a);
    }

    return 0;
    
    
}