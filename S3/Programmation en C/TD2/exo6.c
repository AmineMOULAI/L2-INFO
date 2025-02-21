// Multiplication égyptienne

#include <stdio.h>

int main()
{

    int a, b, x, y, r = 0;

    printf("Entrer a et b :");
    scanf("%d %d", &a, &b);

    x = a;
    y = b;

    while (y != 0)
    {
        if (y % 2 == 0)
        {
            x *= 2;
            y /= 2;
        }else
        {
            y -= 1;
            r += x;
        }
        
    }

    printf("%d x %d = %d",a, b, r);
    

}