#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int min_age;
    int max_age;

}classe_age;

typedef struct 
{
    int annee;
    classe_age age;
    int nbr_admis;
    float p_reussite;
    
}donnee;

donnee* creer_donnee(int annee, classe_age age, int nbr_admis, float p_reussite)
{
    donnee* d = (donnee*)malloc(sizeof(d));
    d->annee = annee;
    d->age = age;
    d->nbr_admis = nbr_admis;
    d->p_reussite = p_reussite;

    if (d == NULL)
    {   
        printf("erreur !\n");
        return NULL;
    }
    
    return d;
}

void afficher_donnee(donnee* d)
{
    if (d != NULL)
    {
        printf("Annee : %d\n", d->annee);
        printf("Age : %d - %d\n", d->age.min_age, d->age.max_age);
        printf("Nombre d'admis : %d\n", d->nbr_admis);
        printf("Pourcentage de reussite : %.2f\n", d->p_reussite);
    }
}

void liberer_donnee(donnee** d)
{
    if (d != NULL && *d != NULL)
    {
        free(*d);
        *d =NULL;
    }
}


int main()
{
    classe_age age = {20, 25};
    donnee* d = creer_donnee(2024, age, 100, 85.5);

    afficher_donnee(d);
    return 0;
}