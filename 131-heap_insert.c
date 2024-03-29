#include "binary_trees.h"

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (!root)
		return NULL;
	if (!*root)
		return *root = binary_tree_node(NULL, value);

	heap_t *tree = *root;
	int size, leaves, sub, bit, level;

	size = binary_tree_size(tree);
	for (leaves = size, level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	heap_t *new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	for (heap_t *flip = new; flip->parent && flip->n > flip->parent->n;
		 flip = flip->parent)
	{
		int tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new = new->parent;
	}
	return new;
}

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