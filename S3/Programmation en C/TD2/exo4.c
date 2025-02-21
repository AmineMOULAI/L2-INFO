// Min et Max d'une série d'entiers

#include <stdio.h>


int main()
{
    int value, max = 0, min = 0;
    float moy;

    printf("Entrer la série d'entiers :\n");
    scanf("%d", &value);
    printf("Vous avez entré : %d\n", value);

    min = value;
    max = value;

    while(scanf("%d", &value) != EOF)
    {
        printf("Vous avez entré : %d\n", value);


        if (min > value)
        {
            min = value;
        }
        if(max < value)
        {
            max = value;
        }
        
        
    }
    
    printf("Min : %d\n", min);
    printf("Max : %d", max);

    return 0;
}