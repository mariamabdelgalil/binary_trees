#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t nodes = 0, expected_nodes = 0;

    if (!tree)
        return (0);

    nodes = binary_tree_count_nodes(tree);
    expected_nodes = binary_tree_expected_nodes(tree->height);

    return (nodes == expected_nodes);
}

/**
 * binary_tree_count_nodes - Counts the number of nodes in a binary tree
 * @tree: A pointer to the root node of the tree
 *
 * Return: The number of nodes in the tree
 */
size_t binary_tree_count_nodes(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (1 + binary_tree_count_nodes(tree->left) + binary_tree_count_nodes(tree->right));
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree
 *
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_l = 0, height_r = 0;

    if (!tree)
        return (0);

    height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
    height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

    return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_expected_nodes - Calculates the expected number of nodes
 *                              in a perfect binary tree of given height
 * @height: The height of the perfect binary tree
 *
 * Return: The expected number of nodes
 */
size_t binary_tree_expected_nodes(size_t height)
{
    size_t nodes = 1, i;

    for (i = 0; i < height; i++)
        nodes *= 2;

    return (nodes - 1);
}

