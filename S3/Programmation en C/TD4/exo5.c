// Damier 

#include <stdio.h> 

void afficher(int t, int c)
{
    for(int i = 0; i < t; i++)
    {
        for(int j = 0; j < c; j++)
        {
          for(int x = 0; x < c; x++)
          {
              if (i % 2 == 0)
              {             
                for (int k = 0; k < c; k++)
                {
                    printf("X");
                }
                for (int k = 0; k < c; k++)
                {
                    printf(".");
                }
              }
              else
              {
                  for (int k = 0; k < c; k++)
                {
                    printf(".");
                }
                for (int k = 0; k < c; k++)
                {
                    printf("X");
                }
              }
              
          }
          printf("\n");
        }
        
    }
}



int main()
{
    int t, c;

    printf("Entrer t et c :");
    scanf("%d%d", &t, &c);

    afficher(t, c);
    return 0;
}