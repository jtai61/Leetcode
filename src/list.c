#include "list.h"

#if ( LINKED_LIST_METHOD == SINGLY_LINKED_LIST )

struct ListNode *sorted_list_push(struct ListNode *head, int val)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));

    if (new_node == NULL)
    {
        printf("Error: memory allocation fail.\n");
        return head;
    }

    new_node->val = val;

    struct ListNode *cur = head;

    /* add to first */
    if (cur == NULL || cur->val > val)
    {
        new_node->next = cur;
        head = new_node;
    }
    else    /* add to middle or last */
    {
        while (cur->next != NULL && cur->next->val <= val)
        {
            cur = cur->next;
        }
        
        new_node->next = cur->next;
        cur->next = new_node;
    }

    return head;
}

/* LeetCode 206. Reverse Linked List */
struct ListNode *reverseList(struct ListNode *head)
{    
    struct ListNode *cur = head;
    struct ListNode *pre = NULL;
    struct ListNode *next = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    return pre;
}

/* LeetCode 21. Merge Two Sorted Lists */
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    if (list1 == NULL)
        return list2;
    
    if (list2 == NULL)
        return list1;
    
    if (list1->val <= list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

/* LeetCode 83. Remove Duplicates from Sorted List */
struct ListNode *deleteDuplicates(struct ListNode *head)
{
    if (head == NULL)
        return NULL;
    
    struct ListNode *cur = head;

    while (cur != NULL && cur->next != NULL)
    {
        if (cur->val == cur->next->val)
        {
            struct ListNode *duplicate = cur->next;
            cur->next = cur->next->next;
            free(duplicate);
        }
        else
        {
            cur = cur->next;
        }
    }

    return head;
}

/* LeetCode 203. Remove Linked List Elements */
struct ListNode *removeElements(struct ListNode *head, int val)
{    
    struct ListNode *cur = head;
    struct ListNode *pre = NULL;

    while (cur != NULL)
    {
        if (cur->val == val)
        {
            struct ListNode *target = cur;

            if (pre == NULL)
            {
                head = cur->next;
            }
            else
            {
                pre->next = cur->next;
            }
            
            cur = cur->next;
            free(target);
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }

    return head;
}

/* LeetCode 876. Middle of the linked list */
struct ListNode *middleNode(struct ListNode *head)
{
    if (head == NULL)
        return NULL;

    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
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