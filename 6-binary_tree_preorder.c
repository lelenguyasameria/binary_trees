#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree using pre-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node. The value in the node
 *        must be passed as a parameter to this function.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    func(tree->n);  // Call the provided function with the value of the current node
    binary_tree_preorder(tree->left, func);    // Recursively traverse the left subtree
    binary_tree_preorder(tree->right, func);   // Recursively traverse the right subtree
}
