#include "binary_trees.h"

/**
 * helper - converts a sorted array into an AVL tree
 * @array: Pointer to the sorted array of integers
 * @start: Index of the start of the current subarray
 * @end: Index of the end of the current subarray
 * @parent: Pointer to the parent node of the current node
 *
 * Return: Pointer to the root node of the resulting AVL tree,
 * or NULL
 */
avl_t *helper(int *array, int start, int end, avl_t *parent)
{
	avl_t *newNode;
	int mid = (start + end) / 2;

	if (start > end)
		return (NULL);
	newNode = malloc(sizeof(avl_t));
	if (!newNode)
		return (NULL);

	newNode->n = array[mid];
	newNode->parent = parent;
	newNode->left = helper(array, start, mid - 1, newNode);
	newNode->right = helper(array, mid + 1, end, newNode);
	return (newNode);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Return: a pointer to the root node of the created AVL tree
 *         NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (array ? helper(array, 0, size - 1, NULL) : NULL);
}
