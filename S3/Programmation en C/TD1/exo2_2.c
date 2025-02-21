#include <stdio.h>

int main()
{
    int a, b, c, d;
    float moy;

    printf("Entrer les 4 entiers :");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    moy = (float)(a + b + c + d) / 4;

    printf("La moyenne : %.2f", moy);

    return 0;

}