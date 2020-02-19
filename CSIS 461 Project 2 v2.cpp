#include<iostream>
#include<vector>
#include<string>
#include<ctime>



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
	char section;
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
	temp->section = ' ';
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
		fitness_current = NULL;
		fitness_next = NULL;

	}

	void add_class(string name, int enrollment)
	{
		Class* temp = new_class();
		Class* temp2 = new_class();


		temp->class_name = name;
		temp->expected_enrollment = enrollment;

		temp2->class_name = name;
		temp2->expected_enrollment = enrollment;

		current.push_back(temp);
		next.push_back(temp2);
	}

	void add_teacher(string name/*, vector<string>& qualifications*/)
	{
		teacher* temp = new_teacher();

		temp->name = name;
	//	temp->qualifications = qualifications;

		if (name == "Rao")
			Rao == temp;
		if (name == "Mitchell")
			Mitchell = temp;
		if (name == "Hare")
			Hare = temp;
		if (name == "Bingham")
			Bingham = temp;


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

	vector<Class*> generate()
	{
		attempts = 0;
		success = 0;

		fitness_current = find_fitness(current);

		set_equal(current, next);


		while (attempts != 4000)
		{
			random_change();
			fitness_next = find_fitness(next);

			if (fitness_next > fitness_current)
			{
				set_equal(next, current);
				fitness_current = fitness_next;
				success++;
				attempts = 0;

			}
			else
			{
				double difference = (fitness_current - fitness_next) / 10 + 1;
				double decimal = rand() % 100;
				decimal = decimal / 100;

				if (decimal* difference < temperature)
				{
					set_equal(next, current);
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

	teacher* Rao;
	teacher* Mitchell;
	teacher* Hare;
	teacher* Bingham;
	Class* CS101A;
	Class* CS191A;
	Class* CS101B;
	Class* CS191B;
	Class* CS201A;
	Class* CS291A;
	Class* CS201B;
	Class* CS291B;

	vector<Class*> current;
	vector<Class*> next;

	vector<int> time_slot;
	vector<room*> available_rooms;
	vector<teacher*> available_teachers;

	void scramble()
	{
		for (int i = 0; i < current.size(); i++)
		{
			current[i]->instructer = available_teachers[rand()% available_teachers.size()];
			current[i]->location = available_rooms[rand() % available_rooms.size() ];
			current[i]->time_slot = time_slot[rand() % time_slot.size()];

		}

	};

	void random_change()
	{
		Class* temp = next[rand() % (next.size()) ];

		int attribute = rand() % 3;

		switch(attribute)
		{
		case 0:
			temp->time_slot = time_slot[rand() % time_slot.size() ];
			break;

		case 1:
			temp->instructer = available_teachers[rand() % available_teachers.size()];
			break;

		case 2:
			temp->location = available_rooms[rand() % available_rooms.size()];
			break;

		};


	};

	int find_fitness(const vector<Class*>& input)
	{
		int fitness = 0;
		bool is_only_class;
		bool is_only_teacher;

		for (int z = 0; z < available_teachers.size(); z++)
		{
			available_teachers[z]->classes = 0;
		}

		for (int i = 0; i < input.size(); i++)
		{
			Class* current_class = input[i];
			teacher* target_teacher = input[i]->instructer;
			room* target_location = input[i]->location;
			int target_time = input[i]->time_slot;

			is_only_class = true;
			is_only_teacher = true;

			if (input[i]->instructer->name == "Staff")
			{
				fitness++;
			}
			else
			{
				if (search(target_teacher->qualifications, current_class->class_name))
				{
					fitness = fitness + 3;
				}
			}



			for (int j = i; j < input.size(); j++)
			{
				if (input[j] != current_class)
				{
					if (input[j]->location == target_location && input[j]->time_slot == target_time)
					{
						is_only_class = false;
					}

					if (input[j]->instructer == target_teacher && input[j]->time_slot == target_time)
					{
						is_only_teacher = false;
					}
				}

			}

			if (is_only_class)
			{
				fitness = fitness + 5;
			}

			if (is_only_teacher)
			{
				fitness = fitness + 5;
			}

			if (input[i]->expected_enrollment < input[i]->location->capacity)
			{
				fitness = fitness + 5;

				if (input[i]->location->capacity < 2 * input[i]->expected_enrollment)
				{
					fitness = fitness + 2;
				}
			}

			current_class->instructer->classes++;


		}

		for (int a = 0; a < available_teachers.size(); a++)
		{
			if (available_teachers[a]->classes > 4)
			{
				int penalty = available_teachers[a]->classes - 4;

				fitness = fitness + (penalty * -5);
			}
		}


	

	};

	void print_scheduale(vector<Class*>& input)
	{
		for (int i = 0; i < input.size(); i++)
		{
			cout <<"class: " <<  input[i]->class_name << endl;
			cout <<"teacher: " << input[i]->instructer->name << endl;
			cout << "room: " << input[i]->location->building << " " << input[i]->location->room_number << endl;
			cout <<"time: " << input[i]->time_slot << endl << endl;
		}

	}

	void set_equal(vector<Class*>& a, vector<Class*>& b)
	{
		for (int i = 0; i < a.size(); i++)
		{
			b[i]->instructer = a[i]->instructer;
			b[i]->location = a[i]->location;
			b[i]->time_slot = a[i]->time_slot;
		}


	}

	bool search(vector<string>& input, string& target)
	{
		bool is_present = false;

		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == target)
				is_present = true;
		}

		return is_present;
	}

};





int main()
{
	srand(time(0));

	schedule_generator test;

	system("pause");
	return 0;

};