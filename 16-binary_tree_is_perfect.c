#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of tree or 0 otherwise
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
		return (0);

	left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return ((left > right) ? left : right);

}

/**
 * binary_tree_size - function that measures the size of a
 * binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: size of tree or 0 otherwise
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * power_recursion - returns the value of num raised to the power x
 * @num: value to be exponentiated
 * @x: the power to be raised
 *
 * Return: num to the power x or -1 if x is negative
 */
int power_recursion(int num, int x)
{
	if (x < 0)
		return (-1);
	if (x == 0)
		return (1);
	else
		return (num * power_recursion(num, x - 1));
}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if perfect or 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0, nodes = 0, power = 0;

	if (tree == NULL)
		return (0);

	if (tree->right == NULL && tree->left == NULL)
		return (1);

	height = binary_tree_height(tree);
	nodes = binary_tree_size(tree);

	power = (size_t)power_recursion(2, height + 1);
	return (power - 1 == nodes);
}
