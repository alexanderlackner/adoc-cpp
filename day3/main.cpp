#include <fstream>
#include <iostream>
#include <string>
#include<cmath>
#include <list>

//part 1
/*
int main(void)
{
	std::ifstream infile("input.txt");

	std::string line;

	int occurence_of_zero [12] = {};

	while (std::getline(infile, line))
	{
		for (int i = 0; i < 12; ++i)
		{
			if (line.at(i) == '0')
			{
				occurence_of_zero[i] += 1;
			}
		}
	}

	int gamma_rate = 0, epsilon_rate = 0;

	for (int i = 0; i < 12; ++i)
	{
		std::cout<< "[" << i << "]: " << occurence_of_zero[i] << "\n";
		if (occurence_of_zero[i] > 500)
		{
			epsilon_rate += pow(2.0, 11-i); //111100111111 = 3903

		} else 
		{
			gamma_rate += pow(2.0, 11-i); //11000000 = 192
		}
	}

	std::cout<<gamma_rate << " * " << epsilon_rate << " = " << gamma_rate*epsilon_rate;

	return 0;
}
*/

int count_occurences_of_zero(int idx, std::list<std::string>& list)
{
	int occurence_of_zero = 0;

	for (std::string& line : list)
	{
		if (line.at(idx) == '0')
			{
				occurence_of_zero += 1;
			}
	}
	return occurence_of_zero;
}

void print_list(std::list<std::string>& list)
{
	for (std::string& line : list)
	{
		std::cout<<line<< "\n";
	}
}

int main(void)
{
	std::ifstream infile("input.txt");

	std::string line;

	std::list<std::string> input_list_most_common = {};
	std::list<std::string> input_list_least_common = {};

	while (std::getline(infile, line))
	{
		input_list_most_common.push_back(line);
		input_list_least_common.push_back(line);
	}

	for (int i = 0; i < 12; ++i)
	{
		if (input_list_most_common.size()>1) {
			if (count_occurences_of_zero(i, input_list_most_common) > input_list_most_common.size()/2)
			{
				input_list_most_common.remove_if([&i](std::string line){ return line.at(i) == '1';});

			} else
			{
				input_list_most_common.remove_if([&i](std::string line){ return line.at(i) == '0';});
			}
		}

		if (input_list_least_common.size() > 1 ) {
			if (count_occurences_of_zero(i, input_list_least_common) > input_list_least_common.size()/2)
			{
				input_list_least_common.remove_if([&i](std::string line){ return line.at(i) == '0';});

			} else
			{
				input_list_least_common.remove_if([&i](std::string line){ return line.at(i) == '1';});
			}
		}
		
		/*
		print_list(input_list_most_common);
		std::cout<<"--------\n";
		print_list(input_list_least_common);
		std::cout<<"--------\n";
		*/

	}

	std::cout<<"--------\n";
	std::cout<< input_list_most_common.front() << " and " << input_list_least_common.front();

	return 0;
}