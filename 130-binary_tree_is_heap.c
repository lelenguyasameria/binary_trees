#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return is_heap_helper(tree) ? 1 : 0;
}

/**
 * is_heap_helper - Recursive helper function to check if a tree is a valid Max Binary Heap.
 * @node: The current node to check.
 *
 * Return: 1 if the subtree rooted at 'node' is a valid Max Binary Heap, 0 otherwise.
 */
int is_heap_helper(const binary_tree_t *node)
{
    if (node == NULL)
        return (1);

    if (node->left != NULL && node->n < node->left->n)
        return (0);

    if (node->right != NULL && node->n < node->right->n)
        return (0);

    return is_heap_helper(node->left) && is_heap_helper(node->right);
}

