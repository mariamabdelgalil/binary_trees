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
 * binary_tree_levelorder - traverst a binary tree using level-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **nodes_queue, *tmp;
	int currentProcessed = 0, currentAdded = 0, sz;

	if (!tree || !func)
	{
		return;
	}
	sz = binary_tree_size(tree);
	nodes_queue = malloc(sizeof(binary_tree_t *) * sz);
	nodes_queue[currentAdded++] = (binary_tree_t *)tree;
	while (currentProcessed < sz)
	{
		tmp = nodes_queue[currentProcessed++];
		func(tmp->n);
		if (tmp->left)
			nodes_queue[currentAdded++] = tmp->left;
		if (tmp->right)
			nodes_queue[currentAdded++] = tmp->right;
	}
	free(nodes_queue);
}
