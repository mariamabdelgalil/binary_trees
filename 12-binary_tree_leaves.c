#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of leaves in the binary tree, 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* If both left and right children are NULL, the node is a leaf */
    if (tree->left == NULL && tree->right == NULL)
        return (1);

    /* Recursively count leaves in the left and right subtrees */
    return binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
}
