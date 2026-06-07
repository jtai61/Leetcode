#include "queue.h"

#if ( METHOD == LINKED_LIST )

Queue *queue_init(void)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));

    q->length = 0;
    q->front = NULL;
    q->rear = NULL;

    return q;
}

bool queue_empty(Queue *q)
{
    if (q->length == 0 && q->front == NULL && q->rear == NULL)
        return true;
    else
        return false;
}

bool queue_full(Queue *q)
{
    if (q->length == SIZE)
        return true;
    else
        return false;
}

void queue_push(Queue *q, Item i)
{
    if (queue_full(q))
    {
        printf("Error: queue is full.\n");
        return;
    }
    
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->data = i;
    new_node->next = NULL;

    if (queue_empty(q))
    {
        q->front = new_node;
    }
    else
    {
        q->rear->next = new_node;
    }
    q->rear = new_node;
    q->length++;
}

Item queue_pop(Queue *q)
{
    if (queue_empty(q))
    {
        printf("Error: queue is empty.\n");
        return;
    }

    Node *target = q->front;
    Item i = target->data;

    q->length--;
    q->front = q->front->next;

    if (q->length == 0 && q->front == NULL)
        q->rear = NULL;
    
    free(target);

    return i;
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

#else   // METHOD == ARRAY

Queue *queue_init(void)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));

    q->front = -1;
    q->rear = -1;

    return q;
}

bool queue_full(Queue *q)
{
    if (q->front == ((q->rear + 1) % SIZE))
        return true;
    else
        return false;
}

bool queue_empty(Queue *q)
{
    if (q->front == -1 && q->rear == -1)
        return true;
    else
        return false;
}

void queue_push(Queue *q, Item i)
{
    if (queue_full(q))
    {
        printf("Error: queue is full.\n");
        return;
    }
    
    q->rear = (q->rear + 1) % SIZE;
    q->data[q->rear] = i;

    if (q->front == -1) // First push
    {
        q->front = q->rear;
    }
}

Item queue_pop(Queue *q)
{
    if (queue_empty(q))
    {
        printf("Error: queue is empty.\n");
        return;
    }
    
    Item target = q->data[q->front];

    if (q->front == q->rear)    // Only one element
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % SIZE;
    }

    return target;
}

#endif