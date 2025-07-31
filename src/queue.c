#include "queue.h"

Queue *queue_create(void)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));

    q->front = NULL;
    q->back = NULL;

    return q;
}

bool queue_empty(Queue *q)
{
    if (q->front == NULL && q->back == NULL)
        return true;
    else
        return false;
}

void queue_push(Queue *q, Item i)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->data = i;
    new_node->next = NULL;

    if (queue_empty(q))
    {
        q->front = new_node;
    }
    else
    {
        q->back->next = new_node;
    }

    q->back = new_node;
}

Item queue_pop(Queue *q)
{
    if (queue_empty(q))
    {
        printf("Error: queue is empty.\n");
        exit(EXIT_FAILURE);
    }
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

void queue_destroy(Queue *q)
{
    while (!queue_empty(q))
        queue_pop(q);
    
    free(q);
}

void queue_print(Queue *q)
{
    for (Node *p = q->front; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}
