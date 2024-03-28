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
	binary_tree_t **nodes_queue, *tmp;
	int currentProcessed = 0, currentAdded = 0, sz;
	int incompleteFound = 0;

	if (!tree)
	{
		return (1);
	}
	sz = binary_tree_size(tree);
	nodes_queue = malloc(sizeof(binary_tree_t *) * sz);
	nodes_queue[currentAdded++] = (binary_tree_t *)tree;
	while (currentProcessed < sz)
	{
		tmp = nodes_queue[currentProcessed++];
		if (incompleteFound && (tmp->left != NULL || tmp->right != NULL))
		{
			free(nodes_queue);
			return (0);
		}
		if (tmp->left == NULL  && tmp->right != NULL)
		{
			free(nodes_queue);
			return (0);
		}
		else if (tmp->left != NULL && tmp->right == NULL)
			incompleteFound = 1;
		else if (tmp->left == NULL && tmp->right == NULL)
			incompleteFound = 1;
		if (tmp->left)
			nodes_queue[currentAdded++] = tmp->left;
		if (tmp->right)
			nodes_queue[currentAdded++] = tmp->right;
	}
	free(nodes_queue);
	return (1);
}
