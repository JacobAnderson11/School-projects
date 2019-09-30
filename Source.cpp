//Jacob Anderson, Brian Davis
#include<iostream>
#include<string>
#include<stack>
#include<sstream>
#include<math.h>

using namespace std;

class StatementParser
{
	public:

	void parser(string input)
	{
		int i;
		int n;
		string substring;
		stack<string> parenth;

		bool isNum = false;
		bool isBiOp = false;
		bool isUnOp = false;

		if (input[0] == ')')
		{
			cout << "Error. Cannot start with a closed paranthesis at index 0." << endl;
			isValid = false;
		}
		if (input[0] == '&' || input[0] == '|' || input[0] == '*' || input[0] == '^' || input[0] == '%' || input[0] == '/')
		{
			cout << "Error. Cannot start with a binary operator at index 0." << endl;
			isValid = false;
		}
		if (input[0] == '>' || input[0] == '<' || input[0] == '=')
		{
			cout << "Error. Cannot start with a binary operator at index 0." << endl;
			isValid = false;
		}
		if (input[0] == '!' && input[1] == '=')
		{
			cout << "Error. Cannot start with a binary operator at index 0." << endl;
			isValid = false;
		}
		if (input[0] == '+' && input[1] != '+')
		{
			cout << "Error. Cannot start with a binary operator at index 0." << endl;
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
					if (input[i + 1] == '+')
					{
						isUnOp = true;
						if (isNum == true)
						{
							cout << "Error: Cannot have unary operator after number at index: " << i << endl;
							isValid = false;
						}

						substring = input.substr(i, 2);
						if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
						{
							cout << "The op being pushed onto the op stack is: " << substring << endl;
							op.push(substring);
							i++;
							break;
						}
						else if (op.empty() == false && getPriority(op.top()) > getPriority(substring))
						{
							performOp(substring);
							cout << "The op being pushed onto the op stack is: " << substring << endl;
							op.push(substring);
							i++;
							break;
						}
					}
					else if (input[i + 1] != '+')
					{
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
						isUnOp = false;
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
							performOp(substring);
							cout << "The op being pushed onto the op stack is: " << substring << endl;
							op.push(substring);

							break;
						}
					}

					break;
				case '-':
					if (input[i + 1] == '-')
					{
						if (isNum == true)
						{
							cout << "Error: Cannot have unary operator after number at index: " << i << endl;
							isValid = false;
						}

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
							performOp(substring);
							cout << "The op being pushed onto the op stack is: " << substring << endl;
							op.push(substring);
							i++;
							break;
						}
					}
					else if (isNum == false && input[i + 1] != '-')
					{
						isUnOp = true;
						op.push("NEG");
						cout << "The op being pushed onto the op stack is: NEG" << endl;
					}
					else
					{
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
						isUnOp = false;
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
							performOp(substring);
							cout << "The op being pushed onto the op stack is: " << substring << endl;
							op.push(substring);
							break;
						}
					}
					break;
				case '*':
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
					isUnOp = false;
					substring = input.substr(i, 1);
					if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
					{
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						break;
					}
					else if (getPriority(op.top()) > getPriority(substring))
					{
						performOp(substring);
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						break;
					}
					break;
				case '/':
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
					isUnOp = false;
					substring = input.substr(i, 1);
					if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
					{
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						break;
					}
					else if (getPriority(op.top()) > getPriority(substring))
					{
						performOp(substring);
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						break;
					}
					break;
				case '%':
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
					isUnOp = false;
					substring = input.substr(i, 1);
					if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
					{
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						break;
					}
					else if (getPriority(op.top()) > getPriority(substring))
					{
						performOp(substring);
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						break;
					}
					break;
				case '^':
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
					isUnOp = false;
					substring = input.substr(i, 1);
					if (op.empty() == true || getPriority(op.top()) <= getPriority(substring))
					{
						cout << "The op being pushed onto the op stack is: " << substring << endl;
						op.push(substring);
						break;
					}
					else if (getPriority(op.top()) > getPriority(substring))
					{
						performOp(substring);
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
					isUnOp = false;
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
							performOp(substring);
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
					isUnOp = false;
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
							performOp(substring);
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
					isUnOp = false;
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
							performOp(substring);
							cout << "The op being pushed onto the op stack is: " << substring << endl;
							op.push(substring);
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
							performOp(substring);
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
					isUnOp = false;
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
							performOp(substring);
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
					isUnOp = false;

					substring = input.substr(i, 1);

					parenth.push(substring);

					cout << "The op being pushed onto the op stack is: " << substring << endl;
					op.push(substring);

					break;
				case '[':
					isUnOp = false;

					substring = input.substr(i, 1);

					parenth.push(substring);

					cout << "The op being pushed onto the op stack is: " << substring << endl;
					op.push(substring);

					break;
				case '{':
					isUnOp = false;

					substring = input.substr(i, 1);

					parenth.push(substring);

					cout << "The op being pushed onto the op stack is: " << substring << endl;
					op.push(substring);

					break;
				case ')':
					if (parenth.empty() || parenth.top() == "[" || parenth.top() == "{")
					{
						cout << "Error unmatched parenthesis at index: " << i << endl;
						isValid = false;
					}
					else
					{
						parenth.pop();
					}
					substring = input.substr(i, 1);

					performOp(substring);

					break;
				case ']':
					if (parenth.empty() || parenth.top() == "(" || parenth.top() == "{")
					{
						cout << "Error unmatched parenthesis at index: " << i << endl;
						isValid = false;
					}
					else
					{
						parenth.pop();
					}
					substring = input.substr(i, 1);

					while (op.empty() == false && getPriority(op.top()) > getPriority(substring))
					{
						cout << "Performing operation" << endl;
						performOp(substring);
					}
					break;
				case '}':
					if (parenth.empty() || parenth.top() == "[" || parenth.top() == "(")
					{
						cout << "Error unmatched parenthesis at index: " << i << endl;
						isValid = false;
					}
					else
					{
						parenth.pop();
					}
					substring = input.substr(i, 1);

					performOp(substring);

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
							performOp(substring);
							cout << "The op being pushed onto the op stack is: " << substring << endl;
							op.push(substring);
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
							performOp(substring);
							cout << "The op being pushed onto the op stack is: " << substring << endl;
							op.push(substring);
							break;
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
							performOp(substring);
							cout << "The op being pushed onto the op stack is: " << substring << endl;
							op.push(substring);
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
							performOp(substring);
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
						cout << "The number being pushed onto the num stack is: " << n << endl;
						num.push(n);
						substring = to_string(n);
						i = i + substring.size() - 1;
					}
					else
					{
						cout << "Error unrecognized character at index: " << i << endl;
						isValid = false;
					}
				}
			}
			else if (isValid == false)
			{
				break;
			}
		}
		if (parenth.empty() == false)
		{
			cout << "Error: Unbalanced parenthesis at index " << i << endl;
			isValid = false;
		}
		while (op.empty() == false && num.empty() == false && isValid == true)
		{
			cout << "Performing Operation: " << endl;
			performOp(substring);
		}

		if (num.empty() == false && isValid == true)
			cout << endl << "The result is: " << num.top() << endl;

	}

	private:
	bool isValid = true;
	stack<int> num;
	stack<string> op;

	int getPriority(string op)
	{
		if (op == "(" || op == ")")
		{
			return 0;
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
		else if (op == "NEG")
		{
			return 8;
		}
		else
		{
			return 0;
		}
	}

	void performOp(string OP)
	{
		int rightNum, leftNum;
		int result;
		cout << "Calculating: " << endl;

		if (op.top() == "+")
		{
			rightNum = num.top();
			num.pop();
			leftNum = num.top();
			num.pop();
			result = rightNum + leftNum;
			cout << "the result of the calculation is: " << result << endl;
			num.push(result);
		}
		if (op.top() == "-")
		{
			rightNum = num.top();
			num.pop();
			leftNum = num.top();
			num.pop();
			result = leftNum - rightNum;
			cout << "the result of the calculation is: " << result << endl;
			num.push(result);
		}
		if (op.top() == "++")
		{
			rightNum = num.top();
			num.pop();
			result = rightNum + 1;
			cout << "the result of the calculation is: " << result << endl;
			num.push(result);
		}
		if (op.top() == "--")
		{
			rightNum = num.top();
			num.pop();
			result = rightNum - 1;
			cout << "the result of the calculation is: " << result << endl;
			num.push(result);
		}
		if (op.top() == "*")
		{
			rightNum = num.top();
			num.pop();
			leftNum = num.top();
			num.pop();
			result = rightNum * leftNum;
			cout << "the result of the calculation is: " << result << endl;
			num.push(result);
		}
		if (op.top() == "/")
		{
			rightNum = num.top();
			num.pop();
			leftNum = num.top();
			num.pop();
			if (rightNum != 0)
			{
				result = leftNum / rightNum;
				cout << "the result of the calculation is: " << result << endl;
				num.push(result);
			}
			else
			{
				cout << "Error division by 0!" << endl;
				isValid = false;
			}
		}
		if (op.top() == "%")
		{
			rightNum = num.top();
			num.pop();
			leftNum = num.top();
			num.pop();
			result = leftNum % rightNum;
			cout << "the result of the calculation is: " << result << endl;
			num.push(result);

		}
		if (op.top() == "^")
		{
			rightNum = num.top();
			num.pop();
			leftNum = num.top();
			num.pop();
			result = pow(leftNum, rightNum);
			cout << "the result of the calculation is: " << result << endl;
			num.push(result);

		}
		if (op.top() == ">")
		{
			rightNum = num.top();
			num.pop();
			leftNum = num.top();
			num.pop();
			result = leftNum > rightNum;
			cout << "the result of the calculation is: " << result << endl;
			num.push(result);

		}
		if (op.top() == ">=")
		{
			rightNum = num.top();
			num.pop();
			leftNum = num.top();
			num.pop();
			result = leftNum >= rightNum;
			cout << "the result of the calculation is: " << result << endl;
			num.push(result);

		}
		if (op.top() == "<")
		{
			rightNum = num.top();
			num.pop();
			leftNum = num.top();
			num.pop();
			result = leftNum < rightNum;
			cout << "the result of the calculation is: " << result << endl;
			num.push(result);
		}
		if (op.top() == "<=")
		{
			rightNum = num.top();
			num.pop();
			leftNum = num.top();
			num.pop();
			result = leftNum <= rightNum;
			cout << "the result of the calculation is: " << result << endl;
			num.push(result);
		}
		if (op.top() == "==")
		{
			rightNum = num.top();
			num.pop();
			leftNum = num.top();
			num.pop();
			result = leftNum == rightNum;
			cout << "the result of the calculation is: " << result << endl;
			num.push(result);
		}
		if (op.top() == "&&")
		{
			rightNum = num.top();
			num.pop();
			leftNum = num.top();
			num.pop();
			result = leftNum && rightNum;
			cout << "the result of the calculation is: " << result << endl;
			num.push(result);

		}
		if (op.top() == "||")
		{
			rightNum = num.top();
			num.pop();
			leftNum = num.top();
			num.pop();
			result = leftNum || rightNum;
			cout << "the result of the calculation is: " << result << endl;
			num.push(result);
		}
		if (op.top() == "!")
		{
			rightNum = num.top();
			num.pop();

			result = !rightNum;
			cout << "the result of the calculation is: " << result << endl;
			num.push(result);
		}
		if (op.top() == "!=")
		{
			rightNum = num.top();
			num.pop();
			leftNum = num.top();
			num.pop();
			result = leftNum != rightNum;
			cout << "the result of the calculation is: " << result << endl;
			num.push(result);
		}

		if (op.top() == "NEG")
		{
			rightNum = num.top();
			num.pop();

			result = -rightNum;
			cout << "the result of the calculation is: " << result << endl;
			num.push(result);
		}

		op.pop();

		if (op.empty() == false && getPriority(op.top()) > getPriority(OP))
		{
			performOp(OP);
		}
	}
};

int main()
{
	string input;

	cout << "Please input an expression: ";
	getline(cin, input);

	StatementParser Example;

	Example.parser(input);

	system("pause");
	return 0;

}