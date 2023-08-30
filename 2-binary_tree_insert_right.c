#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child
 * of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 * Return: pointer to the created node, or NULL on failure or
 * if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newnd;

	if (!parent)
		return (NULL);

	newnd = binary_tree_node(parent, value);
	if (!newnd)
		return (NULL);

	if (!(parent->right))
		parent->right = newnd;
	else
	{
		parent->right->parent = newnd;
		newnd->right = parent->right;
		parent->right = newnd;
	}
	return (newnd);
}
