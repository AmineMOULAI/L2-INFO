// Saisie d'un arbre avec le tableau de papa

#include <stdio.h>

int feuille(int t[], int n, int x)
{
    for (int i = 0; i < n; i++) 
        if (t[i] == x) return 0; 
    return 1;
}

int hauteurA(int t[], int n)
{
    int h_max = 0;

    for (int i = 0; i < n; i++)
    {
        int h = 0;
        int v = t[0];
        while (v != -1)
        {
            h++;
            v = t[v];
        }
        if(h > h_max) h_max = h;
    }

    return h_max;  
}

int main()
{
    int n = 12;
    int t[n];
    for(int i = 0; i < n; i++)
    {
        printf("pére de noeud %d :", i);
        scanf("%d", &t[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (feuille(t, n, i) == 1)
            printf("%d est une feuille\n", i);
    }
    printf("\n");
    int hA = hauteurA(t, n);
    printf("La hauteur de l'arbre : %d\n", hA);
    
    return 0;
}