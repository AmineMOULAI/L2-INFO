#include <stdio.h>

int calc(int n)
{
    int i, j, k;
    k = 0;
    i = n / 2;

    while (i <= n)
    {
        j = 1;
        while (j <= n)
        {
            k = k + n / 2;
            j = j * 2;
        }
        i = i + 1;
    }

    return k;
    
}

int main()
{
    int n;
    int c;

    printf("n = ");
    scanf("%d", &n);

    c = calc(n);

    printf("c = %d", c);

    return 0;
}