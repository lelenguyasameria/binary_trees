#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST).
 * @root: A pointer to the root node of the tree.
 * @value: The value to remove from the tree.
 *
 * Return: A pointer to the new root node of the tree after removing the desired value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else
    {
        if (root->left == NULL)
        {
            bst_t *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }

        bst_t *temp = find_in_order_successor(root->right);

        root->n = temp->n;
        root->right = bst_remove(root->right, temp->n);
    }

    return root;
}

/**
 * find_in_order_successor - Finds the in-order successor of a given node.
 * @node: The node for which to find the in-order successor.
 *
 * Return: A pointer to the in-order successor node.
 */
bst_t *find_in_order_successor(bst_t *node)
{
    bst_t *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

