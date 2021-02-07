#include "tree.h"

int main()
{
	Tree tree(1);
	tree.insert(1, 2);
	tree.insert(1, 3);
	tree.insert(2, 4);
	tree.insert(3, 5);
	tree.insert(3, 6);
	tree.insert(4, 7);
	tree.insert(5, 8);
	tree.insert(5, 9);
	tree.insert(6, 10);
	tree.insert(6, 11);
	tree.insert(7, 12);
	tree.insert(11, 13);

	printf("preorder : ");
	tree.preorder(tree.root);
	printf("\n");

	printf("inorder : ");
	tree.inorder(tree.root);
	printf("\n");

	printf("postorder : ");
	tree.postorder(tree.root);
	printf("\n");

	printf("levelorder\n");
	tree.levelorder(tree.root);
	printf("\n");

	tree.free(tree.root);
}