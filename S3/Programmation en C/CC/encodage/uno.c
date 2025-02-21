#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    BLUE,
    ROUGE,
    JAUNE,
    VERT
}color_t;

typedef enum
{
    NUM,
    PLUS_TWO,
    INVERSION,
    PASSE,
    JOKER,
    PLUS_FOUR
}type_t;

typedef struct card 
{
    color_t color;
    type_t type;
    int value;
    struct card *next;

}card_t;

card_t* insere_card(card_t* c, int v, color_t color, type_t t)
{
    card_t* c_tmp = (card_t*)malloc(sizeof(card_t));
    c_tmp->color = color;
    c_tmp->type = t;
    c_tmp->value = v;

    if (c == NULL)
        c_tmp->next = c;
    c = c_tmp;

    return c;
}

card_t* search_card(card_t* c ,int v, color_t color, type_t t)
{
    card_t* p = c;

    while (p != NULL)
    {
        if (p->value == v && p->color == color && c->type == t)
            return p;
        p = p->next;
    }
    return NULL; 
}

card_t* delete_card(card_t* c, int v, color_t color, type_t t)
{
    if (c == NULL) return NULL;
    
}


int main()
{
    card_t* c = NULL;

    return 0;
}