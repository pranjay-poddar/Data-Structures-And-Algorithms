// A recursive C++ program to print
// REVERSE level order traversal
#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;
};


void printGivenLevel(node* root, int level);
int height(node* node);
node* newNode(int data);

void reverseLevelOrder(node* root)
{
	int h = height(root);
	int i;
	for (i=h; i>=1; i--)
		printGivenLevel(root, i);
}

void printGivenLevel(node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1)
	{
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}

int height(node* node)
{
	if (node == NULL)
		return 0;
	else
	{

		int lheight = height(node->left);
		int rheight = height(node->right);

		if (lheight > rheight)
			return(lheight + 1);
		else return(rheight + 1);
	}
}

node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return(Node);
}

/* Driver code*/
int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Level Order traversal of binary tree is \n";
	reverseLevelOrder(root);

	return 0;

}

