// Valeur aléatoire 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


int main()
{
    srand(time(NULL));

    int value = rand()%100 +1, c = rand()%10+1, v;
    bool trouve = false;

    printf("c = %d\n", c);

    while ((c > 0) && (trouve == false))
    {
        printf("Entrer la valeur :");
        scanf("%d", &v);
        if (v < value)
        {
            printf("Plus !\n");
        }else if (v > value)
        {
            printf("Moins !\n");
        }else
        {
            printf("Bravo !\n");
            trouve = true;
        }
        c-= 1;
        
    }

    if (c == 0)
    {
        printf("Game over !\n");
    }
    
    

    return 0;
    
}