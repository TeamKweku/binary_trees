#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child on a parent
 * @parent: pointer to the node to insert the left-child
 * @value: value to store in new node
 *
 * Return: pointer to created node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	new_node->left = parent->left;

	if (parent->left != NULL)
		parent->left->parent = new_node;

	parent->left = new_node;

	return (new_node);
}
