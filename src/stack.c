#include "stack.h"

#if (METHOD == LINKED_LIST)

Stack *stack_init(void)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));

    s->top = NULL;

    return s;
}

bool stack_empty(Stack *s)
{
    if (s->top == NULL)
        return true;
    else
        return false;
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
    if (stack_empty(s))
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

void stack_destroy(Stack *s)
{
    while (!stack_empty(s))
        stack_pop(s);
    
    free(s);
}

void stack_print(Stack *s)
{
    for (Node *p = s->top; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

#else   // METHOD == ARRAY

Stack *stack_init(void)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));

    s->top = -1;

    return s;
}

bool stack_empty(Stack *s)
{
    if (s->top == -1)
        return true;
    else
        return false;    
}

bool stack_full(Stack *s)
{
    if (s->top == (SIZE - 1))
        return true;
    else
        return false;    
}

void stack_push(Stack *s, Item i)
{
    if (stack_full(s))
    {
        printf("Error: stack is full.\n");
        return;
    }
    
    s->data[++s->top] = i;
}

Item stack_pop(Stack *s)
{
    if (stack_empty(s))
    {
        printf("Error: stack is empty.\n");
        return;
    }

    return s->data[s->top--];
}

#endif
