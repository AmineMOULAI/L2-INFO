#ifndef TREE_UTILS
#define TREE_UTILS

    typedef struct node_t 
    {
        int val;
        struct node_t *left, *right;
    }node_t;
    
    typedef node_t* tree_t;

    typedef struct stack_t
    {
        tree_t* data;
        int capacity, top;
    }stack_t;

    int* create_array(int n);
    node_t* create_node(int val);
    int tree_height(tree_t A);
    int nb_node(tree_t A);
    //void insert_pbt_node(tree_t* A, int val);
    void insert_bst_node(tree_t* A, int val);
    tree_t* create_bst(int* array, int n);
    void pre_order(tree_t* A);
    void in_order(tree_t* A);
    void post_ordre(tree_t* A);
    void indentation_display_rec(tree_t A, int i, int height);
    void indentation_display(tree_t A, int i, int height);
    tree_t tournement(int* t, int l, int r);
    stack_t* init_stack(int capacity);
    int is_empty(stack_t* s);
    int is_full(stack_t* s);
    void push(stack_t* s, tree_t v);
    tree_t pop(stack_t* s);
    void pre_order_non_rec(tree_t root, int nb_node);
    void in_order_non_rec(tree_t root, int nb_node);
    void post_order_non_rec(tree_t root, int nb_node);
    int is_heap(int array[], int n);
    void rise(int heap[], int i, int v);
    void sink(int heap[], int n, int i);
    void heap_sort(int heap[], int n);

    
    typedef struct queue
    {
        tree_t* data;
        int front;
        int rear;
        int size;  
    }queue_t;
    
    queue_t* init_queue(int size);
    int is_empty_queue(queue_t* queue);
    int is_full_queue(queue_t* queue);
    void enqueue(queue_t* q, tree_t t);
    tree_t dequeue(queue_t* q);
    void display_queue(queue_t* q);
    void BFS(tree_t root);










#endif