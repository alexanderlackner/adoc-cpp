#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>

int calculate_fuel_consumption(std::vector<int> coordinate_vec, int go_to)
{
	int total = 0;
	for (const int& coordinate : coordinate_vec)
	{
		//part 1
		//total += abs(coordinate-go_to);
		int n = abs(coordinate-go_to);
		total += n*(n+1)/2;
	}
	return total;
}

//part 1
/*
int main(void)
{
	std::ifstream infile("input.txt");
	std::string line;

	std::vector<int> coordinate_vec;

	std::getline(infile, line);
    std::stringstream stream(line);

	while (stream.good())
	{
		std::string coordinate;
		getline(stream, coordinate, ',');
		coordinate_vec.push_back(std::stoi(coordinate));
	}
	std::sort(coordinate_vec.begin(), coordinate_vec.end());

	std::cout<<calculate_fuel_consumption(coordinate_vec, (coordinate_vec[499]+coordinate_vec[500])/2);

	return 0;
}*/

//part 2
int main(void)
{
	std::ifstream infile("input.txt");
	std::string line;

	std::vector<int> coordinate_vec;

	std::getline(infile, line);
    std::stringstream stream(line);

	while (stream.good())
	{
		std::string coordinate;
		getline(stream, coordinate, ',');
		coordinate_vec.push_back(std::stoi(coordinate));
	}

	int last_winner = 0;
	int offset = 0, left, right;

	//approximate minimum
	for (int i = 1024; i>=2; i=i/2)
	{	
		left = calculate_fuel_consumption(coordinate_vec, i/2 + offset);
		right = calculate_fuel_consumption(coordinate_vec, i*1.5 + offset);

		if (left<right)
		{
			last_winner = left;
		} else
		{
			last_winner = right;
			offset += i;
		}
	}

	//check if minimum might be one to the left or right
	left = calculate_fuel_consumption(coordinate_vec, offset+1);
	right = calculate_fuel_consumption(coordinate_vec, offset-1);
	if (left < last_winner && left < right)
	{
		std::cout<<left;
	} else if (right < last_winner && right < left)
	{
		std::cout<<right;
	} else
	{
		std::cout<<last_winner;
	}

	return 0;
}