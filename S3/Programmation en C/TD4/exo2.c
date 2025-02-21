// distance entre deux points 

#include <stdio.h>
#include <math.h>

double distance(double xa, double xb, double ya, double yb)
{
    return sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
}

int main()
{

    double xa, xb, ya, yb, d;

    printf("Entrer xa et xb :");
    scanf("%lf%lf", &xa, &xb);

    printf("Entrer ya et yb :");
    scanf("%lf%lf", &ya, &yb);

    d = distance(xa, xb, ya, yb);

    printf("La distance entre a et b : %.2lf\n", d);

    
    return 0;
}