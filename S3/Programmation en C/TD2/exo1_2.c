// Afficher le nombre de chiffres non nuls dans n

#include <stdio.h>

int main()
{
    int n, m, r, c = 0;

    printf("Entrer n :");
    scanf("%d", &n);

    m = n;

    while (m != 0)
    {
        r = m % 10;
        if (r != 0)
        {
            c += 1;
        }
        
        m /= 10;
    }

    printf("Le nombre de chiffres non nuls : %d", c);
    

    return 0;
}