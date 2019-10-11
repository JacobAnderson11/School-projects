#include<iostream>
#include<list>

using namespace std;
void printList(list<int> input);

void insertionSort(list<int>& input)
{
	cout << "Starting Sort: " << endl;
	list<int>::iterator up;
	list<int>::iterator down, current;
	
	for (up = input.begin(); up != input.end(); up++)
	{
		int key = *up; 

		for(current = input.begin(); current != input.end();current ++)
		{
			if (*current < key)
			{
				down = up;
				while (down != input.begin() && *down < *current)
				{
					down--;
				}
				int temp = *down;
				*down = *current;
				*current = temp;
			}
		}
	}

}

void printList(list<int> input) 
{
	cout << "The list has a size of: " << input.size() << endl;

	list<int>::iterator print;
	for (print = input.begin(); print != input.end(); print++)
	{
		cout << "The current node is: " << *print << endl;

	}
}

int main()
{
	list<int> input;

	for (int i = 0; i < 100; i++)
	{
		input.push_back(rand()%100);
	}
	cout << "the list is: " << endl; 
	printList(input);

	insertionSort(input);

	cout << "The list after sorting is: " << endl;
	printList(input);
}
