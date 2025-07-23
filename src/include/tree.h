#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} TreeNode;

void preorder(TreeNode *);
void inorder(TreeNode *);
void postorder(TreeNode *);


#endif