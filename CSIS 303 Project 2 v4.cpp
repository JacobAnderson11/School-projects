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
			if (valid_input(input[i]) || input[i] == ' ')
			{
				char temp = input[i];
				temp = tolower(temp);
				result += searchMap(temp);
			}
			else
			{
				cout << "Invalid input: " << endl;
				result = "";
				break;
			}


		}

		return result;
	}
	string decode(string input)
	{
		result = "";
		if (valid_decode(input))
		{
			traverse_tree(root, input, 0);
		}
		else 
			cout << "Invalid input: " << endl;
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
	bool valid_decode(string input)
	{
		bool isValid = true;
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] != '.' && input[i] != '_' && input[i] != ' ')
			{
				isValid = false;
			}
			return isValid;
		}
	}
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

		if (input[i] != ' ' && i != input.size() && Node->left == NULL && Node->right == NULL)
		{
			cout << "Invalid input" << endl;
			result = "";
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

		return key.at(input) + " ";


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
			key.insert(pair<char, string>(' ', ""));

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
		input = "";
		do
		{
			cout << "Please provide the input: ";
			getline(cin, input);
			cout << endl;
			system("CLS");
		} while (input.size() == 0);

		do
		{
			cout << "Would you like to encode or decode the input? (e/d) ";
			cin >> Select;
			cout << endl;
			Select = tolower(Select);

			if (Select != 'd' && Select != 'e')
			{
				cout << "Error unrecognized mode. Please try again: " << endl;
				system("pause");
			}

			system("CLS");

		} while (Select != 'd' && Select != 'e');

		string temp;
		if (Select == 'd')
		{
			temp = example.decode(input);
					if (temp.size() != 0)
					{
						cout << "The result is: " << temp << endl;
					}
		}
		else if (Select == 'e')
		{
			temp = example.encode(input);
			if (temp.size() != 0)
			{
				cout << "The result is: " << temp << endl;
			}
		}

		cout << endl;

		cout << "if you would like to stop press n: ";
		cin >> Continue;
		cout << endl;

		Continue = tolower(Continue);

		system("CLS");
	} while (Continue != 'n');


	return 0;
}
