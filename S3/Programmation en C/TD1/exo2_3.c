#include <stdio.h>

int main()
{
    const float t_cnss = 17.5 / 100, t_impot = 3.5 / 100;
    int n_enfant, jours;
    float v_cnss, v_impot, s_base, s_brut, s_net, t_travail, p_technicite, p_transport, p_enfant, prime;

    printf("Entrer le salaire brut :");
    scanf("%f", &s_brut);

    printf("Entrer le nombres de jours travaillés :");
    scanf("%d", &jours);

    printf("Entrer le salaire de base :");
    scanf("%d", &s_base);

    printf("Entrer la prime de transport :");
    scanf("%d", &p_transport);

    printf("Entrer la prime de technicité :");
    scanf("%d", &p_technicite);

    printf("Entrer le nombre d'enfants :");
    scanf("%d", &n_enfant);

    printf("Entrer la prime d'un enfant :");
    scanf("%d", &p_enfant);


    v_cnss = t_cnss * s_brut;
    v_impot = t_impot * s_brut;
    prime = p_enfant * n_enfant;
    t_travail = jours / 26;
    s_brut = (s_base + p_technicite + p_transport + prime) * t_travail;
    s_net = s_brut - v_impot - v_cnss;

    printf("Le salaire net : %.2f", s_net);

    return 0;
}