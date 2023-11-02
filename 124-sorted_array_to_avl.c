#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL Tree from a sorted array.
 * @array: A pointer to the first element of the sorted array.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);

    return (sorted_array_to_avl_helper(array, 0, size - 1, NULL));
}

/**
 * sorted_array_to_avl_helper - Recursively builds an AVL Tree from a sorted array.
 * @array: A pointer to the first element of the sorted array.
 * @start: The start index of the current subarray.
 * @end: The end index of the current subarray.
 * @parent: A pointer to the parent node of the current subtree.
 *
 * Return: A pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl_helper(int *array, int start, int end, avl_t *parent)
{
    if (start > end)
        return (NULL);

    int mid = (start + end) / 2;

    avl_t *new_node = binary_tree_node(parent, array[mid]);
    if (new_node == NULL)
        return (NULL);

    new_node->left = sorted_array_to_avl_helper(array, start, mid - 1, new_node);
    new_node->right = sorted_array_to_avl_helper(array, mid + 1, end, new_node);

    return (new_node);
}

