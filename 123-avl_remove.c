#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL Tree.
 * @root: A pointer to the root node of the tree for removing a node.
 * @value: The value to remove from the tree.
 *
 * Return: A pointer to the new root node of the tree after removing the desired value, and after rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (root == NULL)
        return (root);

    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            avl_t *temp = (root->left) ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            avl_t *temp = avl_find_min(root->right);
            root->n = temp->n;
            root->right = avl_remove(root->right, temp->n);
        }
    }

    if (root == NULL)
        return (root);

    int balance = binary_tree_balance(root);

    if (balance > 1 && binary_tree_balance(root->left) >= 0)
        return binary_tree_rotate_right(root);

    if (balance < -1 && binary_tree_balance(root->right) <= 0)
        return binary_tree_rotate_left(root);

    if (balance > 1 && binary_tree_balance(root->left) < 0)
    {
        root->left = binary_tree_rotate_left(root->left);
        return binary_tree_rotate_right(root);
    }

    if (balance < -1 && binary_tree_balance(root->right) > 0)
    {
        root->right = binary_tree_rotate_right(root->right);
        return binary_tree_rotate_left(root);
    }

    return root;
}

/**
 * avl_find_min - Helper function to find the minimum value node in an AVL tree.
 * @node: A pointer to the root node of the tree to search.
 *
 * Return: A pointer to the node with the minimum value.
 */
avl_t *avl_find_min(avl_t *node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

