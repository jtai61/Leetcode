#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "basic_define.h"

#define ARRAY           ( 1 )
#define LINKED_LIST     ( 2 )
#define STACK_METHOD    ( ARRAY )

#define SIZE    ( 10 )

typedef int Item;

#if ( STACK_METHOD == LINKED_LIST )

typedef struct node
{
    Item data;
    struct node *next;
} Node;

typedef struct stack
{
    u32 length;
    Node *top;
} Stack;

#else

typedef struct stack
{
    Item data[SIZE];
    int top;
} Stack;

#endif

Stack *stack_init(void);
bool stack_empty(Stack *);
void stack_push(Stack *, Item);
Item stack_pop(Stack *);
void stack_destroy(Stack *);
void stack_print(Stack *);

#endif