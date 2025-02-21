#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define TOTAL_POS N * N


// structures
typedef struct 
{
    int couleur;
    int traite;

}cellule;

typedef struct
{
    cellule g[N][N];

}grille;

typedef struct 
{
    int l;
    int c;
}position;



enum color{
    
    Rouge,
    Vert,
    Bleu,
    Jaune,
    Noir,
    Blanc
};

// fonctions 

void remplir_grille(grille* t, cellule c)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            t->g[i][j].couleur = rand() % (c.couleur);
            t->g[i][j].traite = 0;
        }
        
    }
}

void afficher_grille(grille t)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            switch (t.g[i][j].couleur)
            {
            case Rouge:
                printf("\x1b[31mR\x1b[0m ");
                break;
            case Vert:
                printf("\x1b[32mV\x1b[0m ");
                break;
            case Bleu:
                printf("\x1b[34mB\x1b[0m ");
                break;
            case Jaune:
                printf("\x1b[33mJ\x1b[0m ");
                break;
            case Noir:
                printf("\x1b[30mN\x1b[0m ");
                break;
            case Blanc:
                printf("\x1b[37mW\x1b[0m ");
                break;
            default:
                break;
            }
        }
        printf("\n");
        
    }
    
}

void initialiser(position T[])
{
    for (int i = 0; i < TOTAL_POS; i++)
    {
        T[i].l = -1;
        T[i].c = -1;
    } 
}

void ajouter(position T[], position p)
{
    int i = 0;

    while (i < TOTAL_POS && T[i].l != -1 && T[i].c != -1)
    {
        i++; 
    }
    if (i < TOTAL_POS)
        {
            T[i].l = p.l;
            T[i].c = p.c;
        }
    
}

position retirer(position T[])
{
    position tmp;

    tmp = T[0];

    for (int i = 0; i < TOTAL_POS - 1; i++)
    {
        T[i] = T[i + 1]; 
    }
    T[TOTAL_POS - 1] = (position){-1, -1};
    
    return tmp;
}

void afficher(position T[])
{
    for (int i = 0; i < TOTAL_POS; i++)
    {
        if (T[i].l != -1 && T[i].c != -1)
        {
            printf("T[%d] = {%d, %d}\n",i ,T[i].l, T[i].c);
        }
        
    }
    
}

void modifier_couleur(position* T, grille* t, int couleur)
{
    position p = {0, 0};

    int couleur_init = t->g[0][0].couleur;
    ajouter(T, p);

    while (T[0].l != -1 && T[0].c != -1)
    {
        p = retirer(T);

        t->g[p.l][p.c].couleur = couleur;
        t->g[p.l][p.c].traite = 1;

        position adjacente[4] = {{p.l + 1, p.c}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l, p.c - 1}};

        for (int i = 0; i < 4; i++)
        {
            int x = adjacente[i].l;
            int y = adjacente[i].c;
            if (x >= 0 && x < N && y >= 0 && y < N && t->g[x][y].couleur == couleur_init && t->g[x][y].traite == 0)
            {
                ajouter(T, (position){x, y});
            } 
        }  
    } 
}

int taille_region_adjacente(position* T, grille* t)
{
    position p = {0, 0};
    int taille_reg_adj = 0;
    int couleur_init = t->g[0][0].couleur;

    ajouter(T, p);

    while (T[0].l != -1 && T[0].c != -1)
    {
        p = retirer(T);
        taille_reg_adj++;

        t->g[p.l][p.c].traite = 1;

        position adjacente[4] = {{p.l + 1, p.c}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l, p.c - 1}};

        for (int i = 0; i < 4; i++)
        {
            int x = adjacente[i].l;
            int y = adjacente[i].c;
            if (x >= 0 && x < N && y >= 0 && y < N && t->g[x][y].couleur == couleur_init && t->g[x][y].traite == 0)
            {
                ajouter(T, (position){x, y});
            } 
        }  
    }

    return taille_reg_adj;
}

int main()
{
    srand(time(NULL));
    grille f;
    cellule c1 = {6, 0};
    position T[TOTAL_POS], T1[TOTAL_POS];
    position k = {1, 2}, k1 = {0, 3}, k2 = {1, 3}, r;
    

    remplir_grille(&f, c1);
    afficher_grille(f);
    initialiser(T);
    ajouter(T, k);
    ajouter(T, k1);
    ajouter(T, k2);
    r = retirer(T);
    printf("r{%d, %d}\n", r.l, r.c);
    

    /*for (int i = 0; i < TOTAL_POS; i++)
    {
        printf("T[%d] = {%d, %d}\n",i, T[i].l, T[i].c);
    }*/
    printf("\n");
    modifier_couleur(T1, &f, Noir);
    //afficher(T);
    afficher_grille(f);

    return 0;

}