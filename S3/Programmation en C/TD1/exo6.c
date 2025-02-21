/* 1. pour a = 5, le resultat : --> valeur positive
           a = -4, resultat : --> valeur negative

   2. (condition) ? (coondition vraie) : (condition fausse)

   3. 

*/



#include <stdio.h>
#include <math.h>

int main()
{
float a, b, c, delta, x1, x2;

    printf("Entrer a, b et c : ");
    scanf("%f %f %f", &a, &b, &c);

    delta = b * b - 4 * a * c;

    (delta >= 0) ? ((-b - sqrt(delta)) / 2 * a) : 0;
    (delta >= 0) ? ((-b + sqrt(delta)) / 2 * a) : 0;

    if (delta >= 0)
    {
        x1 = (-b - sqrt(delta)) / 2 * a;
        x2 = (-b + sqrt(delta)) / 2 * a;

        printf(" Deux solutions :\nx1 = %.2f\nx2 = %.2f", x1, x2);
    }else{
        printf("Pas de solution !");
    }

    return 0;
    
}