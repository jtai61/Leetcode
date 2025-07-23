#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

/* singly linked list node structure */
typedef struct ListNode
{
    int data;
    struct ListNode *next;
} ListNode;

/* doubly linked list node structure */
typedef struct ListNode2
{
    int data;
    struct ListNode2 *prev;
    struct ListNode2 *next;
} ListNode2;

void print_list(ListNode *);
void add_to_sorted_list(ListNode **, int);
void delete_from_list(ListNode **, int);
void reverse_list(ListNode **);
void delete_from_doubly_linked_list(ListNode2 **, int);
void add_to_sorted_doubly_linked_list(ListNode2 **, int);


#endif