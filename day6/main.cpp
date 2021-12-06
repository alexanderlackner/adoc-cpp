#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cmath>

//part 1 & 2 (simple variable changes)
int main(void)
{
	std::ifstream infile("input.txt");
	std::string line;

	std::getline(infile, line);
    std::stringstream stream(line);

	//population with a first duplication date of up to 264 are part of the population on day 256
	long long int pop_array[264] = {};

	while (stream.good())
	{
		std::string parent_days;
		getline(stream, parent_days, ',');
		//add initial input to array
		//idea is the day they first duplicate is the index-1
		//ex.: pop_array[2] -> number of fish that duplicate for the first time on day 3
		pop_array[std::stoi(parent_days)-1] += 1;
	}

	//iterate over all fish that duplicate in the 256 day period
	for (int i = 0; i<256; ++i)
	{
		//calculate how often a fish with first duplication date i duplicates
		int populates_this_many_times = std::floor((256-(i+1))/7);
		for (int j = 0; j<= populates_this_many_times; ++j)
		{
			//depending on the first duplication date a fish duplicates on different days and a different amount of times
			//all fish with the same first duplication date duplicate on the same days
			//since pop_array[i] is the number of fish that duplicate on day i+1 we add this number to every following day they duplicate
			int populates_after = j*7 + 9 + i;
			//these fish only become relevant after 256 days and therefor arent interesting to us
			if (populates_after > 263)
			{
				break;
			} else
			{
				pop_array[populates_after] += pop_array[i];
			}
		}
	}

	long long int total = 0;

	for (int i = 0; i<264; ++i)
	{
		total += pop_array[i];
	}

	std::cout<<total;

	return 0;
}