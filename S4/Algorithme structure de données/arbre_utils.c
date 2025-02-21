#include <stdio.h>
#include <stdlib.h>
#include "arbre_utils.h"


typedef struct node_t
{
    int val;
    struct node_t *FG, *FD;
}node_t;


typedef node_t* tree_t;


node_t* create_node(int val)
{
    node_t* n = (node_t*)malloc(sizeof(node_t));
    n->val = val;
    n->FG = NULL;
    n->FD = NULL;

    return n;
}
int max(int a, int b)
{
    if (a > b) return a;
    else return b;
    
}
int height_tree(tree_t A)
{
    if (A == NULL) return -1;
    else{
        return 1 + max(height_tree(A->FG), height_tree(A->FD));
    }
    
}

/*void insert_node(tree_t* A, int val)
{
    node_t* node = create_node(val);

    if (*A == NULL)
    {
        *A = node;
    }
    
}*/

void prefixe(tree_t A)
{
    if (A != NULL)
    {
        printf("%d ", A->val);
        prefixe(A->FG);
        prefixe(A->FD);
    }
    
}

void infixe(tree_t A)
{
    if(A != NULL)
    {
        infixe(A->FG);
        printf("%d ", A->val);
        infixe(A->FD);
    }
}

void postfixe(tree_t A)
{
    if (A != NULL)
    {
        postfixe(A->FG);
        postfixe(A->FD);
        printf("%d ", A->val);
    }   
}

int main()
{
    return 0;
}