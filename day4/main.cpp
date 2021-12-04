#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "field.h"

//part 1
/*
int main(void)
{
	std::ifstream infile("input.txt");
	std::string line;

	std::getline(infile, line);
	std::vector<int> input_sequence;
    std::stringstream stream(line);

	while (stream.good())
	{
		getline(stream, line, ',');
		input_sequence.push_back(stoi(line));
	}

	std::list<field> field_list;
	int x_coordinate = 0;
	int a, b, c, d, e;

	field* new_field = new field();

	while (infile >> a >> b >> c >> d >> e)
	{
		(*new_field).add_line_to_field(x_coordinate, a, b, c, d, e);
		x_coordinate++;

		if(x_coordinate == 5)
		{
			field_list.push_back(*new_field);
			x_coordinate = 0;
			new_field = new field();
		}
	}

	
	for (const int& target : input_sequence)
	{
		for (field& current_field : field_list)
		{
			current_field.mark(target);
			if(current_field.check_for_completion())
			{
				current_field.print_field();
				current_field.print_marked();
				std::cout<<current_field.sum_of_all_unmarked_numbers()*target;
				return 0;
			}
		}
	}

	return 0;
}
*/

//part2
int main(void)
{
	std::ifstream infile("input.txt");
	std::string line;

	std::getline(infile, line);
	std::vector<int> input_sequence;
    std::stringstream stream(line);

	while (stream.good())
	{
		getline(stream, line, ',');
		input_sequence.push_back(stoi(line));
	}

	std::list<field> field_list;
	int x_coordinate = 0;
	int a, b, c, d, e;

	field* new_field = new field();

	while (infile >> a >> b >> c >> d >> e)
	{
		(*new_field).add_line_to_field(x_coordinate, a, b, c, d, e);
		x_coordinate++;

		if(x_coordinate == 5)
		{
			field_list.push_back(*new_field);
			x_coordinate = 0;
			new_field = new field();
		}
	}

	
	for (const int& target : input_sequence)
	{
		for (field& current_field : field_list)
		{
			current_field.mark(target);
			if(current_field.check_for_completion() && !current_field.get_has_won())
			{
				std::cout<<current_field.sum_of_all_unmarked_numbers()*target<<"\n";
				current_field.toggle_has_won();
			}
		}
	}

	return 0;
}