#include "binary_trees.h"

bst_t *bst_search(const bst_t *tree, int value);
int binary_tree_is_leaf(const binary_tree_t *node);
int node_has_both_children(const binary_tree_t *node);
void change_parent(binary_tree_t *node, binary_tree_t *new_parent);
bst_t *bst_remove(bst_t *root, int value);
void rebalance(avl_t **tree);

/**
 * avl_remove - Removes a node with a specified value from an AVL tree
 * @root: Pointer to the root node of the AVL tree
 * @value: Value of the node to be removed
 * Return: Pointer to the root node of the AVL
 */
avl_t *avl_remove(avl_t *root, int value)
{
	root = (avl_t *)bst_remove((bst_t *)root, value);

	if (root == NULL)
		return (NULL);
	rebalance(&root);
	return (root);
}

/**
 * rebalance - Balances the AVL tree after node removal
 * @tree: Pointer to a pointer to the root node of the AVL tree
 */
void rebalance(avl_t **tree)
{
	int balance_factor;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	rebalance(&(*tree)->left);
	rebalance(&(*tree)->right);

	balance_factor = binary_tree_balance((const binary_tree_t *)*tree);

	if (balance_factor > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_factor < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * bst_remove - Removes a node with a specified value from
 * a binary search tree (BST)
 * @root: Pointer to the root node of the BST
 * @value: Value of the node to be removed
 * Return: Pointer to the root node of the resulting BST after removal,
 * or NULL if the specified value is not present in the BST
 * or if the tree is empty
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node_to_remove = bst_search(root, value);

	if (!node_to_remove)
		return (root);

	if (binary_tree_is_leaf(node_to_remove))
	{
		root = (node_to_remove->parent) ? root : NULL;
		change_parent(node_to_remove, NULL);
		free(node_to_remove);
	}
	else if (node_has_both_children(node_to_remove))
	{
		bst_t *successor = node_to_remove->right;

		while (successor->left)
			successor = successor->left;

		node_to_remove->n = successor->n;
		bst_remove(successor, successor->n);
	}
	else
	{
		if (node_to_remove->left)
			root = (node_to_remove->parent) ? root : node_to_remove->left,
				   change_parent(node_to_remove, node_to_remove->left);
		else
			root = (node_to_remove->parent) ? root : node_to_remove->right,
				   change_parent(node_to_remove, node_to_remove->right);

		free(node_to_remove);
	}

	return (root);
}

/**
 * bst_search - Searches for a value in a binary search tree (BST)
 * @tree: Pointer to the root node of the BST
 * @value: Value to search for in the BST
 *
 * Return: Pointer to the node containing the value if found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree && tree->n > value)
		return (bst_search(tree->left, value));
	else if (tree && tree->n < value)
		return (bst_search(tree->right, value));
	else
		return ((bst_t *)tree);
}

/**
 * binary_tree_is_leaf - Checks if a node is a leaf in a binary tree
 * @node: Pointer to the node to check
 *
 * Return: 1 if the node is a leaf, 0 otherwise or if the node is NULL
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
		return (1);
	return (0);
}

/**
 * node_has_both_children - Checks if a node has both left and right children
 * @node: Pointer to the node to be checked
 *
 * Return: 1 if the node has both left and right children, 0 otherwise or if
 *         the node is NULL
 */
int node_has_both_children(const binary_tree_t *node)
{
	if (node && node->left && node->right)
		return (1);
	return (0);
}

/**
 * change_parent - Changes the parent of a node
 *
 * @node: Pointer to the node whose parent is to be changed
 * @new_parent: Pointer to the new parent node
 */
void change_parent(binary_tree_t *node, binary_tree_t *new_parent)
{
	if (!node || !node->parent)
		return;

	if (node->parent->left == node)
		node->parent->left = new_parent;
	else if (node->parent->right == node)
		node->parent->right = new_parent;

	if (new_parent)
		new_parent->parent = node->parent;
}
