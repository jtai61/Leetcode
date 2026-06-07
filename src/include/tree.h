#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

#define BINARY_TREE     ( 1 )
#define TYPE            ( BINARY_TREE )

#if ( TYPE == BINARY_TREE )

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

typedef struct tree
{
    Node *root;
} BinaryTree;

BinaryTree *tree_init(void);
void tree_preorder(BinaryTree *);
void tree_inorder(BinaryTree *);
void tree_postorder(BinaryTree *);

#endif

#endif