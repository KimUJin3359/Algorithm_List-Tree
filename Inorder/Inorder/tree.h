#ifndef TREE_H
# define TREE_H

#include <stdio.h>
#pragma warning (disable :4996)

class Node
{
public:
	int num;
	char data;
	int level;
	Node *left;
	Node *right;

	Node(int num, int level);
};

class Tree
{
public:
	Node *root;
	int level = 0;

	Tree();
	Tree(char data);
	Node* find_node(Node *node, int num);
	void find_node_by_level(Node *node, int level);
	void insert_root(int num);
	void insert_left(int num, int num_l);
	void insert_right(int num, int num_r);
	void preorder(Node *node);
	void inorder(Node *node);
	void postorder(Node *node);
	void levelorder(Node *node);
	void free_by_level(Node *node, int level);
	void free(Node *node);
	void set_data(int num, char c);
};

#endif
