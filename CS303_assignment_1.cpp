//Jacob Anderson
#include<iostream>
using namespace std;

void y1_check(int x, int& y1)//function to instert the given n value into the first equation
{
	  y1 = 100 * x + 10;
	cout << "Y1 == " << y1 << endl;
};

void y2_check(int x, int& y2)//function to insert the given n value into the second equation
{
	 y2 = 5 * x * x + 2;
	cout << "Y2 == " << y2 << endl;
}

void compare(int& y1, int& y2)//function to compare the outputs of the two equations for any given n value
{
	if (y1 > y2)
		cout << "Y1 is greater than Y2" << endl << endl;
	else
		cout << "Y2 is greater than Y1" << endl << endl;
}

int main()
{
	int n = 0;
	int y1, y2;

	while (n < 101)
	{
		cout << "N == " << n << endl;
		y1_check( n, y1);
		y2_check( n, y2);
		compare(y1, y2);
		n = n + 10;
	};
	return 0;
}
