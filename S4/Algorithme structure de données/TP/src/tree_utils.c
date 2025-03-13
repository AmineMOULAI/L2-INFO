#include <stdio.h>
#include <stdlib.h>
#include "tree_utils.h"

/* 
    * max
    * create_node
    * tree_height
    * nb_node
    * insert_pbt_node
    * insert_bst_node
    * create_pbt
    * create_bst
    * pre_order
    * in_order
    * post_ordre
    * indentation_display
    * print_node
    * tournement    
*/

int* create_array(int n)
{
    int* array = (int*)malloc(n * sizeof(int));    
    int max = 100, min = 0;
    
    for (int i = 0; i < n; i++)
        array[i] = rand() % (max - min + 1);

    return array;
    
}

int m(int a, int b)
{
     return (a > b) ? a : b;
}

node_t* create_node(int val)
{
    node_t* new = (node_t*)malloc(sizeof(node_t));
    new->val = val;
    new->left = NULL;
    new->right = NULL;
    return new;
}

int tree_height(tree_t A)
{
    if(A == NULL) return -1;
    else return 1 + tree_height(A->left) + tree_height(A->right);
}

int nb_node(tree_t A)
{
    if (A = NULL) return 0;
    else return 1 + nb_node(A->left) + nb_node(A->right);
}

/*void insert_pbt_node(tree_t* A, int val)
{
    if (*A == NULL)
    {
        node_t* new = create_node(val);
        *A = new;
    }
    
}*/


void insert_bst_node(tree_t* A, int val)
{
    if (*A == NULL)
    {
        node_t* new = create_node(val);
        *A = new;
    }
    else if(val > (*A)->val) insert_bst_node(&(*A)->right, val);
    else if(val < (*A)->val) insert_bst_node(&(*A)->left, val);
}

tree_t* create_bst(int* array, int n)
{
    tree_t* tree = (tree_t*)malloc(sizeof(tree_t));
    for (int i = 0; i < n; i++)
        insert_bst_node(tree, array[i]);
    return tree;
}

void pre_order(tree_t A)
{
    if (A != NULL)
    {
        printf("%d ", A->val);
        pre_order(A->left);
        pre_order(A->right);
    }
}

void in_order(tree_t A)
{
    if (A != NULL)
    {
        in_order(A->left);
        printf("%d ", A->val);
        in_order(A->right);
    }
}

void post_ordre(tree_t A)
{
    if (A != NULL)
    {
        post_ordre(A->left);
        post_ordre(A->right);
        printf("%d ", A->val);
    }
}