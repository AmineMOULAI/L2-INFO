// Moutons et dindons

#include <stdio.h>

void fermier(int t, int p)
{
    int m = 0, d = 0, solution = 0;

    while((m < t) && (m * 4 + d * 2 != p)) 
    {
        d = t - m;
        m++;   
    }
    if(m != t)
    {
      printf("Nombres de moutons : %d\nNombres de dindons : %d\n", m, d);
      solution = 1;
    }
    if (!solution)
    {
        printf("Aucune solution !\n");
    }
    
}


int main()
{
    int t, p;

    printf("Entrer t et p :");
    scanf("%d%d", &t, &p);

    fermier(t, p);
    return 0;
}