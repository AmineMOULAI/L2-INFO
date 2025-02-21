// Algorithme de tri

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Tableau 

void tab(int t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        t[i] = rand() % 100;
    }    
}

// tri à bulle

void tri_bulle(int t[], int n)
{
    int tmp, s;

    for (int i = 0; i < n - 1; i++)
    {
        s = 0;
        for (int j = 0; j < n -  i - 1; j++)
        {
          if(t[j] > t[j + 1])
          {
            tmp = t[j];
            t[j] = t[j+1];
            t[j+1] = tmp;
            s = 1;
          }
        }
        

        if (s == 0)
        {
            break;
        }
        
        
    }
    
}


// afficher le tableau 
void afficher(int t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", t[i]);
    }
    
}


int main()
{
    srand(time(NULL));
    
    const int n = 10;
    int t[n];

    tab(t, n);
    printf("Avant : ");
    afficher(t, n);
    printf("\n");
    tri_bulle(t, n);
    printf("Apres :");
    afficher(t, n);
    return 0;
}