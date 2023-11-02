#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: A double pointer to the root node of the Max Heap.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    if (root == NULL)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    if (*root == NULL)
    {
        *root = new_node;
        return (new_node);
    }

    parent = find_insertion_point(*root);
    if (parent->left == NULL)
        parent->left = new_node;
    else
        parent->right = new_node;

    new_node->parent = parent;

    return (heapify_up(new_node));
}

/**
 * find_insertion_point - Finds the insertion point for the new node.
 * @root: A pointer to the root node of the Max Heap.
 *
 * Return: A pointer to the parent node for the new node.
 */
heap_t *find_insertion_point(heap_t *root)
{
    queue_t *queue = NULL;
    heap_t *node = NULL;

    queue_push(&queue, root);

    while (queue)
    {
        node = queue_pop(&queue);

        if (node->left == NULL || node->right == NULL)
            break;

        queue_push(&queue, node->left);
        queue_push(&queue, node->right);
    }

    return (node);
}

/**
 * heapify_up - Bubbles up the new node to maintain the Max Heap property.
 * @node: The newly inserted node.
 *
 * Return: A pointer to the final position of the new node.
 */
heap_t *heapify_up(heap_t *node)
{
    while (node->parent != NULL && node->n > node->parent->n)
    {
        node->n ^= node->parent->n;
        node->parent->n ^= node->n;
        node->n ^= node->parent->n;
        node = node->parent;
    }
    return (node);
}

