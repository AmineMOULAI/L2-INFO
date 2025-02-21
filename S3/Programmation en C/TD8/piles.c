#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

}node;

typedef struct 
{
    node *top;
}stack;

stack* createStack()
{
    stack *s = (stack*)malloc(sizeof(stack));

    s->top = NULL;

    return s;
}

void push(stack* s, int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = s->top;  // Le nouveau nœud pointe vers l'ancien sommet
    s->top = newNode;        // Mettre à jour le sommet
}

int pop(stack* s)
{
    if (s->top == NULL)
    {
        printf("Stack underflow !");
        return -1;
    }

    node *tmp = s->top;
    int poppedV = tmp->data;
    s->top = tmp->next;
    free(tmp);

    return poppedV;   
}

void displayStack(stack *s)
{
    node *p = s->top;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main()
{
    stack *s = createStack();
    int v;

    push(s, 2);
    push(s, 3);
    push(s, 4);
    displayStack(s);
    v = pop(s);
    printf("Popped Value : %d\n", v);
    displayStack(s);


    

    return 0;
}