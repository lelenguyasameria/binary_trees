#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: A double pointer to the root node of the heap.
 *
 * Return: The value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
    int root_value;
    heap_t *last_node, *parent;

    if (root == NULL || *root == NULL)
        return (0);

    root_value = (*root)->n;
    last_node = find_last_node(*root);

    if (*root == last_node)
    {
        free(*root);
        *root = NULL;
        return (root_value);
    }

    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    last_node->parent = NULL;
    last_node->left = (*root)->left;
    last_node->right = (*root)->right;

    if (last_node->left)
        last_node->left->parent = last_node;
    if (last_node->right)
        last_node->right->parent = last_node;

    parent = last_node;
    while (parent && root_value > parent->n)
    {
        parent->n ^= root_value;
        root_value ^= parent->n;
        parent->n ^= root_value;
        parent = parent->parent;
    }

    free(*root);
    *root = last_node;

    return (root_value);
}

/**
 * find_last_node - Finds the last node in the heap.
 * @root: A pointer to the root node of the heap.
 *
 * Return: A pointer to the last node in the heap.
 */
heap_t *find_last_node(heap_t *root)
{
    queue_t *queue = NULL;
    heap_t *node = NULL;

    queue_push(&queue, root);

    while (queue)
    {
        node = queue_pop(&queue);

        if (node->left != NULL)
            queue_push(&queue, node->left);
        if (node->right != NULL)
            queue_push(&queue, node->right);
    }

    return (node);
}

