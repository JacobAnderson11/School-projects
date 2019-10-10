#include<iostream>
#include<string>
#include<sstream>

using namespace std;

void to_number(string input, int i, int result); //recursivly adds any numbers in the given string together 

int main()
{
	string input;
	int i = 0;
	int result = 0;

	cout << "Please provide the input string: ";
	cin >> input;
	cout << endl;

	to_number(input, i, result);

	return 0;
}

void to_number(string input, int i, int result)
{
	if (i > input.size() - 1)
	{
		cout << "the result is: "<< result << endl;
		return;
	}
	else
	{
		int n;

		if (istringstream(input.substr(i, 1)) >> n)
		{
			result = result + n;
		}

		to_number(input, i + 1, result);
	}

}

