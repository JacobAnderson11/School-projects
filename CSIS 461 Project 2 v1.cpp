#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct teacher
{
	string name;
	vector<string> qualifications;
	int classes;

};

teacher* new_teacher()
{
	teacher* temp = new teacher;

	temp->name = "";
	temp->classes = NULL;
	temp->qualifications.clear();

	return temp;
};

struct room
{
	string building;
	int room_number;
	int capacity;

};

room* new_room()
{
	room* temp = new room;

	temp->building = "";
	temp->room_number = NULL;
	temp->capacity = NULL;

	return temp;
};

struct Class
{
	string class_name;
	teacher* instructer;
	room* location;
	int time_slot;
	int expected_enrollment;

};

Class* new_class()
{
	Class* temp = new Class;
	
	temp->instructer = NULL;
	temp->location = NULL;
	temp->class_name = "";
	temp->time_slot = NULL;
	temp->expected_enrollment = NULL;

	return temp;
};

 
class schedule_generator
{
public:

	schedule_generator()
	{
		success = NULL;
		attempts = NULL;
		temperature = 400;
		finish = NULL;
		fitness_current = NULL;
		fitness_next = NULL;

	}

	void add_class(string name, int enrollment)
	{
		Class* temp = new_class();

		temp->class_name = name;
		temp->expected_enrollment = enrollment;

		current.push_back(temp);
	}

	void add_teacher(string name, vector<string> qualifications)
	{
		teacher* temp = new_teacher();

		temp->name = name;
		temp->qualifications = qualifications;

		available_teachers.push_back(temp);
	};

	void add_time_slot(int time)
	{
		time_slot.push_back(time);

	};

	void add_room(string building, int num, int capacity)
	{
		room* temp = new_room();

		temp->building = building;
		temp->room_number = num;
		temp->capacity = capacity;

		available_rooms.push_back(temp);
	};

	void clear_class()
	{
		current.clear();
		next.clear();
	}

	void clear_teacher()
	{
		available_rooms.clear();
	};

	void clear_time_slot()
	{
		time_slot.clear();
	};

	void clear_rooms()
	{
		available_rooms.clear();
	};

	vector<Class*> generate()
	{
		scramble();

		fitness_current = find_fitness(current);

		next = current;


		while (attempts != 4000)
		{
			random_change();
			fitness_next = find_fitness(next);

			if (fitness_next > fitness_current)
			{
				current = next;
				fitness_current = fitness_next;
				success++;
				attempts = 0;

			}
			else
			{
				int difference = (fitness_current - fitness_next)/10 + 1;

				if (rand_num * difference < temperature)
				{
					current = next;
					fitness_current = fitness_next;
					success++;
					attempts = 0;
				}
				else
				{
					attempts++;
				}
			}

			if (success == 400)
			{
				temperature = temperature * .9;
				success = 0;

			}

		}


		return current;
	};


private:
	int success;
	int attempts;
	int fitness_current;
	int fitness_next;
	double temperature;

	vector<Class*> current;
	vector<Class*> next;

	vector<int> time_slot;
	vector<room*> available_rooms;
	vector<teacher*> available_teachers;

	void scramble()
	{
		for (int i = 0; i < current.size(); i ++)
		{
			current[i]->instructer = available_teachers[rand_num];
			current[i]->location = available_rooms[rand_num];
			current[i]->time_slot = time_slot[rand_num];

		}

	};

	void random_change()
	{
		Class* temp = next[rand];

		int attribute = rand;

		switch[attribute]
		{
		case 0:
			temp->time_slot = time_slots[rand];
			break;

		case 1:
			temp->instructer = availabile_teachers[rand];
			break;

		case 2:
			temp->location = available_rooms[rand];

		};
		

	};

	int find_fitness(const vector<Class*>& input)
	{
		int fitness = 0;

		reset_classes(input);

		set_classes();

	};

	void reset_classes(const vector<Class*>& input)
	{
		for (int i = 0; i < input.size(); i++)
		{
			input[i]->instructer->classes = 0;
		}
	}

};





int main()
{

	system("pause");
	return 0;

};