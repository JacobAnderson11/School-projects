//Jacob Anderson, Brian Davis
#include<iostream>
#include<string>
#include<stack>
#include<sstream>

using namespace std;

void parser(string input, stack<string>& op, stack<int>& num)
{
	int i;
	int n;
	string substring;

	for (i = 0; i < input.size(); i++)
	{
		cout << "Enter the for loop: " << endl;
		cout << "i is: " << i << endl;

		switch (input[i])
		{ 
		case ' ':
			cout << "The string is: " << input << endl;
			cout << "the section being erased is: " << input.substr(0, 1) << endl;
			input.erase(0, 1);
			cout << "the new string is: " << input << endl;
			i = -1;
			break;
		case '+':
			if (input[i + 1] == '+')
			{
				substring = input.substr(i, 2);
				cout << "The op being pushed onto the op stack is: " << substring << endl;
				op.push(substring);
				cout << "The string is: " << input << endl;
				cout << "the section being erased is: " << input.substr(0, 2) << endl;
				input.erase(0, 2);
				cout << "the new string is: " << input << endl;
			}
			else
			{
				substring = input.substr(i, 1);
				cout << "The op being pushed onto the op stack is: " << substring << endl;
				op.push(substring);
				cout << "The string is: " << input << endl;
				cout << "the section being erased is: " << input.substr(0, 1) << endl;
				input.erase(0, 1);
				cout << "the new string is: " << input << endl;
			}

			i = -1;
			break;
		case '-':
			if (input[i + 1] == '-' )
			{
				substring = input.substr(i, 2);
				cout << "The op being pushed onto the op stack is: " << substring << endl;
				op.push(substring);
				cout << "The string is: " << input << endl;
				cout << "the section being erased is: " << input.substr(0,2) << endl;
				input.erase(0, 2);
				cout << "the new string is: " << input << endl;
			}
			else
			{
				substring = input.substr(i, 1);
				cout << "The op being pushed onto the op stack is: " << substring << endl;
				op.push(substring);

				cout << "The string is: " << input << endl;
				cout << "the section being erased is: " << input.substr(0, 1) << endl;
				input.erase(0, 1);
				cout << "the new string is: " << input << endl;
			}

			i = -1;
			break;
		case '*':
			substring = input.substr(i, 1);
			cout << "The op being pushed onto the op stack is: " << substring << endl;
			op.push(substring);

			cout << "The string is: " << input << endl;
			cout << "the section being erased is: " << input.substr(0, 1) << endl;
			input.erase(0, 1);
			cout << "the new string is: " << input << endl;
			i = -1;
			break;
		case '/':
			substring = input.substr(i, 1);
			cout << "The op being pushed onto the op stack is: " << substring << endl;
			op.push(substring);

			cout << "The string is: " << input << endl;
			cout << "the section being erased is: " << input.substr(0, 1) << endl;
			input.erase(0, 1);
			cout << "the new string is: " << input << endl;
			i = -1;
			break;
		case '%':
			substring = input.substr(i, 1);
			cout << "The op being pushed onto the op stack is: " << substring << endl;
			op.push(substring);

			cout << "The string is: " << input << endl;
			cout << "the section being erased is: " << input.substr(0, 1) << endl;
			input.erase(0, 1);
			cout << "the new string is: " << input << endl;
			i = -1;
			break;
		case '^':
			substring = input.substr(i, 1);
			cout << "The op being pushed onto the op stack is: " << substring << endl;
			op.push(substring);

			cout << "The string is: " << input << endl;
			cout << "the section being erased is: " << input.substr(0, 1) << endl;
			input.erase(0, 1);
			cout << "the new string is: " << input << endl;
			i = -1;
			break;
		case '&':
			if (input[i + 1] == '&')
			{
				cout << "The op being pushed onto the op stack is: " << input.substr(i, 2) << endl;
				op.push(input.substr(i, 2));
			
				cout << "The string is: " << input << endl;
				cout << "the section being erased is: " << input.substr(0, 2) << endl;
				input.erase(0, 2);
				cout << "the new string is: " << input << endl;
			}
			i = -1;
			break;
		case '|':

			if (input[i + 1] == '|')
			{
				substring = input.substr(i, 2);
				cout << "The op being pushed onto the op stack is: " << substring << endl;
				op.push(substring);
			}
			cout << "The string is: " << input << endl;
			cout << "the section being erased is: " << input.substr(0,2) << endl;
			input.erase(0, 2);
			cout << "the new string is: " << input << endl;
			i = -1;
			break;
		case '!':
			
			substring = input.substr(i, 1);
			cout << "The op being pushed onto the op stack is: " << substring << endl;
			op.push(substring);
			cout << "The string is: " << input << endl;
			cout << "the section being erased is: " << input.substr(0, 1) << endl;
			input.erase(0, 1);
			cout << "the new string is: " << input << endl;
			i = -1;
			break;
		case '=':
			if (input[i + 1] == '=')
			{
				cout << "The op being pushed onto the op stack is: " << input.substr(i, 2) << endl;
				op.push(input.substr(i, 2));

				cout << "The string is: " << input << endl;
				cout << "the section being erased is: " << input.substr(0, 2) << endl;
				input.erase(0, 2);
				cout << "the new string is: " << input << endl;
			}
			i = -1;
			break;
		case '(':
			substring = input.substr(i, 1);
			cout << "The op being pushed onto the op stack is: " << substring << endl;
			op.push(substring);

			cout << "The string is: " << input << endl;
			cout << "the section being erased is: " << input.substr(0, 1) << endl;
			input.erase(0, 1);
			cout << "the new string is: " << input << endl;
			i = -1;
			break;
		case ')':
			substring = input.substr(i, 1);
			cout << "The op being pushed onto the op stack is: " << substring << endl;
			op.push(substring);

			cout << "The string is: " << input << endl;
			cout << "the section being erased is: " << input.substr(0, 1) << endl;
			input.erase(0, 1);
			cout << "the new string is: " << input << endl;
			i = -1;
			break;
			break;
		case '<':
			if (input[i + 1] == '=')
			{
				substring = input.substr(i, 2);
				cout << "The op being pushed onto the op stack is: " << substring << endl;
				op.push(substring);
				cout << "The string is: " << input << endl;
				cout << "the section being erased is: " << input.substr(0, 2) << endl;
				input.erase(0, 2);
				cout << "the new string is: " << input << endl;
			}
			else
			{
				substring = input.substr(i, 1);
				cout << "The op being pushed onto the op stack is: " << substring << endl;
				op.push(substring);
				cout << "The string is: " << input << endl;
				cout << "the section being erased is: " << input.substr(0, 1) << endl;
				input.erase(0, 1);
				cout << "the new string is: " << input << endl;
			}

			i = -1;
			break;
			break;
		case '>':
			if (input[i + 1] == '=')
			{
				substring = input.substr(i, 2);
				cout << "The op being pushed onto the op stack is: " << substring << endl;
				op.push(substring);
				cout << "The string is: " << input << endl;
				cout << "the section being erased is: " << input.substr(0, 2) << endl;
				input.erase(0, 2);
				cout << "the new string is: " << input << endl;
			}
			else
			{
				substring = input.substr(i, 1);
				cout << "The op being pushed onto the op stack is: " << substring << endl;
				op.push(substring);
				cout << "The string is: " << input << endl;
				cout << "the section being erased is: " << input.substr(0, 1) << endl;
				input.erase(0, 1);
				cout << "the new string is: " << input << endl;
			}

			i = -1;
			break;
		default:
			cout << "The string is: " << input << endl;
			if (istringstream(input) >> n)
			{
				cout << "n = " << n << endl;
 				cout << "The string being pushed onto the num stack is: " << n << endl;
				num.push(n);
				substring = to_string(n);
				cout << "the section being deleted is: " << input.substr(0, substring.size()) << endl;
				input.erase(0, substring.size());
				cout << "the new string is: " << input << endl;
				i = -1;
			} 
		
		}
		cout << "end loop: " << endl;
	}
	cout << "exit the loop: " << endl;
}

int main() 
{
	stack<int> num;
	stack<string> op;

	string input;

	cout << "Please input an expression: ";
	getline(cin, input);

	parser(input, op, num);

	if (op.empty() == false || num.empty() == false)
	{
		cout << "The top of the num stack is: " << num.top() << endl;
		cout << "The size of the num stack is: " << num.size() << endl;
		cout << "the top of the op stack is: " << op.top() << endl;
		cout << "The size of the op stack is: " << op.size() << endl;
	}
}
