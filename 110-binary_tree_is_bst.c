#include "binary_trees.h"

/**
 * helper - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root
 * @min: Lower bound of checked nodes
 * @max: Upper bound of checked nodes
 *
 * Return: 1 if tree is a valid BST
 *         0 otherwise
 */
int helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (helper(tree->left, min, tree->n - 1) &&
		helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root
 *
 * Return: 1 if tree is a valid BST
 *         0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (helper(tree, INT_MIN, INT_MAX));
}
