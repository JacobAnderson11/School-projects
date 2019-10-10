#include<iostream>
#include<vector>
#include<cstdlib>


using namespace std;

int linear_search(vector<int> input, int target, int pos_first);

int main()
{
	vector<int> input;
	for (int i = 0; i < 5; i++)
	{
		input.push_back(i);
	}
	for (int k = input.size(); k > 0; k--)
	{
		input.push_back(k);
	}
	cout << "the input vector is: " << endl;
	for (int j = 0; j < input.size(); j++)
	{
		cout << input[j] << " ";
	}

	cout << endl;
	int target =6;
	cout << "The target is " << target << endl;

	int result = linear_search(input,target , input.size() - 1);

	cout << "The target is located at index: " << result << endl;
}

int linear_search(vector<int> input, int target, int pos_last)
{
	cout << "input[i] = " << input[pos_last] << endl;

	
	if (target == input[pos_last])
		return pos_last;
	if (pos_last == 0)
		return -1;
	else
		return linear_search(input, target, pos_last - 1);

}