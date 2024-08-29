#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;         // data stored in the node
    struct node *next; // pointer to the next node
};

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

void print_list(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void print_list2(ListNode *head)
{
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void add_to_list(struct node **list, int n)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        new_node->value = n;
        new_node->next = *list;
        *list = new_node;
    }
}

struct node *search_list(struct node *list, int n)
{
    while (list != NULL && list->value != n)
    {
        list = list->next;
    }

    return list;
}

void delete_from_list(struct node **list, int n)
{
    struct node *cur, *prev;

    for (cur = *list, prev = NULL;
         cur != NULL && cur->value != n;
         prev = cur, cur = cur->next)
        ;

    if (cur != NULL) // n was not found if cur == NULL
    {
        if (prev == NULL)
        {
            *list = (*list)->next; // n is in the first node
        }
        else
        {
            prev->next = cur->next; // n is in some other node
        }
        free(cur);
    }
}

void reverse_list(struct node **list)
{
    struct node *cur = *list;
    struct node *prev = NULL;
    struct node *next = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    *list = prev;
}

int main()
{
    struct node *first = NULL; // init linked list

    add_to_list(&first, 10); // insert new node
    add_to_list(&first, 20); // insert new node
    add_to_list(&first, 40); // insert new node
    add_to_list(&first, 30); // insert new node
    add_to_list(&first, 80); // insert new node
    add_to_list(&first, 50); // insert new node

    print_list(first);

    // // found = search_list(first, 20);

    // delete_from_list(&first, 10);

    reverse_list(&first);

    print_list(first);

    return 0;
}
