// Nombre parfait

#include <stdio.h>


int main()
{
    int n, s = 0;
    
    printf("Entrer n :");
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            s += i;
        }
    }
    if (n == s)
    {
        printf("%d est parfait", n);
    }else{
        printf("%d n'est pas parfait", n);
    }
    
    

    return 0;
}