#include <stdio.h>
#include <stdlib.h>
#include <tree_utils.h>
#include <time.h>
#include <assert.h>
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
    /*
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
    /*int c = 10;
    stack_t* s = init_stack(c);
    tree_t t = create_node(5);
    push(s, t);

    tree_t t1 = create_node(10);
    push(s, t1);

    printf("%d\n%d\n", s->data[s->top]->val, s->data[s->top - 1]->val);*/
    /*
    int n;
    printf("Insert n : ");
    scanf("%d", &n);
    int* array = create_array(n);
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
  
    tree_t* A = create_bst(array, n);
    int nb = nb_node(*A);
    printf("%d\n", nb);
    pre_order_non_rec(*A, nb);
    printf("\n");
    pre_orer(A);
    printf("\n");
    in_order_non_rec(*A, nb);
    printf("\n");
    in_order(A);
    printf("\n");
    printf("Post-order : ");
    post_order_non_rec(*A, nb);
    printf("\n");
    printf("Post-order : ");
    post_ordre(A);
    printf("\n");*/

    /*// create heap 
    int heap[10] = {90, 89, 67, 78, 45, 34, 56, 23, 12, 11};
    assert(!is_heap(array, n));
    assert(is_heap(heap, 10));
    printf("Heap : ");
    for (int i = 0; i < n; i++)
        printf("%d ", heap[i]);
    printf("\n");
    
    // rise
    int indx = 8, val = 100;
    rise(heap, indx, val);

    printf("Rise :\nNew heap : ");
    for (int i = 0; i < n; i++)
        printf("%d ", heap[i]);
    printf("\n");
    
    // sink 
    int h[10] = {90, 89, 67, 78, 2, 34, 56, 23, 12, 11};
    indx = 4;
    sink(h, n, indx);

    printf("Sink :\nNew heap : ");
    for (int i = 0; i < n; i++)
        printf("%d ", h[i]);
    printf("\n");
    
    // heap sort

    heap_sort(heap, n);
     printf("Heap sorted : ");
    for (int i = 0; i < n; i++)
        printf("%d ", heap[i]);
    printf("\n");
    */

    tree_t s = create_node(2);
    tree_t s1 = create_node(4);
    tree_t s2 = create_node(5);
    tree_t s3 = create_node(8);
    queue_t* q = init_queue(10);
    enqueue(q, s);
    enqueue(q, s1);
    enqueue(q, s2);
    enqueue(q, s3);
    printf("front : %d, rear : %d, size : %d\n", q->front, q->rear, q->size);
    printf("Before : ");
    display_queue(q);
    tree_t d = dequeue(q);
    tree_t d1 = dequeue(q);
    printf("After : ");
    display_queue(q);
    BFS(*A);
   
}