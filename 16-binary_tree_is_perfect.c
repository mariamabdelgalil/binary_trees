#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is full, return 1. Otherwise, return 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (1);

    if (tree->left == NULL && tree->right == NULL)
        return (1);

    if (tree->left && tree->right)
        return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

    return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree, 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_l = 0, height_r = 0;

    if (tree == NULL)
        return (0);

    height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
    height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

    return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is perfect, return 1. Otherwise, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t height = 0, expected_nodes = 0, actual_nodes = 0;

    if (tree == NULL)
        return (0);

    height = binary_tree_height(tree);
    expected_nodes = (1 << height) - 1;
    actual_nodes = binary_tree_size(tree);

    return (actual_nodes == expected_nodes && binary_tree_is_full(tree));
}

