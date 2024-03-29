#include "binary_trees.h"

/**
 * binary_tree_node2 - Creates a binary tree node
 * @parent: Pointer to the parent node of the node to create
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node2(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

    /* Allocate memory for new node */
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	/* Initialize the new node */
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
/**
 * binary_tree_size2 - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size2(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	size += binary_tree_size2(tree->left);
	size += binary_tree_size2(tree->right);

	return (size + 1);
}

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree;
	int size, leaves, sub, bit, level;
	heap_t *new;
	heap_t *flip;
	int tmp;

	if (!root)
		return (NULL);
	if (!*root)
		return (*root = binary_tree_node2(NULL, value));

	tree = *root;
	size = binary_tree_size2(tree);
	for (leaves = size, level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new = binary_tree_node2(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	for (flip = new; flip->parent && flip->n > flip->parent->n;
		 flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new = new->parent;
	}
	return (new);
}


