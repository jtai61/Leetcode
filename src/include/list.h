#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#define SINGLY_LINKED_LIST      ( 1 )
#define DOUBLY_LINKED_LIST      ( 2 )
#define LINKED_LIST_METHOD      ( SINGLY_LINKED_LIST )

typedef int Item;

#if ( LINKED_LIST_METHOD == SINGLY_LINKED_LIST )

typedef struct ListNode
{
    Item data;
    struct ListNode *next;
} ListNode;

#else

typedef struct ListNode
{
    Item data;
    struct ListNode *left;
    struct ListNode *right;
} ListNode;

#endif

typedef struct _List
{
    ListNode *head;
} List;

List *list_init(void);
void list_destroy(List *);
int list_length(List *);
void sorted_list_push(List *, Item);
void list_pop(List *, Item);
void list_reverse(List *);
List *sorted_list_merge(List *, List *);

#endif