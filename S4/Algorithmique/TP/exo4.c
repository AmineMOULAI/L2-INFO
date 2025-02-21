#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int v;
    struct list* next;

}node;

typedef struct 
{
    node* t;
    int n;
    
}list_node;

node* ajouter(node* h, int val)
{
    node* tmp = (node*)malloc(sizeof(node));
    tmp->v = val;
    tmp->next = NULL;
    if (h != NULL)
    {
        node* p = h;
        while (p->next != NULL && p != NULL)
            p = p->next;
        
        p->next = tmp;

        return h;
    }

    return tmp;
}

int main()
{
    int n = 10;
    
    return 0;
}