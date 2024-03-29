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
 * heapify_up - Restores the Max Heap property by moving the newly inserted
 * node up the tree if necessary
 * @node: Pointer to the newly inserted node
 *
 * Return: Pointer to the root of the heap after restoring the property
 */
heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *newNode, *parent;

	if (root == NULL)
		return (NULL);

	newNode = binary_tree_node(NULL, value);
	if (newNode == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = newNode;
		return (newNode);
	}

	parent = *root;
	while (parent->left != NULL && parent->right != NULL)
	{
		if (binary_tree_size(parent->left) <= binary_tree_size(parent->right))
			parent = parent->left;
		else
			parent = parent->right;
	}

	if (parent->left == NULL)
		parent->left = newNode;
	else
		parent->right = newNode;

	newNode->parent = parent;
	return (heapify_up(newNode));
}
