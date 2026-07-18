#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#define SINGLY_LINKED_LIST      ( 1 )
#define DOUBLY_LINKED_LIST      ( 2 )
#define LINKED_LIST_METHOD      ( SINGLY_LINKED_LIST )

#if ( LINKED_LIST_METHOD == SINGLY_LINKED_LIST )

struct ListNode
{
    int val;
    struct ListNode *next;
};

#else

typedef struct ListNode
{
    Item data;
    struct ListNode *left;
    struct ListNode *right;
} ListNode;

#endif

struct ListNode *sorted_list_push(struct ListNode *, int);
struct ListNode *reverseList(struct ListNode *);
struct ListNode *mergeTwoLists(struct ListNode *, struct ListNode *);
struct ListNode *deleteDuplicates(struct ListNode *);
struct ListNode *removeElements(struct ListNode *, int);
struct ListNode *middleNode(struct ListNode *);

#endif