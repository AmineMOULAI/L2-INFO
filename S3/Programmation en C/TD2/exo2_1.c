// nombre premier

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n;
    bool premier = true;

    printf("Entrer n :");
    scanf("%d", &n);

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            premier = false;
            break;
        }
    }

    if (premier == true)
    {
        printf("%d est Premier !", n);
    }else
    {
        printf("%d n'est pas Premier !", n);
    }

    return 0;
}