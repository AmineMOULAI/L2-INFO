#include <stdio.h>
#include <stdlib.h>
#include "tree_utils.h"

/* 
    * create_array
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
    * init_stack
    * is_empty 
    * push
    * pop
    * pre_order_non_rec
    * in_order_non_rec
    * post_order_non_rec
    * is_heap
    * rise
    * sink
    * heap_sort
    * init_queue
    * is_empty_queue
    * is_full_queue
    * BFS
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
    else return 1 + m(tree_height(A->left), tree_height(A->right));
}

int nb_node(tree_t A)
{
    if (A == NULL) return 0;
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

void pre_order(tree_t* A)
{
    if ((*A) != NULL)
    {
        printf("%d ", (*A)->val);
        pre_order(&(*A)->left);
        pre_order(&(*A)->right);
    }
}

void in_order(tree_t* A)
{
    if (*A != NULL)
    {
        in_order(&(*A)->left);
        printf("%d ", (*A)->val);
        in_order(&(*A)->right);
    }
}

void post_ordre(tree_t* A)
{
    if (*A != NULL)
    {
        post_ordre(&(*A)->left);
        post_ordre(&(*A)->right);
        printf("%d ", (*A)->val);
    }
}

void indentation_display_rec(tree_t A, int i, int height)
{
    if (A != NULL)
    {
        for (int j = 0; j < i; j++)
            printf("  ");
        printf("%d\n", A->val);
        indentation_display_rec(A->left, height - tree_height(A->left), height);
        indentation_display_rec(A->right, height - tree_height(A->left), height);
    }
    
}

void indentation_display(tree_t A, int i, int height)
{
    indentation_display_rec(A, 0, height);
}

tree_t tournement(int* t, int l, int r)
{
    int m = (l + r) / 2;
    tree_t p = create_node(t[m]);
    if (l == r) return p;
    tournement(t, l, m);
    tournement(t, m + 1, r);
    int u = p->left->val;
    int v = p->right->val;
    p->val = (u > v) ? u : v;
    return p;
}

stack_t* init_stack(int capacity)
{
    stack_t* s = (stack_t*)malloc(sizeof(stack_t));
    if(s != NULL)
    {
        s->data = (tree_t*)malloc(capacity * sizeof(tree_t));
        s->top = -1;
        s->capacity = capacity;
    }
    return s;
}

int is_empty(stack_t* s)
{
    return s->top == -1;
}

int is_full(stack_t* s)
{
     return s->top == s->capacity - 1;
}

void push(stack_t* s, tree_t v)
{
    if (is_full(s)) return;
    else s->data[++s->top] = v;
}

tree_t pop(stack_t* s)
{
    if (is_empty(s))
    {
        printf("Can't pop !");
        exit(1);
    }
    return s->data[s->top--];
}

void pre_order_non_rec(tree_t root, int node)
{
    if (root == NULL)
    {
        printf("Tree is empty !\n");
        return;
    }
    
    stack_t* s = init_stack(node);
    tree_t current = root;

    push(s, current);
    while(!is_empty(s))
    {
        current = pop(s);
        printf("%d ", current->val);
        if(current->right != NULL)
            push(s, current->right);
        if (current->left != NULL)
            push(s, current->left);
    }
    free(s->data);
    free(s);
}

void in_order_non_rec(tree_t root, int node)
{
    if(root == NULL)
    {
        printf("Tree is empty !\n");
        return;
    }

    stack_t *s = init_stack(node);
    tree_t current = root;

    while (current != NULL || !is_empty(s))
    {
        while (current != NULL)
        {
            push(s, current);
            current = current->left;
        }
        
        current = pop(s);
        printf("%d ", current->val);
        current = current->right;
    }
    free(s->data);
    free(s);
}

void post_order_non_rec(tree_t root, int node)
{
    if(root == NULL) return;

    stack_t* s1 = init_stack(node);
    stack_t* s2 = init_stack(node);

    tree_t current;
    push(s1, root);

    while (!is_empty(s1))
    {
        current = pop(s1);
        push(s2, current);
        if (current->left != NULL)
            push(s1, current->left);
        if (current->right != NULL)
            push(s1, current->right);
    }
    while (!is_empty(s2))
    {
        current = pop(s2);
        printf("%d ", current->val);
    }
}

int is_heap(int heap[], int n)
{
    for (int i = 0; i < (n - 2) / 2; i++)
    {
        if (i < i * 2 + 1 && heap[i] < heap[i * 2 + 1]) return 0;
        if (i < i * 2 + 2 && heap[i] < heap[i * 2 + 2]) return 0;
    }
    return 1;
}

void rise(int heap[], int i, int v)
{
    int x = heap[i] + v;
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (heap[parent] >= x) break;
        heap[i] = heap[parent];
        i = parent;
    }
    heap[i] = x;
}

void sink(int heap[], int n, int i)
{
    int x = heap[i];
    int j = 2 * i + 1;

    while(j < n)
    {
        if(j + 1 < n && heap[j] < heap[j + 1]) j++;

        if(x >= heap[j]) break;
        heap[i] = heap[j];
        i = j;
        j = 2 * i + 1;   
    }
    heap[i] = x;
}

void heap_sort(int heap[], int n)
{
    if (n > 1)
    {
        int tmp = heap[n - 1];
        heap[n - 1] = heap[0];
        heap[0] = tmp;

        sink(heap, n - 1, 0);
        heap_sort(heap, n - 1);
    }
}

// Queues 

queue_t* init_queue(int size)
{
    queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
    
    if (queue != NULL)
    {
        queue->data = (tree_t*)malloc(size * sizeof(tree_t));
        queue->front = 0;
        queue->rear = 0;
        queue->size = size;
    }
    return queue;   
}

int is_empty_queue(queue_t* queue)
{
    return queue->front == queue->rear;
}

int is_full_queue(queue_t* queue)
{
    return ((queue->rear + 1) % queue->size) ==  queue->front;
}

void enqueue(queue_t* q, tree_t t)
{
    if (is_full_queue(q))
    {
        printf("Error ! Queue is full !\n");
        return;
    }
    q->data[q->rear] = t;
    q->rear = (q->rear + 1) % q->size;
}

tree_t dequeue(queue_t* q)
{
    if (is_empty_queue(q))
    {
        printf("Error ! Queue is empty !\n");
        exit(1);
    }
    tree_t tmp = q->data[q->front];
    q->front = (q->front + 1) % q->size;
    return tmp;
}

void display_queue(queue_t* q)
{
    int p = q->front;
    while(p < q->rear)
        printf("%d ", q->data[p++]->val);
    printf("\n");
}   

void BFS(tree_t root)
{
    int nb = nb_node(root);
    queue_t* queue = init_queue(nb);
    enqueue(queue, root);

    while(!is_empty_queue(queue))
    {
        tree_t p = dequeue(queue);
        printf("%d ", p->val);

        if(p->left != NULL) enqueue(queue, p->left);
        if(p->right != NULL) enqueue(queue, p->right);
    }
    printf("\n");
}

