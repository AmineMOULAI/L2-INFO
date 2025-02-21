// La moyenne d'une série d'entiers 

#include <stdio.h>


int main()
{
    int value, s = 0, c = 0;
    float moy;

    printf("Entrer la série d'entiers :\n");

    while(scanf("%d", &value) != EOF)
    {
        printf("Vous avez entré : %d\n", value);
        s += value;
        c += 1;
    }
    
    moy = (float)s / c; 
    printf("La moyenne : %.2f", moy);

    return 0;
}