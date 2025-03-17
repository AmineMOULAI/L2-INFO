#include <stdio.h>
#include <stdlib.h>
#include <tree_utils.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    
    /*int n;
    printf("Insert n : ");
    scanf("%d", &n);
    int* array = create_array(n);
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
    
    tree_t* A = create_bst(array, n);
    printf("Pre-order : ");
    pre_order(A);
    printf("\n");

    printf("In-order : ");
    in_order(A);
    printf("\n");

    printf("Post-order : ");
    post_ordre(A);
    printf("\n");
    int h = tree_height(*A);
    indentation_display_rec(*A, 0, h);
    printf("\n");

    int n;
    printf("Insert n : ");
    scanf("%d", &n);

    int* array = create_array(n);

    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    tree_t A = tournement(array, 0, n);*/
    int c = 10;
    stack_t* s = init_stack(c);
    for (int i = 0; i < s->capacity; i++)
        s = push(s, i + 1);
    for (int i = 0; i < s->capacity; i++)
       printf("%d ", s->data[i]);
    printf("\n"); 

    int v = pop(s);
    printf("%d\n", v);
    for (int i = 0; i < s->capacity; i++)
       printf("%d ", s->data[i]);
    printf("\n"); 
    
}