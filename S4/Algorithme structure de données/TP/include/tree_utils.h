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
        int* data;
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
    stack_t* push(stack_t* s, int v);
    int pop(stack_t* s);





#endif