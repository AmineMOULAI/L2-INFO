#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int v;
    struct list* next;

}node;

typedef struct 
{
    node** t;
    int n;
    
}list_node;

node* create_node(int v)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->v = v;
    new_node->next = NULL;
    return new_node;
}
node* ajouter(node* h, int val)
{
    node* tmp = (node*)malloc(sizeof(node));
    tmp->v = val;
    tmp->next = NULL;
    if (h != NULL)
    {
        node* p = h;
        while (p != NULL)
            p = p->next;
        
        p->next = tmp;

        return h;
    }

    return tmp;
}

int main()
{
    int n = 10;
    list_node* tab_fils = (list_node*)malloc(sizeof(list_node));
    tab_fils->t = (node**)malloc(n * sizeof(node*)); 
  
    tab_fils->t[0] = create_node(2);
    tab_fils->t[0]->next = create_node(3);
    tab_fils->t[0]->next->next = create_node(4);
    tab_fils->t[1] = create_node(5);
    tab_fils->t[1]->next = create_node(6);
    tab_fils->t[2] = create_node(7);
    tab_fils->t[2]->next = create_node(8);
    tab_fils->t[3] = create_node(9);
    int i = 4;
    while(i < n) 
    {
        tab_fils->t[i] = NULL;
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        node* p = tab_fils->t[i];
        while (p != NULL)
        {
            printf("%d ", p->v);
            p = p->next;
        }
        printf("NULL\n");
    }
    
    return 0;
}