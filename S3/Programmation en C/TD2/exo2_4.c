// nombres parfaits dans [1, k]

#include <stdio.h>


int main()
{
    int k, s = 0;
    
    printf("Entrer n :");
    scanf("%d", &k);

    for (int j = 1; j < k; j++)
    {
        s = 0;
        for (int i = 1; i < j; i++)
        {
            if (j % i == 0)
            {
                s += i;
            }
        }
        if (j == s)
        {
            printf("%d ", j);
        }
    
    }

    return 0;
}