#include<string>
#include<iostream>
#include<stack>
#include<sstream>


using namespace std;

int main()
{
	string input;
	string hold;
	stack<string> output;


	cout << "Please type out a statement: ";
	getline(cin, input);
	cout << endl;

	for (int i = 0; i < input.size(); i++)
	{
		istringstream(input.substr(i)) >> hold;
		output.push(hold);
		i = i + hold.size();

	}

	cout << "the result is: " << endl;

	while (output.empty() == false)
	{
		
		cout << output.top() << " ";
		output.pop();

	}

	return 0;
}