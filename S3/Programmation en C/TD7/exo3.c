#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    A = 1,
    B = 2,
    C = 3
}indice_t;

typedef struct 
{
    indice_t indice;
    int* d;
    int nbS_courant;
    int nb_max_s;
}socle_t;

socle_t* creer_socle(indice_t indx, int nbSocle)
{
    socle_t *s = (socle_t*)malloc(sizeof(socle_t));
    s->indice = indx;
    s->nb_max_s = nbSocle;
    s->nbS_courant = 0;
    s->d = (int*)malloc(nbSocle * sizeof(int));
    
    return s;
}

void detruire_socle(socle_t *s)
{
    if (s != NULL)
    {
        free(s->d);
        free(s);
    }
}

void affichage(socle_t *s)
{
    for (int i = 0; i < s->nb_max_s; i++)
    {
        for (int j = 0; j < s->d[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

void Hanoi(int n, socle_t *src, socle_t *inter, socle_t *dest)
{
    if (n > 0)
    {
        Hanoi(n - 1, src, dest, inter);
        printf("%d --> %d\n", src->indice, dest->indice);
        Hanoi(n - 1, inter, src, dest);
    }    
}

int main()
{
    int n;

    printf("Entrer n :");
    scanf("%d", &n);

    socle_t *a = creer_socle(A, n);

    for (int i = 0; i < a->nb_max_s; i++)
    {
        printf("Entrer le diametre de %d dique : ", i + 1);
        scanf("%d", &(a->d[i]));
    }

    
    socle_t *b = creer_socle(B, n);
    socle_t *c = creer_socle(C, n); 

    Hanoi(n, a, b, c);

    detruire_socle(a);
    detruire_socle(b);
    detruire_socle(c);

    return 0;
}