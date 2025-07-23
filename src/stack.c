#include "stack.h"

Stack *stack_create(void)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));

    s->top = NULL;

    return s;
}

bool stack_is_empty(Stack *s)
{
    if (s->top == NULL)
        return true;
    else
        return false;
}

void stack_make_empty(Stack *s)
{
    while (!is_empty(s))
        pop(s);
}

void stack_destroy(Stack *s)
{
    make_empty(s);
    free(s);
}

void stack_push(Stack *s, Item i)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    
    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
}

Item stack_pop(Stack *s)
{
    if (is_empty(s))
    {
        printf("Error in pop: stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        Node *target = s->top;
        Item i = target->data;
        s->top = s->top->next;
        free(target);
        return i;
    }
}

void stack_print(Stack *s)
{
    for (Node *p = s->top; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}
