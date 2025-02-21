#ifdef ARBRE_UTILS
#define ARBRE_UTILS

    typedef struct node_t
    {
        int val;
        struct node_t *FG, *FD;
    }node_t;

    typedef node_t* tree_t;
    node_t* create_node(int v);
#endif

    


    