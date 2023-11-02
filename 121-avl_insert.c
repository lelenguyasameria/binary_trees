#include "binary_trees.h"

/**
 * avl_insert - Inserts a value into an AVL Tree.
 * @tree: A double pointer to the root node of the AVL tree for inserting the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (tree == NULL)
        return (NULL);

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    if (value == (*tree)->n)
        return (NULL);

    if (value < (*tree)->n)
    {
        avl_t *inserted = avl_insert(&((*tree)->left), value);
        if (inserted == NULL)
            return (NULL);
        (*tree)->left = inserted;
    }
    else
    {
        avl_t *inserted = avl_insert(&((*tree)->right), value);
        if (inserted == NULL)
            return (NULL);
        (*tree)->right = inserted;
    }

    int balance = binary_tree_balance(*tree);

    if (balance > 1 && value < (*tree)->left->n)
        return (binary_tree_rotate_right(*tree));

    if (balance < -1 && value > (*tree)->right->n)
        return (binary_tree_rotate_left(*tree));

    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        return (binary_tree_rotate_right(*tree));
    }

    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        return (binary_tree_rotate_left(*tree));
    }

    return (*tree);
}

