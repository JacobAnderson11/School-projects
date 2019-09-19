#include<iostream>
#include<queue>
#include<string>

using namespace std;

void move_to_rear(queue<int>& input)
{
	int placeholder;

	placeholder = input.front();
	input.pop();
	input.push(placeholder);

}

int main()
{
	queue<int> input;

	for (int i = 0; i < 10; i++)
	{
		cout << "The element " << i << " is being pushed into the queue." << endl;
		input.push(i);
	}

	cout << "The queue has a size of: " << input.size() << endl;
	cout << "The number at the front of the queue is: " << input.front() << endl;
	cout << "The number at the end of the queue is: " << input.back() << endl;

	move_to_rear(input);

	cout << "The queue has a size of: " << input.size() << endl;
	cout << "The number at the front of the queue is: " << input.front() << endl;
	cout << "The number at the end of the queue is: " << input.back() << endl;
}