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
 * helper - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * @index: node index to check
 * @size: number of nodes in the tree
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (helper(tree->left, 2 * index + 1, size) &&
		helper(tree->right, 2 * index + 2, size));
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
	return (tree && helper(tree, 0, binary_tree_size(tree)));
}


/**
 * binary_tree_is_heap_helper - checks if a binary tree
 * is a valid Max Binary Heap
 * @tree: a pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid Max Binary Heap
 *         1 if tree is NULL
 *         0 otherwise
 */
int binary_tree_is_heap_helper(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);
	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (binary_tree_is_heap_helper(tree->left) &&
		binary_tree_is_heap_helper(tree->right));
}


/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap
 *         0 if tree is NULL
 *         0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_is_heap_helper(tree));
}
