#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;

typedef struct node
{
    Item data;
    struct node *next;
} Node;

typedef struct queue
{
    Node *front;
    Node *back;
} Queue;

Queue *create(void);
void destroy(Queue *);
void make_empty(Queue *);
bool is_empty(Queue *);
void push(Queue *, Item);
Item pop(Queue *);
unsigned int get_size(Queue *);
Item get_front(Queue *);
Item get_back(Queue *);
void print_element(Queue *);

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue *create(void)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));

    q->front = NULL;
    q->back = NULL;

    return q;
}

void destroy(Queue *q)
{
    make_empty(q);
    free(q);
}

void make_empty(Queue *q)
{
    while (!is_empty(q))
        pop(q);
}

bool is_empty(Queue *q)
{
    if (q->front == NULL && q->back == NULL)
        return true;
    else
        return false;
}

void push(Queue *q, Item i)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->data = i;
    new_node->next = NULL;

    if (is_empty(q))
    {
        q->front = new_node;
    }
    else
    {
        q->back->next = new_node;
    }

    q->back = new_node;
}

Item pop(Queue *q)
{
    if (is_empty(q))
        terminate("Error: queue is empty.");
    else
    {
        Node *target = q->front;
        Item i = target->data;

        q->front = q->front->next;

        if (q->front == NULL)
            q->back = NULL;
        
        free(target);
        return i;
    }
}

unsigned int get_size(Queue *q)
{
    unsigned int count = 0;

    for (Node *p = q->front; p != NULL; p = p->next)
    {
        count++;
    }
    
    return count;
}

Item get_front(Queue *q)
{
    if (is_empty(q))
        terminate("Error: queue is empty.");
    else
        return q->front->data;
}

Item get_back(Queue *q)
{
    if (is_empty(q))
        terminate("Error: queue is empty.");
    else
        return q->back->data;
}

void print_element(Queue *q)
{
    for (Node *p = q->front; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

int main()
{
    Queue *q1;
    Item n;

    q1 = create();

    push(q1, 10);
    push(q1, 13);
    push(q1, 5);
    push(q1, 78);
    push(q1, 55);

    print_element(q1);

    printf("front: %d\n", get_front(q1));
    printf(" back: %d\n", get_back(q1));
    printf(" size: %d\n", get_size(q1));




    destroy(q1);


    return 0;
}
