#include<iostream>
#include<sstream>
#include<set>
#include<vector>
#include<string>
#include<stack>
#include<cstdlib>
#include<fstream>
#include<queue>


using namespace std;


struct node
{
	int state;
	int weight;
	int distance;
	char move;
	node* parent;
};

node* new_node()
{
	node* temp = new node;
	temp->state = NULL;
	temp->weight = NULL;
	temp->distance = NULL;
	temp->move = ' ';
	temp->parent = NULL;

	return temp;

}

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

class Priority_queue
{
public:
	node* top()
	{
		heapify();
		if(!container.empty())
		return container.front();
	}
	void pop()
	{
		swap(container[0], container[container.size() - 1]);
		container.pop_back();

	}
	void push(node*& input)
	{
		container.push_back(input);
	}
	bool empty()
	{
		return container.empty();
	}
	void clear()
	{
		container.clear();
	}
	int size()
	{
		return container.size();
	}
private:

	vector<node*> container;

	void swap(node*& a, node*& b)
	{
		node* temp = a;
		a = b;
		b = temp;

	}

	void heapify()
	{

		for (int i = 0; i < container.size(); i++)
		{
			if (2 * i + 2 < container.size())
			{
				if (container[i]->weight > container[2 * i + 1]->weight)
				{
					swap(container[i], container[2 * i + 1]);
					i = -1;
				}
				else if (container[i]->weight > container[2 * i + 2]->weight)
				{
					swap(container[i], container[2 * i + 2]);
					i = -1;
				}


			}
			else break;
		}
	}

};

class gameboard
{
public:

	gameboard()
	{
	goal_state = 123456789;
	num = "912345678";
	desired_x = { 3,1,2,3,1,2,3,1,2 };
	desired_y = { 3,1,1,1,2,2,2,3,3 };
	index_x = { 1,2,3,1,2,3,1,2,3 };
	index_y = { 1,1,1,2,2,2,3,3,3 };
	}

	string set_board(const int& input)
	{
		cout << "Start: " << input;
		open.clear();
		closed.clear();
		is_solved = false;

		start_state = input;
		node* temp = new_node();
		temp->state = input;
		temp->distance = 0;
		temp->weight = get_weight(input);

		solve(temp);


		while (open.empty() == false && is_solved == false)
		{
			temp = open.top();
			solve(temp);
			open.pop();
		}

		if (is_solved == true)
		{
			get_solution(solution);
			string answer = "";

			while (!solutions.empty())
			{
				answer = answer + solutions.top();
				answer = answer + ' ';
				solutions.pop();
			}

			return answer;

		}
		else
		{
			string answer = "There is no Solution";
			return answer;
		}

		cout << "end" << endl;

	}

private:
	int start_state;
	int goal_state;

	string num;
	vector<int> desired_x;
	vector<int> desired_y;
	vector<int> index_x;
	vector<int> index_y;

	node* parent;
	node* solution;

	int blank_index;

	bool is_solved;


	Priority_queue open;
	set<int> closed;
	stack<char> solutions;

	bool is_visited(int i)
	{
		return closed.count(i);
	}

	int search(char target)
	{
		for (int i = 0; i < num.size(); i++)
		{
			if (num[i] == target)
				return i;
		}
	}

	void solve(node*& input)
	{
		if (input->state != goal_state)
		{
			parent = input;

			closed.insert(input->state);

			make_children(parent);
		}
		else
		{
			cout << "A solution has been found: " << endl;
			solution = input;
			is_solved = true;
		}



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

		blank_index = temp.find('9');

		switch (blank_index)
		{
		case 0:
			generate_right(temp);
			generate_down(temp);
			break;
		case 1:
			generate_left(temp);
			generate_right(temp);
			generate_down(temp);
			break;
		case 2:
			generate_left(temp);
			generate_down(temp);
			break;
		case 3:
			generate_up(temp);
			generate_left(temp);
			generate_down(temp);
			break;
		case 4:
			generate_up(temp);
			generate_right(temp);
			generate_left(temp);
			generate_down(temp);
			break;
		case 5:
			generate_up(temp);
			generate_down(temp);
			generate_left(temp);
			break;
		case 6:
			generate_up(temp);
			generate_right(temp);
			break;
		case 7:
			generate_up(temp);
			generate_right(temp);
			generate_left(temp);
			break;
		case 8:
			generate_up(temp);
			generate_left(temp);
			break;
		};
	};

	void generate_up(string input)
	{
		node* temp = new_node();
		temp->parent = parent;
		temp->move = input[blank_index - 3];
		swap(input[blank_index], input[blank_index - 3]);
		temp->state = convert_to_int(input);
		temp->distance = parent->distance + 1;
		temp->weight = get_weight(temp->state) + temp->distance;

		if (is_visited(temp->state))
		{
			delete temp;
		}
		else
		{
			open.push(temp);
		}

	};

	void generate_down(string input)
	{
		node* temp = new_node();
		temp->parent = parent;
		temp->move = input[blank_index + 3];
		swap(input[blank_index], input[blank_index + 3]);
		temp->state = convert_to_int(input);
		temp->distance = parent->distance + 1;
		temp->weight = get_weight(temp->state) + temp->distance;

		if (is_visited(temp->state))
		{
			delete temp;
		}
		else
		{
			open.push(temp);
		}

	};

	void generate_right(string input)
	{
		node* temp = new_node();
		temp->parent = parent;
		temp->move = input[blank_index + 1];
		swap(input[blank_index], input[blank_index + 1]);
		temp->state = convert_to_int(input);
		temp->distance = parent->distance + 1;
		temp->weight = get_weight(temp->state) + temp->distance;

		if (is_visited(temp->state))
		{
			delete temp;
		}
		else
		{
			open.push(temp);
		}


	};

	void generate_left(string input)
	{
		node* temp = new_node();
		temp->parent = parent;
		temp->move = input[blank_index - 1];
		swap(input[blank_index], input[blank_index - 1]);
		temp->state = convert_to_int(input);
		temp->distance = parent->distance + 1;
		temp->weight = get_weight(temp->state) + temp->distance;

		if (is_visited(temp->state))
		{
			delete temp;
		}
		else
		{
			open.push(temp);
		}

	};

	void get_solution(node*& input)
	{
		if (input->move != ' ')
			solutions.push(input->move);

		if (input->parent != NULL)
			get_solution(input->parent);


	}

};

void remove_spaces(string& input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == ' ')
			input.erase(i,1);
		if (input[i] == '0')
			input[i] = '9';
	
	}
}

void get_input_data(vector<int>& input)
{
	queue<string> data;
	vector<string> placeholder;

	ifstream input_file;
	input_file.open("Input File.txt");
	string state;

	if (input_file.is_open())
	{
		while (getline(input_file, state))
		{
			remove_spaces(state);

			if (state.size() != 0)
				data.push(state);

		}

		input_file.close();

		string temp = "";

		while (!data.empty())
		{
			temp = "";

			for (int i = 0; i < 3; i++)
			{
				temp = temp + data.front();
				data.pop();
			}

			placeholder.push_back(temp);
		}

		for (int i = 0; i < placeholder.size(); i++)
		{
			input.push_back(convert_to_int(placeholder[i]));
		}

	}

}

void write_to_output(vector<string>& input)
{
	ofstream output_file;
	output_file.open("Output File.txt");
	string state;

	if (output_file.is_open())
	{
		for (int i = 0; i < input.size(); i++)
		{
			output_file << input[i] << endl;
		}
	}
}

int main()
{
	gameboard example;

	vector<int> input;
	vector<string> output;

	get_input_data(input);

	for (int i = 0; i < input.size(); i++)
	{
		output.push_back(example.set_board(input[i]));
	}

	write_to_output(output);
	

	system("pause");
	return 0;
}