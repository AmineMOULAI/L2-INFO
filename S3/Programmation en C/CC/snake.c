// Snake 


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 10
#define NBR_POMMES 6
#define NBR_OBSTACLES 6
#define LENGTH_GRID 20
#define WIDTH_GRID 20
#define TOTALE_POS WIDTH_GRID * LENGTH_GRID
#define POS_OBSTACLE 10

// structures 
typedef struct 
{
    int l;
    int c;

}position;

typedef enum
{
    N = 8, 
    S = 2,
    E = 6, 
    W = 4
}dir;

typedef struct 
{
    position file[TOTALE_POS];
    dir dir;
    int longeur;

}snake;

typedef struct
{
    position obs[POS_OBSTACLE];
    dir dir;
    int longeur;
}obstacle;


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

   for (int i = 0; i < longeur; i++)
   {
        ajouter(s.file, tete);
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
            grille[s.file[i].l][s.file[i].c] = 'o';
        }else{
            grille[s.file[i].l][s.file[i].c] = 'x';
        }       
    }

    for (int i = 0; i < NBR_POMMES; i++)
    {
        grille[P[i].l][P[i].c] = '*';
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
    position ntete = s.file[0];
   
        switch (d)
        {
        case N:
            ntete.l -= 1;
            break;
        case S:
            ntete.l += 1;
            break;
        case E:
            ntete.c += 1;
            break;
        case W:
            ntete.c -= 1;
            break;
        }

        for (int i = s.longeur - 1; i > 0; i--)
        {
            s.file[i] = s.file[i - 1];
        }
        s.file[0] = ntete;   
    
    return s;  
}

void changer_direction(snake s, dir d)
{
    s.dir = d;
}

void creer_pommes(snake s, position P[])
{
    position tmp;
    for (int i = 0; i < NBR_POMMES; i++)
    {
        tmp.l = rand() % LENGTH_GRID;
        tmp.c = rand() % WIDTH_GRID;
        if (appartient(s.file, tmp) == -1)
        {
            P[i].l = tmp.l;
            P[i].c = tmp.c;
        }         
    } 
}

int manger(position P[], snake s)
{
    int i = 0;
    while ((i < NBR_POMMES) && ((s.file[0].l != P[i].l) || (s.file[0].c == P[i].c)))
    {
        i++;
    }
    if (i < NBR_POMMES)
    {
        P[i].l = rand() % LENGTH_GRID;
        P[i].c = rand() % WIDTH_GRID;
        return 1;
    }else{
        return 0;
    }
}

snake redimensionner_serpent(snake s)
{
    int l = 0;
    int c = 0;

    switch (s.dir)
        {
        case N:
            l = -1;
            break;
        case S:
            l = 1;
            break;
        case E:
            c = 1;
            break;
        case W:
            c = -1;
            break;
        }
    
    position p = {s.file[0].l + l, s.file[0].c + c};
    ajouter(s.file, p);
    return s;
}

obstacle creer_obstacle(position p_obstacle, int longeur, dir d)
{
    obstacle o;
    o.dir = d;
    o.longeur = longeur;

    initialiser(o.obs);

     switch (o.dir)
    {
        ajouter(o.obs, p_obstacle);
        case N:
            p_obstacle.l = -1;
            break;
        case S:
            p_obstacle.l = 1;
            break;
        case E:
            p_obstacle.c = 1;
            break;
        case W:
            p_obstacle.c = -1;
            break;
    }

    return o;
}

void creer_obstacles(obstacle* o)
{
    int val[4] = {2, 4, 6, 8}; 
    position p;
    int longeur;
    dir d;

    for (int i = 0; i < NBR_OBSTACLES; i++)
    {
        p.l = rand() % LENGTH_GRID - 6;
        p.c = rand() % WIDTH_GRID - 6;        
        longeur = rand() % 10;
        int indx = rand() % 4;
        d = val[indx];
        

        o[i] = creer_obstacle(p, longeur, d);
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
    int a, b, x = 0, direction;

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

    printf("\n");

    creer_pommes(s, P);
    do
    {
        x++;
        afficher_grille(g, s, P);
        printf("Entrer la dir :");
        scanf("%d", &direction);
        s = avancer(s, direction);
        if (manger(P, s) == 1)
        {
            s = redimensionner_serpent(s);
        }
            
    } while (x < 20);
    
    return 0;
}