#include<iostream>
#include<string>

using namespace std;

struct person
{
	string name;
	int data;
	person* left;
	person* right;

};

class priority_queue
{
public:
	priority_queue()
	{
		root = NULL;
		height = 0;
		isinserted = false;
		size = 0;
		
	}
	void push(string name, int data)
	{
		size++;
		person* temp = new person;
		temp->data = data;
		temp->name = name;
		temp->left = NULL;
		temp->right = NULL;
		isinserted = false;

		if (root == NULL)
			root = temp;
		else
		{
			heapify(root);
			insert(root, temp, 0);
		}
	}
	void pop()
	{
		size--;
		
		heapify(root);
		if (root != NULL)
		{
			if (root->left != NULL && root->right == NULL)
			{
				root = root->left;
			}	
			if (root->left == NULL && root->right != NULL)
			{
				root = root->right;
			}	
			if (root->left != NULL && root->right != NULL)
			{
				if (root->left->data >= root->right->data)
				{
					person* temp = root;
					root = root->left;
					isinserted = false;
					insert(root, temp->right, 0);
					temp = NULL;
				}
				else if(root->left->data < root->right->data)
				{
					person* temp = root;
					root = root->right;
					isinserted = false;
					insert(root, temp->left, 0);
					temp = NULL;
				}
			}
		}
	}
	int root_data()
	{
		if (root != NULL)
		{
			heapify(root);
			return root->data;
		}
		else
			return NULL;
	}
	string root_name ()
	{
		if (root != NULL)
		{
			heapify(root);
			return root->name;
		}
		else
			return "";
	}
	void print()
	{
		print_tree(root);
	}
	int get_size()
	{
		return size;
	}
private:
	void print_tree(person* root)
	{
		if (root != NULL)
		{
			cout << root->name << " has " << root->data << " dependents" << endl;
			if (root->left != NULL)
				cout << "L = " << root->left->name;
			if (root->right != NULL)
				cout << " R = " << root->right->name;
			cout << endl;

			if (root->left != NULL)
			{
				print_tree(root->left);
			}
			if (root->right != NULL)
			{
				print_tree(root->right);
			}
		}
	}
	void heapify(person* node)
	{
		if (node->left != NULL)
		{
			if (compare(node, node->left) == 1 || compare(node, node->left) == 2)
			{
				heapify(node->left);
			}
			else if(compare(node, node->left) == 0)
			{
				int temp = node->data;
				node->data = node->left->data;
				node->left->data = temp;
				string temp2 = node->name;
				node->name = node->left->name;
				node->left->name = temp2;

				heapify(root);
			}

		}
		
		if (node->right != NULL)
		{
			if (compare(node, node->right) == 1 || compare(node, node->left) == 2)
			{
				heapify(node->right);
			}
			else if (compare(node, node->right) == 0)
			{
				int temp = node->data;
				node->data = node->right->data;
				node->right->data = temp;
				string temp2 = node->name;
				node->name = node->right->name;
				node->right->name = temp2;

				heapify(root);
			}

		}



	}
	void insert(person* node, person* NEW,int depth)
	{
		if (depth < height - 1 )
		{
			if (node->left == NULL)
			{
				node->left = NEW;
				isinserted = true;
			}
			else if (node->right == NULL)
			{
				node->right = NEW;
				isinserted = true;
			}

			if (node->left != NULL && isinserted == false)
				insert(node->left, NEW, depth++);
			if (node->right != NULL && isinserted == false)
				insert(node->right, NEW, depth++);
		}
	
	
		
		if (isinserted == false)
		{
				height++;
				insert(root, NEW, 0);
		}

	}
	int compare(person* a, person* b)
	{
		if (a != NULL && b != NULL)
		{
			if (a->data > b->data)
				return 1;
			else if (a->data == b->data)
				return 2;
			else
				return 0;
		}
		else
			return -1;
	}

	person* root;
	bool isinserted;
	int height;
	int size;

};

int main()
{

	priority_queue example;
	cout << "The size of the queue is: " << example.get_size() << endl;

	example.push("Jacob", 0);
	cout << example.root_name() << " " << example.root_data() << endl;
	example.push("Angie", 3);
	cout << example.root_name() << " " << example.root_data() << endl;
	example.push("Brad", 4);
	cout << example.root_name() << " " << example.root_data() << endl;
	example.push("Megan", 2);
	cout << example.root_name() << " " << example.root_data() << endl;
	example.push("Dawn", 5);
	cout << example.root_name() << " " << example.root_data() << endl;
	
	cout << "The size of the queue is: " << example.get_size() << endl;

	example.print();
	example.pop();
	cout << "After poping: " << endl;

	cout << example.root_name() << " " << example.root_data() << endl;
	cout << "The size of the queue is: " << example.get_size() << endl;
	example.print();

	system("pause");
	return 0;
}