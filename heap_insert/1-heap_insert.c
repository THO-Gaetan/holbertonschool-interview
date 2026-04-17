#include "binary_trees.h"

/**
* tree_size - Measures the size of a binary tree
* @tree: Pointer to the root of the tree
*
* Return: Number of nodes in the tree
*/
static size_t tree_size(const heap_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
* find_parent - Finds the parent node for insertion index
* @root: Pointer to the heap root
* @index: Index of the new node (1-based level-order)
*
* Return: Pointer to parent node, or NULL on failure
*/
static heap_t *find_parent(heap_t *root, size_t index)
{
	size_t parent_index, bit;
	heap_t *node;

	if (root == NULL || index < 2)
		return (NULL);

	parent_index = index / 2;
	node = root;
	bit = 1;

	while (bit <= parent_index)
		bit <<= 1;
	bit >>= 2;

	while (bit > 0 && node != NULL)
	{
		if (parent_index & bit)
			node = node->right;
		else
			node = node->left;
		bit >>= 1;
	}

	return (node);
}

/**
* bubble_up - Restores Max Heap ordering from a node upward
* @node: Pointer to the inserted node
*
* Return: Pointer to node containing inserted value after bubbling
*/
static heap_t *bubble_up(heap_t *node)
{
	int tmp;

	while (node != NULL && node->parent != NULL && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}

	return (node);
}

/**
* heap_insert - Inserts a value in a Max Binary Heap
* @root: Double pointer to the root node of the heap
* @value: Value to store in the node to be inserted
*
* Return: Pointer to the inserted node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	size_t index;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	index = tree_size(*root) + 1;
	parent = find_parent(*root, index);
	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if ((index & 1) == 0)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (bubble_up(new_node));
}
