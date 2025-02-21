#include <stdio.h>
#include <stdlib.h>

#define N 9

// 
typedef struct 
{
    int val;
    int modif;
}cellule;

typedef struct coordonnees
{
    int x;
    int y;
    struct coordonnees *next; 
}coordonnees;

typedef struct 
{
    coordonnees *sommet;
}pile_coordonnees;



// fonctions 
cellule** creer_grille(cellule** t, int n)
{
    int i = 0;
    t = (cellule**)malloc(N * sizeof(cellule*));

    do
    {
        t[i] = malloc(N * sizeof(cellule));
        i++;
    } while (i < N && t[i - 1] != NULL);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        { 
            t[i][j].val = 0;
            t[i][j].modif = 0;
        }
    }
    
    return t;
}

void detruire_grille(cellule** t, int n)
{
    for (int j = 0; j < n; j++)
        free(t[j]);
    free(t);
    
}

cellule** remplir_grille(cellule** t, int n, const char* fic)
{
    FILE* f = fopen(fic, "r");

    if (f == NULL)
    {
        printf("Erreur !");
        exit(1);
    }
    int x, y, v;
    while (fscanf(f, "%d %d %d", &x, &y, &v) != EOF)
    {
        t[x - 1][y - 1].val = v;
    }
    fclose(f);

    return t;
}

void afficher_grille(cellule** t, int n)
{
    for (int i = 0; i < n + 6; i++)
        printf("+-");
    printf("+");
    printf("\n");
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j % 3 == 0) printf("| %d ", t[i][j].val);
            else printf(" %d ", t[i][j].val);
        }
        printf("|");
        printf("\n");
        if ((i + 1) % 3 == 0)
        {
            for (int i = 0; i < n + 6; i++)
                printf("+-");
            printf("+");
            printf("\n");
        }    
    }
}

pile_coordonnees* creer_pile_coordonnees()
{
    pile_coordonnees *pile = (pile_coordonnees*)malloc(sizeof(pile_coordonnees));

    pile->sommet = NULL;

    return pile;
}

void detruire_pile_coordonnees(pile_coordonnees* pile)
{
    coordonnees *p = pile->sommet;
    coordonnees *p1;

    while (p != NULL)
    {
        p1 = p->next;
        free(p);
        p = p1;
    }

    free(pile);
}

void empiler(pile_coordonnees* pile, int x, int y)
{
    coordonnees *newN = (coordonnees*)malloc(sizeof(coordonnees));

    newN->x = x;
    newN->y = y;
    newN->next = pile->sommet;
    pile->sommet = newN;
}

coordonnees* depiler(pile_coordonnees* pile)
{
    if (pile == NULL)
    {
        printf("Pile vide !");
        return -1;
    }

    coordonnees *tmp = pile->sommet;;
    pile->sommet = tmp->next;
    return tmp;
}

void afficher_pile(pile_coordonnees *pile)
{
    coordonnees *p = pile->sommet;

    while (p != NULL)
    {
        printf("(%d, %d)\n", p->x, p->y);
        p = p->next;
    }
    printf("NULL\n");
    
}

int combien_sur_ligne(cellule** g, int n, int ligne, int e)
{
    int occ = 0;
    for (int j = 0; j < n; j++)
    {
        if (g[ligne][j].val == e)
            occ += 1;
    }

    return occ;
}

int combien_sur_colonne(cellule** g, int n, int col, int e)
{
    int occ = 0;
    for (int i = 0; i < n; i++)
    {
        if (g[i][col].val == e)
            occ += 1;
    }

    return occ;
}

int combien_sur_bloc(cellule** g, int n, int x, int y, int e)
{
    int occ = 0;

    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; i < y + 3; j++)
        {
            if (g[i][j].val == e)
                occ++;
        }    
    }

    return occ;
    
}

int tester_validite(cellule**g, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = (i / 3) * 3;
            int y = (j / 3) * 3;
            if (combien_sur_ligne(g, n, i, g[i][j].val) > 1 || 
                combien_sur_colonne(g, n, j, g[i][j].val) > 1 || 
                combien_sur_bloc(g, n, x, y, g[i][j].val) > 1)
                return 0;
        }
    }
    return 1;
}

void resoudre_v1(cellule** g, int n)
{

    pile_coordonnees *p = creer_pile_coordonnees();
    int i = 0, j = 0;

    while (i < n)
    {
            
        if (g[i][j].val == 0 && g[i][j].modif == 0)
        {
            int trouve = 0;
            int k = 1;
            while (k <= 9 && g[i][j].modif == 0)
            {
                int x = (i / 3) * 3;
                int y = (j / 3) * 3;
                if (combien_sur_ligne(g, n, i, k) == 0 || 
                    combien_sur_colonne(g, n, j, k) == 0 || 
                    combien_sur_bloc(g, n, x, y, k) == 0)
                {    
                    g[i][j].val = k;
                    g[i][j].modif = 1;
                    empiler(p, i, j);
                    if (tester_validite(g, N))
                    {
                        trouve = 1;
                    }
                    else
                    {
                        g[i][j].val = 0;
                        g[i][j].modif = 0;

                    }
                    
                    
                }
                k++;
                    
            }
            
        }
        
    }
    
}



int main()
{
    cellule** g = NULL;
    
    g = creer_grille(g, N);

    g = remplir_grille(g, N, "sudoku-relax.txt");
    afficher_grille(g, N);

    detruire_grille(g, N);

    pile_coordonnees *pile = creer_pile_coordonnees();
    afficher_pile(pile);



    return 0;
}