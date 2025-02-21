#include <stdio.h>
#include <math.h>

# define M_PI	3.14159265358979323846
 
float perimetre(float r)
{
    return 2 * M_PI * r;
}

int main()
{
    float r, p;

    printf("Entrer r : ");
    scanf("%f", &r);

    p = perimetre(r);
    printf("Le périmetre : %.2f\n", p);

    return 0;
}