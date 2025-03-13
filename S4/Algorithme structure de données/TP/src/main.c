#include <stdio.h>
#include <stdlib.h>
#include <tree_utils.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    
    int n;
    printf("Insert n : ");
    scanf("%d", &n);
    int* array = create_array(n);
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
    
    tree_t* A = create_bst(array, n);
    printf(" %d\n",(*A)->val);
    printf("%d %d\n",(*A)->left->val, (*A)->right->val);
    /*pre_order(A);
    printf("\n");
    in_order(A);
    printf("\n");
    post_ordre(A);
    printf("\n");
    */
}