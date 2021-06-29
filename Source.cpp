#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
Node* createNode(int new_data)
{
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}
void addToTree(char ch, struct Node *root_ref, struct Node *new_node)
{
	if (ch == 'L')
		root_ref->left = new_node;
	else if (ch == 'R')
		root_ref->right = new_node;
}
void Traverse_Inorder(struct Node *root_ref)
{
	if (root_ref == NULL)
		return;
	else
	{
		Traverse_Inorder(root_ref->left);
		printf(" %d ", root_ref->data);
		Traverse_Inorder(root_ref->right);
	}
}
void Traverse_Preorder(struct Node *root_ref)
{
	if (root_ref == NULL)
		return;
	else
	{
		printf(" %d ", root_ref->data);
		Traverse_Preorder(root_ref->left);
		Traverse_Preorder(root_ref->right);
	}
}
void Traverse_Postorder(struct Node *root_ref)
{
	if (root_ref == NULL)
		return;
	else
	{
		Traverse_Postorder(root_ref->left);
		Traverse_Postorder(root_ref->right);
		printf(" %d ", root_ref->data);
	}
}
void main()
{
	struct Node *root1, *node2, *node3, *node4, *node5, *node6, *node7, *node8, *node9;
	root1 = createNode(1);
	node2 = createNode(2);
	node3 = createNode(3);
	node4 = createNode(4);
	node5 = createNode(5);
	node6 = createNode(6);
	node7 = createNode(7);
	node8 = createNode(8);
	node9 = createNode(9);
	addToTree('L', root1, node2);
	addToTree('R', root1, node3);
	addToTree('L', node2, node4);
	addToTree('R', node2, node5);
	addToTree('L', node3, node6);
	addToTree('R', node3, node7);
	addToTree('L', node5, node8);
	addToTree('R', node5, node9);
	
	printf("\nInorder Traversal : ");
		Traverse_Inorder(root1);
	printf("\n\nPreorder Traversal : "); \
		Traverse_Preorder(root1);
	printf("\n\nPostorder Traversal : ");
		Traverse_Postorder(root1);
	_getch();
}