#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: Pointer to the new root node of the tree once rotated
 *         NULL upon failure
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree || !tree->right)
		return (NULL);
	new_root = tree->right;
	tree->right = new_root->left;
	if (new_root->left)
		new_root->left->parent = tree;

	new_root->left = tree;
	new_root->parent = tree->parent;
	if (new_root->parent)
	{
		if (new_root->parent->left == tree)
			new_root->parent->left = new_root;
		else
			new_root->parent->right = new_root;
	}
	tree->parent = new_root;

	return (new_root);
}
