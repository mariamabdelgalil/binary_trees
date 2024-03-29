#include "binary_trees.h"

/**
 * helper - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise or if the tree is NULL
 */
int helper(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (!tree)
		return (0);
	else if (!tree->left && !tree->right)
		return (1);
	l = 1 + helper(tree->left);
	r = 1 + helper(tree->right);
	return (r == l && r != 0 && l != 0 ? r : 0);
}
/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise or if the tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	return (helper(tree) ? 1 : 0);
}
