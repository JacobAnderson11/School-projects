#include<iostream>
using namespace std;

bool isBST = true;

struct NODE
{
	int data;
	NODE* left;
	NODE* right;
};

bool check_BST(NODE* root);
void check_left(NODE* root, int root_data);
void check_right(NODE* root, int root_data);
void print_tree(NODE* root);

int main()
{
	NODE* root = new NODE;
	root->right = NULL;
	root->left = NULL;
	NODE* A = new NODE;
	A->right = NULL;
	A->left = NULL;
	NODE* B = new NODE;
	B->right = NULL;
	B->left = NULL;
	NODE* C = new NODE;
	C->right = NULL;
	C->left = NULL;
	NODE* D = new NODE;
	D->left = NULL;
	D->right = NULL;
	NODE* E = new NODE;
	E->left = NULL;
	E->right = NULL;
	

	root->left = A;
	root->right = B;
	A->right = C;
	B->left = D;
	C->left = E;

	root->data = 10;
	A->data = 7;
	C->data = 9;
	E->data = 8;
	B->data = 15;
	D->data = 12;

	print_tree(root);

	if (check_BST(root) == true)
		cout << "The tree is a BST: " << endl;
	else
		cout << "the tree is not a BST: " << endl;

	isBST = true;

	root->data = 10;
	A->data = 7;
	C->data = 9;
	E->data = 6;
	B->data = 15;
	D->data = 12;

	print_tree(root);

	if (check_BST(root) == true)
		cout << "The tree is a BST: " << endl;
	else
		cout << "the tree is not a BST: " << endl;

	isBST = true;

	root->data = 10;
	A->data = 7;
	C->data = 11;
	E->data = 8;
	B->data = 15;
	D->data = 12;

	print_tree(root);

	if (check_BST(root) == true)
		cout << "The tree is a BST: " << endl;
	else
		cout << "the tree is not a BST: " << endl;

	isBST = true;

	root->data = 20;
	A->data = 15;
	C->data = 19;
	E->data = 16;
	B->data = 60;
	D->data = 59;

	print_tree(root);

	if (check_BST(root) == true)
		cout << "The tree is a BST: " << endl;
	else
		cout << "the tree is not a BST: " << endl;

	isBST = true;

	root = NULL;

	print_tree(root);

	if (check_BST(root) == true)
		cout << "The tree is a BST: " << endl;
	else
		cout << "the tree is not a BST: " << endl;
}


bool check_BST(NODE* root) //checks if the given tree is a BST:
{
	if (root != NULL)
	{
		int root_data = root->data;
		check_left(root->left, root_data);
		check_right(root->right, root_data);
		return isBST;
	}
	else
		return false;
}
void check_left(NODE* root, int root_data) //checks the left half of the tree compared to the root:
{

	if (root != NULL && root->data < root_data)
	{
		if (root->left != NULL)
			check_left(root->left, root_data); //continues checking the left half of the tree:
		if (root->right != NULL)
			check_left (root->right, root_data); //continues checking the left half of the tree: 

		check_BST(root); //checks that every possible subtree of the tree is also a BST:
	}
	else if (root != NULL && root->data > root_data)
		isBST = false;
}
void check_right(NODE* root, int root_data)
{

	if (root != NULL && root->data > root_data)
	{
			if (root->left != NULL)
				check_right(root->left, root_data);
		if (root->right != NULL)
			check_right(root->right, root_data);

		check_BST(root);
	}
	else if ( root != NULL && root->data < root_data)
		isBST = false;

}

void print_tree(NODE* root)
{
	if (root != NULL)
	{
		if (root->data != NULL)
		{
			cout << "The root is: " << root->data << endl;
			if (root->left != NULL)
				cout << "The roots left child is: " << root->left->data << endl;
			if (root->right != NULL)
				cout << "The roots right child is: " << root->right->data << endl;
		}

		if (root->left != NULL)
		{
			print_tree(root->left);
		}
		if (root->right != NULL)
		{
			print_tree(root->right);
		}
	}
	else
		cout << "The tree is NULL: " << endl;
}