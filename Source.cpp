#include<iostream>
#include<sstream>
#include<set>
#include<vector>
#include<string>
#include<cstdlib>


using namespace std;


struct node
{
	int state;
	int weight;
	char move;
	node* u;
	node* d;
	node* l;
	node* r;
	node* parent;
};

node* new_node()
{
	node* temp = new node;
	temp->state = NULL;
	temp->weight = NULL;
	temp->move = ' ';
	temp->u = NULL;
	temp->d = NULL;
	temp->l = NULL;
	temp->r = NULL;
	temp->parent = NULL;

	return temp;

}

class priority_queue
{
public:
	node* top() 
	{
		return container[0];
	}
	void pop()
	{

	}
	void push(node*& input)
	{
		container.push_back(input);
	}
	bool empty()
	{
		return container.empty();
	}
private:

	vector<node*> container;

	void heapify()
	{

	}

};




class gameboard
{
public: 
	void set_board(const int& input)
	{
		start_state = input;
		solve(input);

	}

private:
	int start_state;
	int goal_state = 123456780;

	string num = "012345678";
	int desired_x[9] = { 3,1,2,3,1,2,3,1,2 };
	int desired_y[9] = { 3,1,1,1,2,2,2,3,3 };
	int index_x[9] = { 1,2,3,1,2,3,1,2,3};
	int index_y[9] = { 1,1,1,2,2,2,3,3,3};

	node* parent;
	int zero_index;

	
	priority_queue open;
	set<int> closed;

	string convert_to_string(int num)
	{
		string temp = to_string(num);

		return temp;
	}

	int convert_to_int(string input)
	{
		int temp;
	istringstream iss(input);
	iss >> temp;

	return  temp;
	}

	bool is_visited(int i)
	{

	}

	int search(char target)
	{
		for (int i = 0; i < num.size(); i++)
		{
			if (num[i] == target)
				return i;
		}
	}

	void solve(const int& input)
	{
		parent = new_node();
		parent->state = input;
		parent->weight = get_weight(parent->state);

		closed.insert(parent->state);

		make_children(parent);

		

	}

	int get_weight(int input)
	{
		string temp = convert_to_string(input);
		int x = 0;
		int y = 0;
		int total = 0;

		for (int i = 0; i < temp.size(); i++)
		{
			int a = search(temp[i]);

			x = abs(index_x[i] - desired_x[a]);
			y = abs(index_y[i] - desired_y[a]);
			total = total + x + y;
		
		}

		return total;
	}

	void make_children(node*& parent)
	{
		string temp = convert_to_string(parent->state);

		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] == 0);
			zero_index = i;
		}

		switch (zero_index)
		{
		case 0:
			parent->r = generate_right(temp);
			parent->d = generate_down(temp);
		case 1:
			parent->l = generate_left(temp);
			parent->r = generate_right(temp);
			parent->d = generate_down(temp);
		case 2:
			parent->l = generate_left(temp);
			parent->d = generate_down(temp);
		case 3:
			parent->u = generate_up(temp);
			parent->l = generate_left(temp);
			parent->d = generate_down(temp);
		case 4:
			parent->u = generate_up(temp);
			parent->r = generate_right(temp);
			parent->l = generate_left(temp);
			parent->d = generate_down(temp);
		case 5:
			parent->u = generate_up(temp);
			parent->d = generate_down(temp);
			parent->l = generate_left(temp);
		case 6:
			parent->u = generate_up(temp);
			parent->r = generate_right(temp);
		case 7:
			parent->u = generate_up(temp);
			parent->r = generate_right(temp);
			parent->l = generate_left(temp);
		case 8:
			parent->u = generate_up(temp);
			parent->l = generate_left(temp);
		};

		if (parent->l != NULL)
			parent->l->parent = parent;
		if (parent->r != NULL)
			parent->r->parent = parent;
		if (parent->u != NULL)
			parent->u->parent = parent;
		if (parent->d != NULL)
			parent->d->parent = parent;


	};

	node* generate_up(string input)
	{
		swap(input[zero_index], input[zero_index - 3]);
	};
	node* generate_down(string input)
	{
		swap(input[zero_index], input[zero_index + 3]);
	};
	node* generate_left(string input)
	{
		swap(input[zero_index], input[zero_index - 1]);
	};
	node* generate_right(string input)
	{
		swap(input[zero_index], input[zero_index + 1]);

	};

	};


int main()
{
	/*
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 1;
	set<int> closed;

	closed.insert(a);
	closed.insert(b);
	closed.insert(d);
	cout << closed.count(1);
	cout << closed.count(8);
	*/


	system("pause");
	return 0;
}