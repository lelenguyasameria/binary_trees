#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node. The value in the node
 *        must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    queue_t *queue = NULL;
    const binary_tree_t *current;

    queue = enqueue(queue, (void *)tree);

    while (!is_empty(queue))
    {
        current = (const binary_tree_t *)dequeue(&queue);
        func(current->n);

        if (current->left)
            queue = enqueue(queue, (void *)current->left);
        if (current->right)
            queue = enqueue(queue, (void *)current->right);
    }

    free_queue(queue);
}

