#include "tree.h"

void tree_preorder(BinaryTree *t)
{
    if (t->root == NULL)
        return;

    printf("%d ", t->root->data);
    preorder(t->root->left);
    preorder(t->root->right);
}

void inorder(BinaryTree *t)
{
    if (t->root == NULL)
        return;

    inorder(t->root->left);
    printf("%d ", t->root->data);
    inorder(t->root->right);
}

void postorder(BinaryTree *t)
{
    if (t->root == NULL)
        return;

    postorder(t->root->left);
    postorder(t->root->right);
    printf("%d ", t->root->data);
}
