// fibonacci avec mult matricielle 

#include <stdio.h>

int main()
{
    int F[2][2] = {{1, 1}, {1, 0}}, U[2][2] = {{1, 0}, {1, 0}}, R[2][2], n;


    printf("Entrer n : ");
    scanf("%d", &n);

    for (int x = 1; x < n; x++)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                R[i][j] = 0;
                for (int k = 0; k < 2; k++)
                {
                    R[i][j] += U[i][k] * F[k][j];
                }
                
            }
            
        }
        for (int a = 0; a < 2; a++)
        {
            for (int b = 0; b < 2; b++)
            {
                U[a][b] = R[a][b];
            }
            
        }
        
        
    }

    printf("U%d = %d", n, U[0][0]);

    return 0;
     
}