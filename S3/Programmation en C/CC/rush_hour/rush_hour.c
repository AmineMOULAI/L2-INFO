#include <stdio.h>
#include <stdlib.h>

#define SIZE_G 6
#define NB_VEHICULE 16

typedef struct 
{
    char g[SIZE_G][SIZE_G];
}grille_t;


// Direction de mouvement 
typedef enum
{
    H,
    B,
    G,
    D
}direction_t;

// Vehicule 
typedef struct 
{
    int ligne;
    int colonne;
    int longeur;
    char orientation;    
    char nom;
}vehicule_t;

// Mouvement 
typedef struct 
{
    int v;
    int l;
    direction_t d;
}mouvement_t;


// Configuration 
typedef struct 
{
    vehicule_t pos_v[16];
    int prec;
    mouvement_t move;
}config_t;

// Rush Hour
typedef struct 
{
    config_t* tab;
    int size;
    int current;
    int max;
    int nb_v;
}rush_hour_t;

// augmenter la taille du tab config
void increase_size(rush_hour_t* r, int n)
{
    r->size += n;
    r->tab = (config_t*)realloc(r->tab, r->size * (sizeof(config_t)));
}

//allouer rush hour, lire d'un fichier la config

rush_hour_t* allocate(char* filename, int n)
{
    rush_hour_t* r = (rush_hour_t*)malloc(sizeof(rush_hour_t));
    r->tab = (config_t*)malloc(n * sizeof(config_t));
    r->size = n;
    r->current = 0;
    r->max = 0;
    r->nb_v = NB_VEHICULE; 
    
    mouvement_t m = {-1, 0, 0};
    r->tab[0].move = m;
    r->tab[0].prec = -1;

    FILE* f = fopen(filename, "r");

    if (f != NULL)
    {
        int x, y, l;
        char o, v;
        int i = 0;
        while (fscanf(f,"%d %d %d %c %c",&x, &y, &l, &o, &v) != EOF)
        {
            r->tab[0].pos_v[i].ligne = x;
            r->tab[0].pos_v[i].colonne = y;
            r->tab[0].pos_v[i].longeur = l;
            r->tab[0].pos_v[i].orientation = o;
            r->tab[0].pos_v[i].nom = v;
            i++;
        }
        fclose(f);
    }

    return r;
}

void deallocate(rush_hour_t* r)
{
    free(r->tab);
    r->tab = NULL;
    free(r);
    r = NULL;   
} 

grille_t create_grid(rush_hour_t* r)
{
    grille_t grid;

    for (int i = 0; i < SIZE_G; i++)
    {
        for (int j = 0; j < SIZE_G; j++)
            grid.g[i][j] = '.';
    }
    

    for (int i = 0; i < r->nb_v; i++)
    {    
        int ligne = r->tab[r->current].pos_v[i].ligne;
        int colonne = r->tab[r->current].pos_v[i].colonne;

        for (int j = 0; j < r->tab[r->current].pos_v[i].longeur; j++)
        {
            if (r->tab[r->current].pos_v[i].orientation == 'v')
                grid.g[ligne++][colonne] = r->tab[r->current].pos_v[i].nom;
            else if (r->tab[r->current].pos_v[i].orientation == 'h')
                grid.g[ligne][colonne++] = r->tab[r->current].pos_v[i].nom;     
        }
    }

    return grid;
}

void print(rush_hour_t* r, int size_g)
{
    grille_t grid = create_grid(r);
    printf("+------+\n");
    for (int i = 0; i < SIZE_G; i++)
    {
        printf("|");
        for (int j = 0; j < SIZE_G; j++)
            printf("%c",grid.g[i][j]);

        printf("|\n");  
    }
    printf("+------+\n");
    
}

config_t* move(rush_hour_t* r, int k, direction_t d, int l)
{
    grille_t grid = create_grid(r);
    config_t* c = (config_t*)malloc(sizeof(config_t));
    c->prec = r->tab[r->current].prec + 1;
    mouvement_t m = {k, d, l};
    c->move = m;
    for (int i = 0; i < r->nb_v; i++)
        c->pos_v[i] = r->tab[r->current].pos_v[i];
    
    int x = r->tab[r->current].pos_v[k].ligne;
    int y = r->tab[r->current].pos_v[k].colonne;
    int lv = r->tab[r->current].pos_v[k].longeur;

    if (r->tab[r->current].pos_v[k].orientation == 'h' && (d == D || d == G))
    {
        if (d == D)
        {
            y += lv;
            for (int j = 0; j < l; j++)
            {
                if (y + j > SIZE_G)
                    if (grid.g[x][y + j] != '.')
                        return NULL;              
            }
            c->pos_v[k].colonne += l;    
        }else
        {
            y -= 1;
            for (int j = 0; j < l; j++)
            {
                if (y + j >= 0)
                    if (grid.g[x][y + j] != '.')
                        return NULL;         
            }
            c->pos_v[k].colonne -= l;  
        }
    }else if (r->tab[r->current].pos_v[k].orientation == 'v' && (d == H || d == B))
    {
        if (d == H)
        {
            x -= 1;
            for (int i = 0; i < l; i++)
            {
                if (x - i <= 0)
                    if (grid.g[x - i][y] != '.')
                        return NULL;              
            }
            c->pos_v[k].ligne -= l;     
        }else
        {
            x += lv;
            for (int i = 0; i < l; i++)
            {
                if (x + i >= 0)
                    if (grid.g[x + i][y] != '.')
                        return NULL;           
            }
            c->pos_v[k].ligne += l;  
        }

    }else return NULL;

    return c;
    
}



int main()
{
    int n = 20;
    rush_hour_t* r = allocate("rush1.txt", n);

    for (int i = 0; i < 5; i++)
    {
        printf("Vehicule %c : pos {%d %d}, longeur : %d, orientation : %c\n", r->tab[0].pos_v[i].nom, r->tab[0].pos_v[i].ligne, r->tab[0].pos_v[i].colonne, r->tab[0].pos_v[i].longeur, r->tab[0].pos_v[i].orientation);
    }
    printf("\n");

    print(r, SIZE_G);

    config_t* conf = move(r, 1, D, 2);
   
    r->tab[0] = *conf;

    print(r, SIZE_G);
    
    return 0;
}