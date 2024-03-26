#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    /* If tree is NULL, it is considered full */
    if (tree == NULL)
        return (1);

    /* If both left and right children are NULL, it is a leaf and considered full */
    if (tree->left == NULL && tree->right == NULL)
        return (1);

    /* If both left and right children are present, recursively check if they are full */
    if (tree->left != NULL && tree->right != NULL)
        return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

    /* If only one child is present, the tree is not full */
    return (0);
}

