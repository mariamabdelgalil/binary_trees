#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: A pointer to the created node
 *         NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node;

	if (!tree)
		return (NULL);

	bst_t *parent = NULL;
	bst_t **current = tree;

	while (*current)
	{
		parent = *current;
		current = (value < parent->n) ? &parent->left : &parent->right;
		if (value == parent->n)
			return (NULL);
	}

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	*current = new_node;

	return (new_node);
}

