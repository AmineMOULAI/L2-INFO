#ifndef TREE_UTILS
#define TREE_UTILS

    typedef struct node_t 
    {
        int val;
        struct node_t *left, *right;
    }node_t;
    
    typedef node_t* tree_t;

    int* create_array(int n);
    node_t* create_node(int val);
    int tree_height(tree_t A);
    int nb_node(tree_t A);
    //void insert_pbt_node(tree_t* A, int val);
    void insert_bst_node(tree_t* A, int val);
    tree_t* create_bst(int* array, int n);
    void pre_order(tree_t A);
    void in_order(tree_t A);
    void post_ordre(tree_t A);


#endif