// allocation dynamique 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tri_bulle(float* t[], int n)
{
    int* tmp;
    float* p = t;
    float* q = t;


    for (int i = p + n; p > 0; p--)
    {
        for ( q = 0; q < p; q++)
        {
            if (*q < *(q) + 1)
            {
                tmp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = tmp;
            }     
        }
    }
    
}


int main()
{
    srand(time(NULL));

    float* t = NULL;
    int n;

    printf("Entrer la taille du tableau : ");
    scanf("%d", &n);

    t = (float*)malloc(n * sizeof(float));
    if (t != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            t[i] = rand() % 100; 
        }
    }

    if (t != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%.2f ", t[i]); 
        }
    }
    

    free(t);
    

    return 0;
}