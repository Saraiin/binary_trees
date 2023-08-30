#include "binary_trees.h"
#include <stdio.h>

/**
 * height_diff - Calculates the height difference of left and right nodes
 * and number of nodes in a binary tree
 * @tree: is a pointer to the root node of the tree to check
 * @n_nodes: A pointer to number of nodes
 * Return: The height difference of left and right nodes
 */
int height_diff(const binary_tree_t *tree, int *n_nodes)
{
	int lh, rh;

	if (!tree)
		return (0);

	(*n_nodes)++;
	lh = tree->left ? 1 + height_diff(tree->left, n_nodes) : 0;
	rh = tree->right ? 1 + height_diff(tree->right, n_nodes) : 0;

	return (lh - rh);
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int lefth, righth, lnodes = 0, rnodes = 0;

	if (!tree)
		return (0);

	lefth = height_diff(tree->left, &lnodes);
	righth = height_diff(tree->right, &rnodes);

	if (lefth == righth && lnodes == rnodes)
		return (1);
	return (0);
}
