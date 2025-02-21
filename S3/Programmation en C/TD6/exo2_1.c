#include <stdio.h>
#include <ctype.h>

int main() {
    char s[50];
    char tmp[50];
    char s1[50];
    int nb_mots = 0;

    // Saisie et écriture dans le premier fichier
    printf("Entrer la chaine de caracteres (fichier 1) : ");
    scanf(" %[^\n]", s); // Utilisation de " %[^\n]" pour lire toute la ligne

    FILE *f = fopen("exo2.txt", "w");
    if (f != NULL) {
        fprintf(f, "%s\n", s);
        fclose(f);
    }

    // Saisie et écriture dans le second fichier
    printf("Entrer la chaine de caracteres (fichier 2) : ");
    scanf(" %[^\n]", s1); // Utilisation de " %[^\n]" pour lire toute la ligne

    FILE *f1 = fopen("exo2_2.txt", "w");
    if (f1 != NULL) {
        fprintf(f1, "%s\n", s1);
        fclose(f1);
    }

    // Concaténation des deux fichiers
    f = fopen("exo2.txt", "a+");
    f1 = fopen("exo2_2.txt", "r");

    if (f != NULL && f1 != NULL) {
        while (fgets(tmp, sizeof(tmp), f1) != NULL) {
            fprintf(f, "%s", tmp); // Ajout du contenu de f1 dans f
        }
        fclose(f1);
        fclose(f);
    }

    // Lecture et affichage du contenu concaténé
    f = fopen("exo2.txt", "r");
    if (f != NULL) {
        printf("Contenu apres concaténation :\n");
        while (fgets(tmp, sizeof(tmp), f) != NULL) {
            printf("%s", tmp);
        }
        rewind(f); // Retour au début du fichier pour compter les mots

        // Comptage des mots
        char c;
        int in_word = 0;
        while ((c = fgetc(f)) != EOF) {
            if (isspace((unsigned char)c)) {
                in_word = 0; // Fin d'un mot
            } else if (!in_word) {
                in_word = 1; // Début d'un nouveau mot
                nb_mots++;
            }
        }
        fclose(f);
    }

    printf("\nNombre total de mots : %d\n", nb_mots);

    return 0;
}
