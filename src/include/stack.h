#ifndef STACK_H
#define STACK_H

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

Stack *stack_create(void);
bool stack_empty(Stack *);
void stack_push(Stack *, Item);
Item stack_pop(Stack *);
void stack_destroy(Stack *);
void stack_print(Stack *);

#endif