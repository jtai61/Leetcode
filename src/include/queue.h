#ifndef QUEUE_H
#define QUEUE_H

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

Queue *queue_create(void);
bool queue_empty(Queue *);
void queue_push(Queue *, Item);
Item queue_pop(Queue *);
void queue_destroy(Queue *);
void queue_print(Queue *);

#endif