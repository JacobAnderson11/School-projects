//Jacob Anderson, Brian Davis
#include<iostream>
#include<string>
#include<stack>
#include<sstream>
#include<math.h>

using namespace std;

int getPriority(string op);
void performOp(stack<string>& op, stack<int>& num);
void parser(string input, stack<string>& op, stack<int>& num);

int main()
{

	cout << 4 % 2 << endl;
	string test = "+";
	cout << "the priority of test = " << getPriority(test) << endl;
	stack<int> num;
	stack<string> op;

	string input;

	cout << "Please input an expression: ";
	getline(cin, input);

	parser(input, op, num);
	cout << "The size of the op stack is: " << op.size() << endl;
	cout << "The size of the num stack is: " << num.size() << endl;

	while (op.empty() == false)
	{
		cout << "Performing Operation: " << endl;
		performOp(op, num);
	}

	cout << endl <<  "The result is: " << num.top() << endl;

	system("pause");
	return 0;

}

void parser(string input, stack<string>& op, stack<int>& num)
{
	int i;
	int n;
	string substring;

	bool isNum = false;
	bool isBiOp = false;
	bool isValid = true;
	bool isUnOp = false;

	if (input[0] == ')')
	{
		cout << "Error. Cannot start with a closed paranthesis at index 0." << endl;
		isValid = false;
	}
	if (input[0] == '&' || input[0] == '|')
	{
		cout << "Error. Cannot start with a binary operator at index 0." << endl;
		isValid = false;
	}
	if (input[0] == '>' || input[0] == '<' || input[0] == '=')
	{
		cout << "Error. Cannot start with a comparason operator at index 0." << endl;
		isValid = false;
	}
	if (input[0] == '!' && input[1] == '=')
	{
		cout << "Error. Cannot start with a comparason operator at index 0." << endl;
		isValid = false;
	}
	for (i = 0; i < input.size(); i++)
	{
		cout << "i is: " << i << endl;

		if (isValid == true)
		{
			switch (input[i])
			{
			case ' ':
				cout << "This index is blank and will be skipped." << endl;
				break;
			case '+':
				isBiOp = false;
				isNum = false;
				if (input[i + 1] == '+')
				{
					isUnOp = true;
					substring = input.substr(i, 2);
					if (op.empty() == true || getPriority(op.top()) >= getPriority(substring))
					{
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						i++;

						break;
					}
					else if (op.empty() == false && getPriority(op.top()) < getPriority(substring))
					{

						if (op.empty() == false)
						{
							cout << "Performing operation" << endl;
							performOp(op, num);
						}
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						i++;

						break;
					}
				}
				else if (input[i + 1] != '+')
				{
					substring = input.substr(i, 1);
					if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
					{
						cout << "Case 1" << endl;
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						break;
					}
					else if (getPriority(op.top()) > getPriority(substring))
					{
						while (op.empty() == false)
						{
							cout << "Performing operation" << endl;
							performOp(op, num);
						}
						cout << "case 2" << endl;
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);

						break;
					}
				}

				break;
			case '-':
				isBiOp = false;
				isNum = false;
				if (input[i + 1] == '-')
				{
					isUnOp = true;
					substring = input.substr(i, 2);
					if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
					{
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						i++;
					}
					else if (getPriority(op.top()) > getPriority(substring))
					{
						while (op.empty() == false)
						{
							cout << "Performing operation" << endl;
							performOp(op, num);
						}
					}
				}
				else
				{
					substring = input.substr(i, 1);
					if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
					{
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						break;
					}
					else if (getPriority(op.top()) > getPriority(substring))
					{
						while (op.empty() == false)
						{
							cout << "Performing operation" << endl;
							performOp(op, num);
						}
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);

						break;
					}
				}
				break;
			case '*':
				isUnOp = false;
				isBiOp = false;
				isNum = false;
				substring = input.substr(i, 1);
				if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
				{
					cout << "The op being pushed onto the op stack is: " << substring << endl;
					op.push(substring);
					break;
				}
				else if (getPriority(op.top()) > getPriority(substring))
				{
					while (op.empty() == false)
					{
						cout << "Performing operation" << endl;
						performOp(op, num);
					}

					cout << "The op being pushed onto the op stack is: " << substring << endl;
					op.push(substring);

					break;
				}
				break;
			case '/':
				isUnOp = false;
				isBiOp = false;
				isNum = false;
				substring = input.substr(i, 1);
				if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
				{
					cout << "The op being pushed onto the op stack is: " << substring << endl;
					op.push(substring);
					break;
				}
				else if (getPriority(op.top()) > getPriority(substring))
				{
					while (op.empty() == false)
					{
						cout << "Performing operation" << endl;
						performOp(op, num);
					}
					cout << "The op being pushed onto the op stack is: " << substring << endl;
					op.push(substring);

					break;
				}
				break;
			case '%':
				isUnOp = false;
				isBiOp = false;
				isNum = false;
				substring = input.substr(i, 1);
				if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
				{
					cout << "The op being pushed onto the op stack is: " << substring << endl;
					op.push(substring);
					break;
				}
				else if (getPriority(op.top()) > getPriority(substring))
				{
					while (op.empty() == false)
					{
						cout << "Performing operation" << endl;
						performOp(op, num);
					}
					cout << "The op being pushed onto the op stack is: " << substring << endl;
					op.push(substring);

					break;
				}
				break;
			case '^':
				isUnOp = false;
				isBiOp = false;
				isNum = false;
				substring = input.substr(i, 1);
				if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
				{
					cout << "The op being pushed onto the op stack is: " << substring << endl;
					op.push(substring);
					break;
				}
				else if (getPriority(op.top()) > getPriority(substring))
				{
					while (op.empty() == false)
					{
						cout << "Performing operation" << endl;
						performOp(op, num);
					}
					cout << "The op being pushed onto the op stack is: " << substring << endl;
					op.push(substring);

					break;
				}
				break;
			case '&':
				if (isUnOp == true)
				{
					cout << "Error. Cannot have a binary operator next to a unary operator at index: " << i << endl;
					isValid = false;
					break;
				}
				if (isBiOp == true)
				{
					cout << "Error. Cannot have two binary operators next to each other at index: " << i << endl;
					isValid = false;
					break;
				}
				isBiOp = true;
				isNum = false;
				if (input[i + 1] == '&')
				{
					substring = input.substr(i, 2);
					if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
					{
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						i++;
						break;
					}
					else if (getPriority(op.top()) > getPriority(substring))
					{
						while (op.empty() == false)
						{
							cout << "Performing operation" << endl;
							performOp(op, num);
						}
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						i++;
						break;
					}
				}
				else
				{
					cout << "Error. Incomplete Binary Operator at index: " << i << endl;
					isValid = false;
				}
				break;
			case '|':
				if (isUnOp == true)
				{
					cout << "Error. Cannot have a binary operator next to a unary operator at index: " << i << endl;
					isValid = false;
					break;
				}
				if (isBiOp == true)
				{
					cout << "Error. Cannot have two binary operators next to each other at index: " << i << endl;
					isValid = false;
					break;
				}
				isBiOp = true;
				isNum = false;
				if (input[i + 1] == '|')
				{
					substring = input.substr(i, 2);
					if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
					{
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						i++;
						break;
					}
					else if (getPriority(op.top()) > getPriority(substring))
					{
						while (op.empty() == false)
						{
							cout << "Performing operation" << endl;
							performOp(op, num);
						}
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						i++;
						break;
					}
				}
				else
				{
					cout << "Error. Incomplete Binary Operator at index: " << i << endl;
					isValid = false;
				}
				break;
			case '!':
				if (isUnOp == true)
				{
					cout << "Error. Cannot have a binary operator next to a unary operator at index: " << i << endl;
					isValid = false;
					break;
				}
				if (isBiOp == true)
				{
					cout << "Error. Cannot have two binary operators next to each other at index: " << i << endl;
					isValid = false;
					break;
				}
				isBiOp = true;
				isNum = false;
				if (input[i + 1] == '=')
				{
					substring = input.substr(i, 2);
					if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
					{
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						i++;
						break;
					}
					else if (getPriority(op.top()) > getPriority(substring))
					{
						while (op.empty() == false)
						{
							cout << "Performing operation" << endl;
							performOp(op, num);
						}
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						i++;
						break;
					}
				}
				else
				{
					substring = input.substr(i, 1);
					if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
					{
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						break;
					}
					else if (getPriority(op.top()) > getPriority(substring))
					{
						while (op.empty() == false)
						{
							cout << "Performing operation" << endl;
							performOp(op, num);
						}
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);

						break;
					}
				}
				break;
			case '=':
				if (isUnOp == true)
				{
					cout << "Error. Cannot have a binary operator next to a unary operator at index: " << i << endl;
					isValid = false;
					break;
				}
				if (isBiOp == true)
				{
					cout << "Error. Cannot have two binary operators next to each other at index: " << i << endl;
					isValid = false;
					break;
				}
				isBiOp = true;
				isNum = false;
				if (input[i + 1] == '=')
				{
					substring = input.substr(i, 2);
					if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
					{
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						i++;
						break;
					}
					else if (getPriority(op.top()) > getPriority(substring))
					{
						while (op.empty() == false)
						{
							cout << "Performing operation" << endl;
							performOp(op, num);
						}
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						i++;
						break;
					}
				}
				else
				{
					cout << "Error. Incomplete Comparason Operator at index: " << i << endl;
					isValid = false;
				}
				break;
			case '(':
				isBiOp = true;
				isNum = false;
				substring = input.substr(i, 1);
				if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
				{
					cout << "The op being pushed onto the op stack is: " << substring << endl;
					op.push(substring);
					break;
				}
				else if (getPriority(op.top()) > getPriority(substring))
				{
			
					cout << "The op being pushed onto the op stack is: " << substring << endl;
					op.push(substring);

					break;
				}

				break;
			case ')':

				substring = input.substr(i, 1);
				if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
				{
					cout << "The op being pushed onto the op stack is: " << substring << endl;
					op.push(substring);
					break;
				}
				else if (getPriority(op.top()) > getPriority(substring))
				{
					while (op.empty() == false)
					{
						cout << "Performing operation" << endl;
						performOp(op, num);
					}
					cout << "The op being pushed onto the op stack is: " << substring << endl;
					op.push(substring);

					break;
				}

				break;
			case '<':
				if (isUnOp == true)
				{
					cout << "Error. Cannot have a binary operator next to a unary operator at index: " << i << endl;
					isValid = false;
					break;
				}
				if (isBiOp == true)
				{
					cout << "Error. Cannot have two binary operators next to each other at index: " << i << endl;
					isValid = false;
					break;
				}
				isBiOp = true;
				isNum = false;
				if (input[i + 1] == '=')
				{
					substring = input.substr(i, 2);
					if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
					{
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						i++;
						break;
					}
					else if (getPriority(op.top()) > getPriority(substring))
					{
						while (op.empty() == false)
						{
							cout << "Performing operation" << endl;
							performOp(op, num);
						}
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						i++;
						break;
					}
				}
				else
				{
					substring = input.substr(i, 1);
					if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
					{
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						break;
					}
					else if (getPriority(op.top()) > getPriority(substring))
					{
						while (op.empty() == false)
						{
							cout << "Performing operation" << endl;
							performOp(op, num);
						}
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);

						break;
					}
				}
				break;
			case '>':
				if (isUnOp == true)
				{
					cout << "Error. Cannot have a binary operator next to a unary operator at index: " << i << endl;
					isValid = false;
					break;
				}
				if (isBiOp == true)
				{
					cout << "Error. Cannot have two binary operators next to each other at index: " << i << endl;
					isValid = false;
					break;
				}
				isBiOp = true;
				isNum = false;
				if (input[i + 1] == '=')
				{

					substring = input.substr(i, 2);
					if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
					{
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						i++;
						break;
					}
					else if (getPriority(op.top()) > getPriority(substring))
					{
						while (op.empty() == false)
						{
							cout << "Performing operation" << endl;
							performOp(op, num);
						}
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						i++;
						break;
					}
				}
				else
				{
					substring = input.substr(i, 1);
					if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
					{
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						break;
					}
					else if (getPriority(op.top()) > getPriority(substring))
					{
						while (op.empty() == false)
						{
							cout << "Performing operation" << endl;
							performOp(op, num);
						}
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);

						break;
					}

				}

				break;
			default:
				isUnOp = false;
				isBiOp = false;
				substring = input.substr(i);

				if (isNum == true)
				{
					cout << "Error. Cannot have 2 numbers next to each other at index: " << i << endl;
					bool isValid = false;
					break;
				}
				isNum = true;

				if (istringstream(substring) >> n)
				{
					cout << "n = " << n << endl;
					cout << "The number being pushed onto the num stack is: " << n << endl;
					num.push(n);
					substring = to_string(n);
					i = i + substring.size() - 1;
				}
			}
		}
		else if (isValid == false)
		{
			break;
		}

	}

}

int getPriority(string op)
{
	if (op == "(" || op == ")")
	{
		return 9;
	}
	else if (op == "||")
	{
		return 1;
	}
	else if (op == "&&")
	{


		return 2;
	}
	else if (op == "==" || op == "!=")
	{

		return 3;
	}
	else if (op == ">" || op == "<")
	{
		return 4;
	}
	else if (op == ">=" || op == "<=")
	{
		return 4;
	}
	else if (op == "+" || op == "-")
	{
		return 5;
	}
	else if (op == "*" || op == "/" || op == "%")
	{
		return 6;
	}
	else if (op == "^")
	{
		return 7;
	}
	else if (op == "++" || op == "--")
	{
		return 8;
	}
	else if (op == "!")
	{
		return 8;
	}
	else
	{
		return 0;
	}
}

void performOp(stack<string>& op, stack<int>& num)
{
	int rightNum, leftNum;
	int result;

	if (op.top() == "+")
	{
		rightNum = num.top();
		num.pop();
		leftNum = num.top();
		num.pop();
		result = rightNum + leftNum;


	}
	if (op.top() == "-")
	{
		rightNum = num.top();
		num.pop();
		leftNum = num.top();
		num.pop();
		result = leftNum - rightNum;


	}
	if (op.top() == "++")
	{
		rightNum = num.top();
		num.pop();
		result = rightNum + 1;


	}
	if (op.top() == "--")
	{
		rightNum = num.top();
		num.pop();
		result = rightNum - 1;


	}
	if (op.top() == "*")
	{
		rightNum = num.top();
		num.pop();
		leftNum = num.top();
		num.pop();
		result = rightNum * leftNum;
	

	}
	if (op.top() == "/")
	{
		rightNum = num.top();
		num.pop();
		leftNum = num.top();
		num.pop();
		result = leftNum / rightNum;


	}
	if (op.top() == "%")
	{
		rightNum = num.top();
		num.pop();
		leftNum = num.top();
		num.pop();
		result = leftNum % rightNum;


	}
	if (op.top() == "^")
	{
		rightNum = num.top();
		num.pop();
		leftNum = num.top();
		num.pop();
		result = pow(leftNum,rightNum);


	}
	if (op.top() == ">")
	{
		;
	}
	if (op.top() == ">=")
	{

	}
	if (op.top() == "<")
	{

	}
	if (op.top() == "<=")
	{

	}
	if (op.top() == "==")
	{

	}
	if (op.top() == "&&")
	{

	}
	if (op.top() == "||")
	{

	}
	if (op.top() == "!")
	{

	}

	cout << "the result of the calculation is: " << result << endl;
	num.push(result);
	op.pop();
}