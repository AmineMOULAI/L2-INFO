#include <stdio.h>
#include <stdlib.h>

// Direction de mouvement 
typedef enum
{
    H,
    B,
    G,
    D
}direction;

// Mouvement 
typedef struct 
{
    char v;
    int l;
    direction d;
}mouvement;

// Vehicule 
typedef struct 
{
    int ligne, colonne;
    int longeur;
    char orientation;    
    char nom;
}vehicule;

// Configuration 
typedef struct 
{
    vehicule pos_v[16];
    int prec;
    mouvement move;
}config;

// Rush Hour
typedef struct 
{
    config* tab;
    int size;
    int current;
    int max;
}rush_hour;

// augmenter la taille du tab config
void increase_size(rush_hour* r, int n)
{
    r->tab = (config*)realloc(r->tab, n * (sizeof(config)));
}

//allouer rush hour, lire d'un fichier la config

rush_hour** allocate(char* filename, int n)
{
    rush_hour* r = (rush_hour**)malloc(sizeof(rush_hour));
    r->tab = (config**)malloc(n * sizeof(config));
    r->size = n;
    r->current = 0;
    r->max = 0;

    FILE* f = fopen(filename, "r");

    if (f != NULL)
    {
        int x, y, l;
        char o, v;
        while (fscanf(f,"%d %d %d %c %c",&x, &y, &l, &o, &v) != EOF)
        {
            r->tab->pos_v->ligne= x;
            r->tab->pos_v->colonne = y;
            r->tab->pos_v->longeur = l;
            r->tab->pos_v->orientation = o;
            r->tab->pos_v->nom = v;
        }
        fclose(f);
    }

    return r;
}


int main()
{

    return 0;
}