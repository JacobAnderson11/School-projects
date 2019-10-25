#include<iostream>
#include<string>
#include<map>
#include<fstream>

using namespace std;

struct node
{
	char letter;
	string code;
	node* left;
	node* right;

};

class morse_code
{
public:
	morse_code()
	{
		setroot();
		build_map();

		map<char, string>::iterator itr;

		for (itr = key.begin(); itr != key.end(); itr++)
		{
			build_tree(root, itr->first, itr->second, 0);
		}
	}

	string encode(string input)
	{
		result = "";
		for (int i = 0; i < input.size(); i++)
		{
			char temp = input[i];
			temp = tolower(temp);
			searchMap(temp);
		}

		return result;
	}
	void decode(string input)
	{
		result = "";
			
	}
	void printKeyTree()
	{
		printtree(root);
	}

private:
	map<char, string> key;
	node* root;
	string result;

	void setroot()
	{
		root = new node;
		root->left = NULL;
		root->right = NULL;
		root->letter = ' ';
		root->code = "";

	}

	void printtree(node* root)
	{
		if (root != NULL)
		{ 
			cout << root->letter << endl;
			printtree(root->left);
			printtree(root->right);
		}
	}

	void searchMap(char input)
	{
		map<char, string>::iterator itr;

		for (itr = key.begin(); itr != key.end(); itr++)
		{
			if (itr->first == input)
			{
				result += itr->second;
				result += " ";
			}
		}
	}

	void build_map()
	{
		ifstream keyFile;
		keyFile.open("morse.txt");
		char letter;
		string code;
		if (keyFile.is_open())
		{
			while (getline(keyFile, code))
			{
				letter = code[0];
				code = code.substr(1);

				key.insert(pair<char,string>(letter, code));

			}

			keyFile.close();

		}

	}

	void build_tree(node* root, char letter, string code, int i)
	{
		if (i < code.size())
		{
			if (code[i] == '.')
			{
				if (root->left == NULL)
				{ 
					root->left = new node;
					root->left->left = NULL;
					root->left->right = NULL;
					build_tree(root->left, letter, code, i + 1);

				}
				else
				{
					build_tree(root->left, letter, code, i + 1);
				}
			}
			if (code[i] == '_')
			{
				if (root->right == NULL)
				{
					root->right = new node;
					root->right->left = NULL;
					root->right->right = NULL;
					build_tree(root->right, letter, code, i + 1);

				}
				else
				{
					build_tree(root->right, letter, code, i + 1);
				}
			}
		}
		else
		{
			root->letter = letter;
			root->code = code;
		}
	}

};

int main()
{

	morse_code example;

	cout << example.encode("Please Help") << endl;

	system("pause");
	return 0;
}