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
			result += searchMap(temp);


		}

		return result;
	}
	string decode(string input)
	{
		result = "";
		traverse_tree(root, input, 0);
		return result;
	}
	void printKeyTree()
	{
		printtree(root);
	}

private:
	map<char, string> key;
	node* root;
	string result;

	char traverse_tree(node* Node, string input, int i)
	{
		if (i == input.size())
		{
			result += Node->letter;

		}

		if (input[i] == ' ')
		{
			result += Node->letter;

			traverse_tree(root, input, i + 1);
		}
		if (Node->left != NULL && input[i] == '.')
		{
			traverse_tree(Node->left, input, i + 1);
		}
		if (Node->right != NULL && input[i] == '_')
		{
			traverse_tree(Node->right, input, i + 1);
		}

		return ' ';
	}
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

	string searchMap(char input)
	{
		map<char, string>::iterator itr;

		if (valid_input(input))
		{
			return key.at(input) + " ";
		}
		else
			return "";

	}

	bool valid_input(char input)
	{
		switch (input)
		{
		case'a':
		case'b':
		case'c':
		case'd':
		case'e':
		case'f':
		case'g':
		case'h':
		case'i':
		case'j':
		case'k':
		case'l':
		case'm':
		case'n':
		case'o':
		case'p':
		case'q':
		case'r':
		case's':
		case't':
		case'u':
		case'v':
		case'w':
		case'x':
		case'y':
		case'z':
			return true;
		default:
			return false;
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

				key.insert(pair<char, string>(letter, code));

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
	char  Continue;
	char Select;
	string input;

	do
	{
		cout << "Please provide the input: ";
		getline(cin, input);
		cout << endl;	

		cout << "Would you like to encode or decode the input? (e/d) ";
		cin >> Select;
		cout << endl;
		Select = tolower(Select);

		if (Select == 'd')
		{
			cout << "The result is: " << endl << example.decode(input) << endl;
		}
		else if (Select == 'e')
		{
			cout << "The result is: " << endl << example.encode(input) << endl;
		}
		else
			cout << "error unrecognized mode: " << endl;

		cout << " (y/n)";
		cin >> Continue;
		cout << endl;

		Continue = tolower(Continue);

		if (Continue != 'y' || Continue != 'n')
		{
			cout << "Unrecognized input:"
		}

	} while (Continue == 'y');
	system("pause");
	return 0;
}