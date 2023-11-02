#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, otherwise 0. If tree is NULL, return 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    queue_t *queue = NULL;
    int found_null = 0;

    queue = enqueue(queue, (void *)tree);

    while (!is_empty(queue))
    {
        const binary_tree_t *current = (const binary_tree_t *)dequeue(&queue);

        if (current == NULL)
            found_null = 1;
        else
        {
            if (found_null)
            {
                free_queue(queue);
                return (0);
            }

            queue = enqueue(queue, (void *)current->left);
            queue = enqueue(queue, (void *)current->right);
        }
    }

    free_queue(queue);

    return (1);
}

