#include "binary_trees.h"


/**
 * min_val - finds the smallest node from a Binary Search Tree
 * @root: a pointer to the root node of the tree
 * Return: a pointer to the smallest node
 */
bst_t *min_val(bst_t *root)
{
	bst_t *min = root;

	while (min->left)
		min = min->left;

	return (min);
}
/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: a pointer to the root node
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node of the tree after removal
 *         NULL on failure
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *holder = NULL;

	if (!root)
		return (NULL);

	if (root->n > value)
		root->left = bst_remove(root->left, value);
	else
		if (root->n < value)
			root->right = bst_remove(root->right, value);
		else
		{
			if (root->left && root->right)
			{
				holder = min_val(root->right);
				root->n = holder->n;
				root->right = bst_remove(root->right, holder->n);
			}
			else
			{
				if (!root->left && !root->right)
				{
					free(root);
					return (NULL);
				}
				holder = root;
				if (!root->left)
					root = root->right;
				else
					if (!root->right)
						root = root->left;
				if (holder->parent->left == holder)
					holder->parent->left = root;
				else
					holder->parent->right = root;
				root->parent = holder->parent;
				free(holder);
			}
		}
	return (root);
}

