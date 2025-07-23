#include "tree.h"

void preorder(TreeNode *root)
{
    if (root == NULL)
        return;
    else
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    else
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(TreeNode *root)
{
    if (root == NULL)
        return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
