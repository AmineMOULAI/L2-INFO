#include <stdio.h>
#include <string.h>

typedef struct 
{
    char ville[20];
    char date[20];
    float t[3];
}temperature;


// fonction 

float min_t(float t[], int n)
{
    float min = t[0];
    for (int i = 1; i < n; i++)
        if (min > t[i]) min = t[i];

    return min;

}

float max_t(float t[], int n)
{
    float max = t[0];
    for (int i = 1; i < n; i++)
        if (max < t[i]) max = t[i];

    return max;
}

float moyenne(float t[], int n)
{
    float s = 0;

    for (int i = 0; i < n; i++)
        s += t[i];

    return s / n;
}


int main()
{

    FILE *f = fopen("enregistrements.bin", "wb"); // Ouvre un fichier en mode binaire pour écriture

    if (f == NULL) {
        printf("Erreur d'ouverture du fichier !\n");
        return 1;
    }

    // Création de quelques enregistrements
    temperature e1 = {"Paris", "2024-12-01", {2, 25.5, 12}};
    temperature e2 = {"Lyon", "2024-12-02", {8, 29, 14}};
    temperature e3 = {"Marseille", "2024-12-03", {10, 31, 19}};
    
    // Écriture des enregistrements dans le fichier binaire
    fwrite(&e1, sizeof(temperature), 1, f);
    fwrite(&e2, sizeof(temperature), 1, f);
    fwrite(&e3, sizeof(temperature), 1, f);

    fclose(f); // Fermeture du fichier

    printf("Fichier binaire créé avec succès !\n");

    char v[20];

    printf("Entrer la ville : ");
    scanf("%s", v);

    f = fopen("enregistrements.bin", "rw");

    if (f == NULL)
    {
        printf("Erreur !");
        return 1;
    }

    temperature a;
    float mn, mx, moy;

    while (fread(&a, sizeof(temperature), 1, f) != 0)
    {
        if (strcmp(a.ville, v) == 0)
        {
            mn = min_t(a.t, 3);
            printf("Min : %.2f\n", mn);
            mx = max_t(a.t, 3);
            printf("Max : %.2f\n", mx);
            moy = moyenne(a.t, 3);
            printf("Moyenne : %.2f\n", moy);
        }
        
    }

    fclose(f);
    return 0;
}