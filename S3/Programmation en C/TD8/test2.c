#include <stdio.h>

#define TAILLE 10 // Taille du tableau

// Fonction pour afficher le tas de crêpes
void crepes(int T[]) {

    int rayonmax = T[0];
    for (int i = 0; i < TAILLE; i++)
        if (rayonmax < T[i]) rayonmax = T[i];
        
    

    for (int i = 0; i < TAILLE; i++) {
        int rayon = T[i];
        
        for (int j = 0; j < rayonmax - rayon; j++) {
            printf(" ");
        }
        // Affichage des étoiles à gauche
        for (int j = 0; j < rayon; j++) {
            printf("*");
        }

        // Barre verticale centrale
        printf("|");

        // Affichage des étoiles à droite
        for (int j = 0; j < rayon; j++) {
            printf("*");
        }

        // Saut de ligne
        printf("\n");
    }

    // Ligne de base
    for (int i = 0; i < 20; i++) {
        printf("-");
    }
    printf("+\n"); // Séparateur central
}

int main() {
    int T[TAILLE] = {3, 4, 7, 1, 10, 2, 5, 9, 6, 8}; // Tableau des rayons

    // Affichage du tas de crêpes
    printf("Tas de crêpes :\n");
    crepes(T);

    return 0;
}
