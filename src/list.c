#include "list.h"

void print_list(ListNode *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void add_to_sorted_list(ListNode **head, int key)
{
    ListNode *cur = *head;
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));

    new_node->data = key;

    /* add to first */
    if (cur == NULL || cur->data > key)
    {
        new_node->next = cur;
        *head = new_node;
    }
    else    /* add to middle or last */
    {
        while (cur->next != NULL && cur->next->data <= key)
        {
            cur = cur->next;
        }
        
        new_node->next = cur->next;
        cur->next = new_node;
    }
}

void delete_from_list(ListNode **head, int n)
{
    ListNode *cur, *prev;

    for (cur = *head, prev = NULL;
         cur != NULL && cur->data != n;
         prev = cur, cur = cur->next)
        ;

    if (cur != NULL) // n was not found if cur == NULL
    {
        if (prev == NULL)
        {
            *head = (*head)->next; // n is in the first node
        }
        else
        {
            prev->next = cur->next; // n is in some other node
        }
        free(cur);
    }
}

void reverse_list(ListNode **head)
{
    ListNode *cur = *head;
    ListNode *prev = NULL;
    ListNode *next = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    *head = prev;
}

void delete_from_doubly_linked_list(ListNode2 **head, int key)
{
    ListNode2 *cur = *head;

    while (cur != NULL)
    {
        if (cur->data == key)
        {
            if (cur->prev != NULL)
            {
                cur->prev->next = cur->next;
            }
            else
            {
                *head = cur->next;
            }

            if (cur->next != NULL)
            {
                cur->next->prev = cur->prev;
            }
            
            free(cur);
        }

        cur = cur->next;
    }
}

void add_to_sorted_doubly_linked_list(ListNode2 **head, int key)
{
    ListNode2 *curr = *head;
    ListNode2 *new_node = (ListNode2 *)malloc(sizeof(ListNode2));

    new_node->data = key;

    /* empty list or insert to front */
    if (curr == NULL || key <= curr->data)
    {
        new_node->next = curr;
        new_node->prev = NULL;

        if (curr != NULL)
        {
            curr->prev = new_node;
        }
        
        *head = new_node;
    }
    else
    {
        while (curr->next != NULL && curr->next->data < key)
        {
            curr = curr->next;
        }
        
        new_node->next = curr->next;
        new_node->prev = curr;

        if (curr->next != NULL)
        {
            curr->next->prev = new_node;
        }
        
        curr->next = new_node;
    }
}
