#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct ListNode
{
    Item data;
    struct ListNode *next;
} ListNode;

typedef struct _List
{
    ListNode *head;
} List;

void sorted_list_push(List *, Item);
void list_pop(List *, Item);
void list_reverse(List *);

#endif