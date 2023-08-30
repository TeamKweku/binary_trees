#include "binary_trees.h"

/**
 * binary_tree_is_root - function that checks if a given node is
 * root
 * @node: pointer to node to be checked
 *
 * Return: 1 if node is a root or 0 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	return ((node->parent == NULL) ? 1 : 0);
}
