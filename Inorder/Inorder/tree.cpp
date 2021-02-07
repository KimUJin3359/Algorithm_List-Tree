#include "tree.h"

Node::Node(int num, int level)
{
	this->num = num;
	this->level = level;
	left = NULL;
	right = NULL;
}


Tree::Tree()
{
	root = NULL;
}

Tree::Tree(char data)
{
	Node *newN = new Node(data, 0);
	root = newN;
}

Node* Tree::find_node(Node *node, int num)
{
	Node *temp = NULL;

	if (node->num == num)
		temp = node;
	if (!temp && node->left)
		temp = find_node(node->left, num);
	if (!temp && node->right)
		temp = find_node(node->right, num);
	return (temp);
}

void Tree::find_node_by_level(Node *node, int level)
{
	if (node->level == level)
		printf("%d ", node->data);
	else if (node->level < level)
	{
		if (node->left)
			find_node_by_level(node->left, level);
		if (node->right)
			find_node_by_level(node->right, level);
	}
}

void Tree::insert_root(int num)
{
	Node *newN = new Node(num, 0);
	root = newN;
}

void Tree::insert_left(int num, int num_l)
{
	Node *temp = find_node(root, num);
	Node *newN = new Node(num_l, temp->level + 1);
	if (temp->level + 1 > level)
		level = temp->level + 1;
	temp->left = newN;
}

void Tree::insert_right(int num, int num_r)
{
	Node *temp = find_node(root, num);
	Node *newN = new Node(num_r, temp->level + 1);
	if (temp->level + 1 > level)
		level = temp->level + 1;
	temp->right = newN;
}

void Tree::preorder(Node *node)
{
	printf("%d ", node->data);
	if (node->left)
		preorder(node->left);
	if (node->right)
		preorder(node->right);
}

void Tree::inorder(Node *node)
{
	if (node->left)
		inorder(node->left);
	printf("%c", node->data);
	if (node->right)
		inorder(node->right);
}

void Tree::postorder(Node *node)
{
	if (node->left)
		postorder(node->left);
	if (node->right)
		postorder(node->right);
	printf("%d ", node->data);
}

void Tree::levelorder(Node *node)
{
	for (int i = 0; i <= level; i++)
	{
		printf("level %d : ", i);
		find_node_by_level(root, i);
		printf("\n");
	}
}

void Tree::free_by_level(Node *node, int level)
{
	if (node->level == level)
		delete node;
	else if (node->level < level)
	{
		if (node->left)
			free_by_level(node->left, level);
		if (node->right)
			free_by_level(node->right, level);
	}
}

void Tree::free(Node *node)
{
	for (int i = level; i >= 0; i--)
		free_by_level(node, i);
}

void Tree::set_data(int num, char c)
{
	Node *temp = find_node(root, num);
	temp->data = c;
}