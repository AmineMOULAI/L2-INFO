#include <stdio.h>

int main()
{
    float val, euro, franc = 6.55957;

    printf("Entrer la somme en francs :");
    scanf("%f", &val);

    euro = val / franc;

    printf("La somme en euro : %f", euro);

    return 0;
}