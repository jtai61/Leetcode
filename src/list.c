#include "list.h"

void sorted_list_push(List *list, Item key)
{
    ListNode *cur = list->head;
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));

    new_node->data = key;

    /* add to first */
    if (cur == NULL || cur->data > key)
    {
        new_node->next = cur;
        list->head = new_node;
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

void list_pop(List *list, Item key)
{
    if (list->head == NULL)
    {
        printf("Error: list is empty.\n");
        return;
    }

    ListNode *cur = list->head;
    ListNode *pre = NULL;

    /* search */
    while (cur != NULL && cur->data != key)
    {
        pre = cur;
        cur = cur->next;
    }
    
    /* not found */
    if (cur == NULL)
    {
        printf("Error: not found.\n");
        return;
    }
    
    /* delete from list */
    if (pre == NULL)
    {
        list->head = cur->next; // first node
    }
    else
    {
        pre->next = cur->next;
    }

    free(cur);
}

void list_reverse(List *list)
{
    ListNode *cur = list->head;
    ListNode *pre = NULL;
    ListNode *next = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    list->head = pre;
}
