// Fibonacci 

#include <stdio.h>

int main()
{
    int n, u, up = 0, upp = 1;

    printf("Entrer n :");
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        u = up + upp;
        up = upp;
        upp = u;
    }

    printf("U%d = %d", n, u);
    
    return 0;

}