#ifndef TREE_H
# define TREE_H

#include <stdio.h>

class Node
{
public:
	int data;
	int level;
	Node *left;
	Node *right;

	Node(int data, int level);
};

class Tree
{
public:
	Node *root;
	int level = 0;

	Tree();
	Tree(int data);
	Node* find_node(Node *node, int data);
	void find_node_by_level(Node *node, int level);
	void insert(int d1, int d2);
	void preorder(Node *node);
	void inorder(Node *node);
	void postorder(Node *node);
	void levelorder(Node *node);
	void free_by_level(Node *node, int level);
	void free(Node *node);
};

#endif
