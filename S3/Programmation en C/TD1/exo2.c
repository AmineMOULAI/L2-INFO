#include <stdio.h>

int main(void)
{
    const float t_cnss = 17.5 / 100, t_impot = 3.5 / 100;
    int nbr_enfant, jours;
    float salaire, prime, p_technicite, p_transport, prime_enfant, s_brut, t_travail,s_base, v_cnss, v_impot, brut;

    printf("Salaire brut :\n");
    scanf("%f", &s_brut);

    printf("Prime enfant :\n");
    scanf("%f", &prime_enfant);

    printf("Nombre d'enfants :\n");
    scanf("%d", &nbr_enfant);

    printf("Nombres de jours :\n");
    scanf("%d", &jours);

    v_impot = t_impot * s_brut;
    v_cnss = t_cnss * s_brut;
    prime = prime_enfant * nbr_enfant;
    t_travail = jours / 26;
    brut = (s_base + p_technicite + p_transport + prime) * t_travail;
    salaire = brut - v_impot - v_cnss;

    printf("Salaire net : %f", salaire);

    return 0;

}