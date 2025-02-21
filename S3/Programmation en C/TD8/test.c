#include <stdio.h>
#include <stdlib.h>

typedef struct list 
{
    int val;
    struct list *next;
}list;

list* insertHead(int v)
{
   list *n = NULL;

    n = (list*) malloc(sizeof(list*));
    n->val = v;
    n->next = NULL;

    return n;
}

list* freeRec(list* l)
{
    list *t = l;
    if (l != NULL)
    {
        t = t->next;
    }
    return t;
}

void display_list(list* h)
{
    list* p = h;

    while (p != NULL)
    {
        printf("%d -> ", p->val);
        p = p->next;
    }

    printf("NULL\n");
}

int sizeList(list *h)
{
    int c = 0;

    list *p = h;

    while (p != NULL)
    {
        p = p->next;
        c++;
    }

    return c;
}

list* searchV(list *h, int v)
{
    list *p = h;
    while (p != NULL)
    {
        if (p->val == v)
            return p;
        p = p->next;
    }

    return NULL;   
}

list* addHead(list *h, int nV)
{
    list *newN = NULL;
    newN = (list*)malloc(sizeof(list));

    newN->val = nV;
    newN->next = NULL;
    if (h != NULL)
        newN->next = h;

    h = newN;
    
    return h;
}

list* addQueue(list *h, int v)
{
    list *newN = NULL;
    newN = (list*)malloc(sizeof(list));

    newN->val = v;
    newN->next = NULL;

    if (h == NULL)
        h = newN;
    list *p = h;
    while (p->next != NULL)
        p = p->next;

    p->next = newN;
    return h;
}

list* add(list* h, int pos, int v)
{
    list* newN = (list*)malloc(sizeof(list));

    newN->val = v;
    newN->next = NULL;

    if (h == NULL)
        return newN;

    int t = sizeList(h);
    if (pos < 1 || pos > t + 1)
    {
        printf("Invalide position !");
        free(newN);
        return h;
    }
    
    if (pos == 1)
    {
        newN->next = h;
        h = newN;
        return h;
    }

    list *p = h;
    int i = 1;
    while (i < pos - 1)
        p = p->next;

    newN->next = p->next;
    p->next= newN;

    return h;
    
}

list* delete(list* h, int pos)
{
    if (h == NULL) return NULL;
    
    int t = sizeList(h);
    if (pos < 1 || pos > t + 1)
    {
        printf("Invalide position !");
        return h;
    }

    list *tmp = h;
    if (pos == 1)
    {
        h = h->next;
        free(tmp);
        return h;
    }
    
    list *p; 
    for (int i = 1; i < pos - 1; i++)
        p = p->next;
        
    tmp = p->next;
    p->next = tmp->next;
    free(tmp);
    return h;
}

int main()
{
    list *h = NULL;
    /*list *a = insertHead(2);
    list *b = insertHead(5);
    list *c = insertHead(10);
    list *d = insertHead(0);
    int val = 5;

    h = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;

    int t = sizeList(h);
    printf("Size = %d\n", t);

    list *res = searchV(h, val);
    if (res != NULL) printf("%d found!\n", val);
    else printf("%d not found !", val);

    h = addHead(h, 8);
    h = addQueue(h, -2);*/
    
    h = add(h, 2, 1);
    h = add(h, 1, 5);
    h = add(h, 2, 6);
    printf("Before : \n");
    display_list(h);
    h = delete(h, 1);
    printf("After : \n");
    display_list(h);


    

    return 0;
}