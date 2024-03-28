#include "binary_trees.h"
/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);

	return (size + 1);
}


/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *nodes_queue[10000], *tmp;
	int front = 0, rear = 0;
	int foundNull = 0;

	if (!tree)
	{
		return (1);
	}
	nodes_queue[rear++] = (binary_tree_t *)tree;
	while (front != rear)
	{
		tmp = nodes_queue[front++];
		if (tmp == NULL)
			foundNull = 1;
		else
		{
			if (foundNull)
			{
				return (0);
			}
			nodes_queue[rear++] = tmp->left;
			nodes_queue[rear++] = tmp->right;
		}
	}
	return (1);
}
