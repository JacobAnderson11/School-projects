#include<iostream>

using namespace std;

struct NODE
{
	int data;
	NODE* left;
	NODE* right;

};

class binary_tree
{
public:
	binary_tree()
	{
		root_ptr = NULL;
	}
	int summation()
	{
		if (root_ptr != NULL)
		{
			int result = 0;
			Sum(root_ptr, result);
			return result;
		}
		else
			return -1;
	}
	void push(int new_data)
	{
		if (root_ptr == NULL)
		{
			NODE* newNode = new NODE;
			newNode->data = new_data;
			newNode->left = NULL;
			newNode->right = NULL;
			root_ptr = newNode;

		}
		else
		{
			insert(root_ptr, new_data);
		}
	}

	int getRoot()
	{
		if (root_ptr != NULL)
			return root_ptr->data;
	}

	void printTree()
	{
		print_tree(root_ptr);
	}
private:
	NODE* root_ptr;
	void Sum(NODE* root, int& result)
	{
		result = result + root->data;
		if (root->left != NULL)
		{
			Sum(root->left, result);
		}
		if (root->right!= NULL)
		{
			Sum(root->right, result);
		}
		
	}

	void print_tree(NODE* root)
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

	void insert(NODE* node, int new_data)
	{
		if (node->data < new_data)
		{
			if (node->right == NULL)
			{
				NODE* newNode = new NODE;
				newNode->data = new_data;
				newNode->left = NULL;
				newNode->right = NULL;
				node->right = newNode;
			}
			else
			{
				insert(node->right, new_data);
			}
		}
		if (node->data > new_data)
		{
			if (node->left == NULL)
			{
				NODE* newNode = new NODE;
				newNode->data = new_data;
				newNode->left = NULL;
				newNode->right = NULL;
				node->left = newNode;
			}
			else
			{
				insert(node->left, new_data);
			}
		}
	}

};


int main()
{
	binary_tree test;
	for (int i = 0; i < 10; i++)
	{
		test.push(1 + rand() % 100); 
	}
	int result = test.summation();
	cout << "The summation of the tree is: " << result << endl;
	test.printTree();

	cout << false;

	system("pause");
	return 0;

};