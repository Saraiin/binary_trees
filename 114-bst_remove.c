#include "binary_trees.h"
#include <stdio.h>

/**
 * inorder_successor - get in order successor of a node
 * @root: pointer to the node to search for it's in order successor
 * Return: pointer to the "in order successor" of the given node
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left)
		root = root->left;
	return (root);
}

/**
 * findparent - looks for the parent of a node
 * @node: pointer to the node
 * Return: pointer to the parent of the node
 */
bst_t *findparent(bst_t *node)
{
	if (node->parent == NULL)
		return (node);
	return (findparent(node->parent));
}
/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: is a pointer to the root node of the tree where
 * you will remove a node
 * @value: is the value to remove in the tree
 * Return: a pointer to the new root node of the tree after
 * removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *tmp;
	int ntmp;

	if (!root || !value)
		return (NULL);
	if (root->n == value)
	{
		if (root->right == NULL)
		{
			if (root->left)
				root->left->parent = root->parent;
			if (root->parent && root->parent->left == root)
				root->parent->left = root->left;
			else if (root->parent)
				root->parent->right = root->left;
			tmp = findparent(root);
			free(root);
			return (tmp);
		}
		if (root->left == NULL)
		{
			if (root->right)
				root->right->parent = root->parent;
			if (root->parent && root->parent->right == root)
				root->parent->right = root->right;
			else if (root->parent)
				root->parent->left = root->right;
			tmp = findparent(root);
			free(root);
			return (tmp);
		}
		node = inorder_successor(root->right);
		ntmp = node->n;
		bst_remove(findparent(node), node->n);
		root->n = ntmp;
		return (findparent(root));
	}
	else if (root->n < value)
		return (bst_remove(root->right, value));
	return (bst_remove(root->left, value));
}
