#include "list.h"

List *list_init(void)
{
    List *list = (List *)malloc(sizeof(List));

    if (list == NULL)
    {
        printf("Error: memory allocation fail.\n");
        return NULL;
    }

    list->head = NULL;

    return list;
}

void list_destroy(List *list)
{
    if (list == NULL)
        return;

    ListNode *cur = list->head;
    ListNode *next = NULL;

    while (cur != NULL)
    {
#if ( LINKED_LIST_METHOD == SINGLY_LINKED_LIST )
        next = cur->next;
#else
        next = cur->right;
#endif
        free(cur);
        cur = next;
    }
    
    free(list);
}

int list_length(List *list)
{
    if (list == NULL)
        return -1;
        
    int count = 0;
    ListNode *ptr = list->head;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    
    return count;
}

#if ( LINKED_LIST_METHOD == SINGLY_LINKED_LIST )

void sorted_list_push(List *list, Item key)
{
    if (list == NULL)
        return;
    
    ListNode *cur = list->head;
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));

    if (new_node == NULL)
    {
        printf("Error: memory allocation fail.\n");
        return;
    }

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
    if (list == NULL)
        return;
    
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
    if (list == NULL)
        return;
    
    if (list->head == NULL)
    {
        printf("Error: list is empty.\n");
        return;
    }

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

List *sorted_list_merge(List *list_1, List *list_2)
{
    if (list_1 == NULL || list_2 == NULL)
        return NULL;
    
    List *merge_list = list_init();
    
    ListNode *ptr1 = list_1->head;
    ListNode *ptr2 = list_2->head;

    ListNode **last_ptr_ref = &(merge_list->head);

    while (ptr1 != NULL || ptr2 != NULL)
    {
        ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));

        if (new_node == NULL)
        {
            printf("Error: memory allocation fail.\n");
            list_destroy(merge_list);
            return NULL;
        }

        new_node->next = NULL;

        if (ptr1 == NULL)
        {
            new_node->data = ptr2->data;
            ptr2 = ptr2->next;
        }
        else if (ptr2 == NULL)
        {
            new_node->data = ptr1->data;
            ptr1 = ptr1->next;
        }
        else
        {
            if (ptr1->data <= ptr2->data)
            {
                new_node->data = ptr1->data;
                ptr1 = ptr1->next;
            }
            else
            {
                new_node->data = ptr2->data;
                ptr2 = ptr2->next;
            }
        }

        *last_ptr_ref = new_node;
        last_ptr_ref = &(new_node->next);
    }
    
    return merge_list;
}

#else

void sorted_list_push(List *list, Item key)
{
    if (list == NULL)
        return;
    
    ListNode *cur = list->head;
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));

    if (new_node == NULL)
    {
        printf("Error: memory allocation fail.\n");
        return;
    }

    new_node->data = key;

    /* add to first */
    if (cur == NULL || cur->data > key)
    {
        new_node->right = cur;
        new_node->left = NULL;
        
        if (cur != NULL)
        {
            cur->left = new_node;
        }
        
        list->head = new_node;
    }
    else    /* add to middle or last */
    {
        while (cur->right != NULL && cur->right->data <= key)
        {
            cur = cur->right;
        }
        
        new_node->right = cur->right;
        new_node->left = cur;
        
        if (cur->right != NULL)
        {
            cur->right->left = new_node;
        }
        
        cur->right = new_node;
    }
}

void list_pop(List *list, Item key)
{
    if (list == NULL)
        return;
    
    if (list->head == NULL)
    {
        printf("Error: list is empty.\n");
        return;
    }

    ListNode *cur = list->head;

    /* search */
    while (cur != NULL && cur->data != key)
    {
        cur = cur->right;
    }
    
    /* not found */
    if (cur == NULL)
    {
        printf("Error: not found.\n");
        return;
    }
    
    /* delete from list */
    if (cur == list->head)
    {
        list->head = cur->right;
    }
    else
    {
        cur->left->right = cur->right;
    }

    if (cur->right != NULL)
    {
        cur->right->left = cur->left;
    }

    free(cur);
}

#endif