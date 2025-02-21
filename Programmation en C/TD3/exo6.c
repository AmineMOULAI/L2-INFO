// Mult matrice 2 x 2

#include <stdio.h>

int main()
{
    int A[2][2], B[2][2], R[2][2];


    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Entrer l'elt : ");
            scanf("%d", &A[i][j]);
        }
        
    }
    printf("\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Entrer l'elt : ");
            scanf("%d", &B[i][j]);
        }
        
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            R[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                R[i][j] += A[i][k] + B[k][j];
            } 
        } 
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }
    
    

    
    return 0;
}