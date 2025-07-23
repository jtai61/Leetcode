#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} TreeNode;



#endif