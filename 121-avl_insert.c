#include "binary_trees.h"
/**
 * fix_balance - Fixes the balance of an AVL tree after insertion
 * @tree: Pointer to a pointer to the root node of the AVL tree
 * @value: Value of the newly inserted node
 */
void fix_balance(avl_t **tree, int value)
{
	int bfactor = binary_tree_balance(*tree);

	if (bfactor > 1 && value < (*tree)->left->n)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfactor < -1 && value > (*tree)->right->n)
		*tree = binary_tree_rotate_left(*tree);
	else if ((bfactor > 1 && value > (*tree)->left->n) ||
			 (bfactor < -1 && value < (*tree)->right->n))
	{
		if (bfactor > 1)
			(*tree)->left = binary_tree_rotate_left((*tree)->left);
		else
			(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = (bfactor > 1) ? binary_tree_rotate_right(*tree) :
			binary_tree_rotate_left(*tree);
	}
}


/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: Pointer to a pointer to the root node of the AVL tree
 * @value: Value to insert into the AVL tree
 * Return: Pointer to the newly inserted node, or NULL if the insertion fails
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = binary_tree_node(NULL, value);
	avl_t *current;
	avl_t *parent;

	if (!new_node)
		return (NULL);

	if (!*tree)
		return (*tree = new_node, new_node);
	current = *tree;
	parent = NULL;
	while (current)
	{
		parent = current;
		if (value == current->n)
		{
			free(new_node);
			return (NULL);
		}
		else if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}

	new_node->parent = parent;
	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	while (parent)
	{
		fix_balance(parent == *tree ? tree : &parent, value);
		parent = parent->parent;
	}

	return (new_node);
}
