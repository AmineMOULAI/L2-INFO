#include <stdio.h>

int main()
{
    int k = 1, u, l, a = 2, c = 0, i;

    printf("Entrer l:");
    scanf("%d", &l);

    
    for (int i = a; i <= l ; i++)
    {
        u = i;
        c = 0;
        while (u != 1)
        {
            if (u % 2 == 0) u = u / 2;
            else u = 3 * u + 1;
           
            c += 1;
        }
        if (k < c)
        {
            k = c;
            a = i;
        }
    }
    printf("a = %d\n", a);
    printf("k = %d\n", k);


    return 0;

}