
//Jacob Anderson, Brian Davis
#include<iostream>
#include<string>
#include<stack>
#include<sstream>
#include<math.h>

using namespace std;

class StatementParser //Class declaration.
{
public:

	void parser(string input) //increments through the string
	{
		int i;
		int n;
		string substring; // used to break up the input into smaller parts for pushing onto the op stack.
		stack<string> parenth; // stack to keep track of parethesis and make sure the expression is balanced.

		bool isNum = false; //keeps track of if the last element was a number.
		bool isBiOp = false; //keeps track of if the last element was a binary op.
		bool isUnOp = false; // keeps track of if the last element was a unary op.

		if (input[0] == ')' || input[0] == ']' || input [0] == '}') // checks that the first index is not a closed parenth
		{
			cout << "Error. Cannot start with a closed paranthesis at index 0." << endl;
			isValid = false;
		}
		if (input[0] == '&' || input[0] == '|' || input[0] == '*' || input[0] == '^' || input[0] == '%' || input[0] == '/') //checks that the first index is not a binary operator.
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

		for (i = 0; i < input.size(); i++) // increments through the string.
		{
			cout << "i is: " << i << endl;

			if (isValid == true)
			{
				switch (input[i])
				{
				case ' ':
					cout << "This index is blank and will be skipped." << endl; // skips blank spaces.
					break;
				case '+':
					if (input[i + 1] == '+') //checks if its addition or an increment.
					{
						isUnOp = true; 
						if (isNum == true) //checks to make sure a number comes before the increment.
						{
							cout << "Error: Cannot have unary operator after number at index: " << i << endl;
							isValid = false;
						}

						substring = input.substr(i, 2);
						if (op.empty() == true || getPriority(op.top()) <= getPriority(substring)) //Compares the priority of the op to the op on the top of the stack.
						{
							cout << "The op being pushed onto the op stack is: " << substring << endl;
							op.push(substring);
							i++;
							break;
						}
						else if (op.empty() == false && getPriority(op.top()) > getPriority(substring))
						{
							performOp(substring); // Performs operation
							cout << "The op being pushed onto the op stack is: " << substring << endl;
							op.push(substring);
							i++;
							break;
						}
					}
					else
					{
						if (isNum == false) //checks that there is a number before the binary op.
						{
							cout << "Error. Please put a number before the binary operator at index: " << i << endl;
							isValid = false;
							break;
						}
						if (isUnOp == true) //checks that there isn't a unary op before the binary op.
						{
							cout << "Error. Cannot have a binary operator next to a unary operator at index: " << i << endl;
							isValid = false;
							break;
						}
						if (isBiOp == true) // checks if there are 2 binary ops back to back.
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
					if (input[i + 1] == '-') // checks to see if its a decrement
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
					else if (isNum == false && input[i + 1] != '-') // checks to see if its a negative sign.
					{
						isUnOp = true;
						op.push("NEG");
						cout << "The op being pushed onto the op stack is: NEG" << endl;
					}
					else 
					{
						if (isNum = false)
						{
							cout << "Error. Please put a number before the binary operator at index: " << i << endl;
							isValid = false;
							break;
						}
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
					if (isNum == false)
					{
						cout << "Error. Please put a number before the binary operator at index: " << i << endl;
						isValid = false;
						break;
					}
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
					if (isNum == false)
					{
						cout << "Error. Please put a number before the binary operator at index: " << i << endl;
						isValid = false;
						break;
					}
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
					if (isNum == false)
					{
						cout << "Error. Please put a number before the binary operator at index: " << i << endl;
						isValid = false;
						break;
					}
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
					if (isNum == false)
					{
						cout << "Error. Please put a number before the binary operator at index: " << i << endl;
						isValid = false;
						break;
					}
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
					if (isNum == false) 
					{
						cout << "Error. Please put a number before the binary operator at index: " << i << endl;
						isValid = false;
						break;
					}
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
					if (input[i + 1] == '&') // checks to make sure the && symbol is complete.
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
					if (isNum == false) 
					{
						cout << "Error. Please put a number before the binary operator at index: " << i << endl;
						isValid = false;
						break;
					}
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
					if (input[i + 1] == '|') // checks that the || symbol is complete
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
					if (input[i + 1] == '=') //checks if its != or just !
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
					if (isNum == false)
					{
						cout << "Error. Please put a number before the binary operator at index: " << i << endl;
						isValid = false;
						break;
					}
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
					if (input[i + 1] == '=') //checks to see if the == is complete
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

					parenth.push(substring); //pushes a '(' onto the parenth stack.

					cout << "The op being pushed onto the op stack is: " << substring << endl;
					op.push(substring); // pushes the open parenth onto the op stack no matter what.

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
					if (parenth.empty() || parenth.top() == "[" || parenth.top() == "{") // checks that the last opne parinth matches the current closed parinth.
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
					if (isNum == false)
					{
						cout << "Error. Please put a number before the binary operator at index: " << i << endl;
						isValid = false;
						break;
					}
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
					if (input[i + 1] == '=') // checks if <= || just <
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
					if (isNum == false)
					{
						cout << "Error. Please put a number before the binary operator at index: " << i << endl;
						isValid = false;
						break;
					}
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

					if (istringstream(substring) >> n) // if the string can be read into an in push that int on the stack
					{
						cout << "The number being pushed onto the num stack is: " << n << endl;
						num.push(n);
						substring = to_string(n);
						i = i + substring.size() - 1;
					}
					else //else its an unrecognized character.
					{
						cout << "Error unrecognized character at index: " << i << endl;
						isValid = false;
					}
				}
			}
			else if (isValid == false) //if the input is invalid break out of the loop.
			{
				break;
			}
		}
		if (parenth.empty() == false)  //checks that all of the open parinths have closed parinths.
		{
			cout << "Error: Unbalanced parenthesis at index " << i << endl;
			isValid = false;
		}
		while (op.empty() == false && num.empty() == false && isValid == true) // if the input is valid and non of the stacks are empty
		{
			cout << "Performing Operation: " << endl;
			performOp(substring);
		}

		if (num.empty() == false && isValid == true) // if num isn't empty then result = num.top()
			cout << endl << "The result is: " << num.top() << endl;

	}

private:
	bool isValid = true; //flag to keep track if the input is valid.
	stack<int> num; //stack for operands, assumed to be ints
	stack<string> op; // stack for ops. string to accomidate multi character operations like &&

	int getPriority(string op) //returns the priority of the operation
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
		else if (op == "{" || op == "}")
		{
			return 0;
		}
		else if (op == "[" || op == "]")
		{
			return 0;
		}
	}

	void performOp(string OP) //performs the operation.
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
				cout << "Error division by 0!" << endl; //checks for division by zero.
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
			performOp(OP); //if priority of the top of the stack is less than the priority of what we are proccessing call performOp again.
		}
	}
};

int main()
{
	string input;

	cout << "Please input an expression: "; //gets input
	getline(cin, input);

	StatementParser Example;

	Example.parser(input); 

	system("pause");
	return 0;

}