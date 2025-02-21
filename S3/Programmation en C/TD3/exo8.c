// Triangle de Pascal 

#include <stdio.h>

int main()
{
    int n;

    printf("Entrer le nombre d'elts :");
    scanf("%d", &n);

    int t[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            t[i][j] = 0;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        t[i][0] = 1;
        t[i][i] = 1;
        
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", t[i][j]);
        }
        printf("\n");
        
    }  
      
    return 0;
}