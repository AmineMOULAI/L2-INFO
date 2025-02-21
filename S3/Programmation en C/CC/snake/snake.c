// Snake 


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 10
#define NBR_POMMES 4
#define LENGTH_GRID 20
#define WIDTH_GRID 20
#define TOTALE_POS WIDTH_GRID * LENGTH_GRID


// structures 
typedef struct 
{
    int l;
    int c;

}position;

typedef enum
{
    N, 
    S,
    E, 
    W
}dir;

typedef struct 
{
    position file[TOTALE_POS];
    dir dir;
    int longeur;

}snake;


//fonctions

void initialiser(position T[])
{
    for (int i = 0; i < TOTALE_POS; i++)
    {
        T[i].l = -1;
        T[i].c = -1;
    }
    
}

void ajouter(position T[], position p)
{
    int i = 0;

    while ((i < TOTALE_POS) && (T[i].l != -1 && T[i].c != -1) && (T[i].l != p.l || T[i].c != p.c) )
        i++;

    if ((i < TOTALE_POS))
    {
        T[i].l = p.l;
        T[i].c = p.c;
    }
    
}    

position retirer(position T[])
{
    position p = T[0];

    for(int i = 1; i < TOTALE_POS - 1; i++)
    {
        T[i - 1] = T[i];
    }
    T[TOTALE_POS - 1] = (position){-1, -1};

    return p;
}    


int appartient(position T[], position p)
{
    for (int i = 0; i < TOTALE_POS; i++)
    {
        if (T[i].l == p.l && T[i].c == p.c)
        {
            return i;
        } 
    }
    return -1;
}

snake creer_serpent(position tete, int longeur, dir d) 
{
   snake s;
   s.dir = d;
   s.longeur = longeur;
   initialiser(s.file);

   ajouter(s.file, tete);

   for (int i = 1; i < longeur; i++)
   {
        switch (d)
        {
        case N:
            tete.l += 1;
            break;
        case S:
            tete.l -= 1;
            break;
        case E:
            tete.c += 1;
            break;
        case W:
            tete.c -= 1;
            break;
        }

        ajouter(s.file, tete);
   }
   return s;
}

void afficher_grille(char grille[WIDTH_GRID][LENGTH_GRID], snake s, position P[])
{
    for (int i = 0; i < LENGTH_GRID; i++)
    {
        for (int j = 0; j < WIDTH_GRID; j++)
        {
            grille[i][j] = '.';
        }
    }
 
    for (int i = 0; i < s.longeur; i++)
    {
        if (i == 0)
        {
            grille[s.file[i].l][s.file[i].c] = 'O';
        }else{
            grille[s.file[i].l][s.file[i].c] = 'X';
        }
        
    }

    for (int i = 0; i < NBR_POMMES; i++)
    {
        grille[P[i].l][P[i].c] = 'P';
    }
    

    for (int i = 0; i < LENGTH_GRID; i++)
    {
        for (int j = 0; j < WIDTH_GRID; j++)
        {
            printf("%c ", grille[i][j]);
        }
        printf("\n");
    }
      
}

snake avancer(snake s, dir d)
{
    for (int i = 0; i < s.longeur; i++)
    {
        switch (d)
        {
        case N:
            s.file[i].l -= 1;
            break;
        case S:
            s.file[i].l += 1;
            break;
        case E:
            s.file[i].c += 1;
            break;
        case W:
            s.file[i].c -= 1;
            break;
        }
    }
    return s;
    
}

void changer_direction(snake s, dir d)
{
    s.dir = d;
}

void creer_pommes(position P[])
{
    for (int i = 0; i < NBR_POMMES; i++)
    {
        P[i].l = rand() % LENGTH_GRID;
        P[i].c = rand() % WIDTH_GRID;
    }
    
}

int manger(position P[], snake s)
{
    for (int i = 0; i < NBR_POMMES ; i++)
    {
        if ((s.file[0].l == P[i].l) && (s.file[0].c == P[i].c))
        {
            P[i].l = rand() % LENGTH_GRID;
            P[i].c = rand() % WIDTH_GRID;
        }
        
        
    }
    
}



int main()
{
    srand(time(NULL));

    position T[TOTALE_POS];
    position P[NBR_POMMES];
    position k = {1, 2}, r = {2, 2}, v = {3, 2}, d = {3, 2};
    position m = {5, 3};
    snake s;
    char g[WIDTH_GRID][LENGTH_GRID];
    int a, b;

    initialiser(T);
    ajouter(T, k);
    ajouter(T, r);
    ajouter(T, v);
    ajouter(T, d);
    
    for (int i = 0; i < TOTALE_POS; i++)
    {
        printf("T[%d] = {%d, %d}\n", i, T[i].l, T[i].c);
    }

    a = appartient(T, v);
    b = appartient(T, m);

    printf("L'indice de {%d, %d} : %d\n", v.l, v.c, a);
    printf("b = %d\n", b);

    s = creer_serpent(m, 4, N);
    printf("\n");
    

    for (int i = 0; i < TOTALE_POS; i++)
    {
        printf("s[%d] = {%d, %d}\n", i, s.file[i].l, s.file[i].c);
    }

    s = avancer(s, N);

    printf("\n");

    creer_pommes(P);

    afficher_grille(g, s, P);

    return 0;
}