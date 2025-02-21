// Ascii art 

#include <stdio.h>

void aff(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("* ");
    }
    
}

void carre(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("* ");
        }
        printf("\n");
        
    }
    
}



int main()
{
    int n;

    printf("Entrer n :");
    scanf("%d", &n);
    printf("Ligne :\n");
    aff(n);
    printf("\n\n");
    printf("Carre :\n");
    carre(n);

    return 0;
}