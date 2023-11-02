#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array.
 * @heap: A pointer to the root node of the heap to convert.
 * @size: An address to store the size of the array.
 *
 * Return: A pointer to the sorted array of integers in descending order.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *sorted_array = NULL;
    size_t array_size = 0;

    if (heap == NULL || size == NULL)
        return (NULL);

    array_size = heap_size(heap);
    sorted_array = malloc(sizeof(int) * array_size);

    if (sorted_array == NULL)
        return (NULL);

    for (size_t i = 0; i < array_size; i++)
    {
        sorted_array[i] = heap_extract(&heap);
    }

    *size = array_size;
    return (sorted_array);
}

/**
 * heap_size - Computes the size of the heap.
 * @root: A pointer to the root node of the heap.
 *
 * Return: The size of the heap.
 */
size_t heap_size(heap_t *root)
{
    if (root == NULL)
        return (0);
    return (1 + heap_size(root->left) + heap_size(root->right));
}

