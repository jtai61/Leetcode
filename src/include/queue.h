#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "basic_define.h"

#define ARRAY           ( 1 )
#define LINKED_LIST     ( 2 )
#define QUEUE_METHOD    ( ARRAY )

#define SIZE    ( 10 )

typedef int Item;

#if ( QUEUE_METHOD == LINKED_LIST )

typedef struct node
{
    Item data;
    struct node *next;
} Node;

typedef struct queue
{
    u32 length;
    Node *front;
    Node *rear;
} Queue;

#else

typedef struct queue
{
    Item data[SIZE];
    int front;
    int rear;
} Queue;

#endif

Queue *queue_init(void);
bool queue_empty(Queue *);
bool queue_full(Queue *);
void queue_push(Queue *, Item);
Item queue_pop(Queue *);
void queue_destroy(Queue *);
void queue_print(Queue *);

#endif