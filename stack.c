#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;

typedef struct node
{
    Item data;
    struct node *next;
} Node;

typedef struct stack
{
    Node *top;
} Stack;

Stack *create(void);
void destroy(Stack *);
void make_empty(Stack *);
bool is_empty(Stack *);
void push(Stack *, Item);
Item pop(Stack *);
void print_stack(Stack *);

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack *create(void)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));

    s->top = NULL;

    return s;
}

void destroy(Stack *s)
{
    make_empty(s);
    free(s);
}

void make_empty(Stack *s)
{
    while (!is_empty(s))
        pop(s);
}

bool is_empty(Stack *s)
{
    if (s->top == NULL)
        return true;
    else
        return false;
}

void push(Stack *s, Item i)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    
    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
}

Item pop(Stack *s)
{
    if (is_empty(s))
        terminate("Error in pop: stack is empty.");
    else
    {
        Node *target = s->top;
        Item i = target->data;
        s->top = s->top->next;
        free(target);
        return i;
    }
}

void print_stack(Stack *s)
{
    for (Node *p = s->top; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

int main(void)
{
    Stack *s1;
    Item n;

    s1 = create();

    push(s1, 1);
    push(s1, 2);
    push(s1, 5);
    // push(s1, 2);
    print_stack(s1);

    n = pop(s1);
    printf("Popped %d from s1\n", n);

    n = pop(s1);
    printf("Popped %d from s1\n", n);

    push(s1, 36);
    push(s1, 294);

    n = pop(s1);
    printf("Popped %d from s1\n", n);

    n = pop(s1);
    printf("Popped %d from s1\n", n);

    print_stack(s1);

    destroy(s1);

    return 0;
}
