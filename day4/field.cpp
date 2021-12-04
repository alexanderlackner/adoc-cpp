#include <iostream>
#include "field.h"

field::field()
{
	has_won = false;
	numbers = new int[5*5];
	marked = new int[5*5];
	for (int x = 0; x < 5; ++x)
	{
		for (int y = 0; y < 5; ++y)
		{
			marked[x*5 + y] = 0;
		}
	}
	hits = 0;
}

field::~field()
{
	delete[] numbers;
	delete[] marked;
}

void field::add_line_to_field(int x_coordinate, int a, int b, int c, int d, int e)
{
	numbers[x_coordinate*5] =  a;
	numbers[x_coordinate*5 + 1] =  b;
	numbers[x_coordinate*5 + 2] =  c;
	numbers[x_coordinate*5 + 3] =  d;
	numbers[x_coordinate*5 + 4] =  e;
}


void field::mark(int target)
{
	for (int x = 0; x < 5; ++x)
	{
		for (int y = 0; y < 5; ++y)
		{
			if(numbers[x*5 + y] == target)
			{
				marked[x*5 + y] = 1;
				hits++;
				return;
			}
		}
	}
}

bool field::check_for_completion()
{
	if (hits >= 5)
	{
		for (int x = 0; x < 5; ++x)
		{
			for (int y = 0; y < 5; ++y)
			{
				if (marked[x*5 + y] == 0)
				{
					goto cnt_a;
				}
			}
			return true;
			cnt_a:;
		}
		for (int y = 0; y < 5; ++y)
		{
			for (int x = 0; x < 5; ++x)
			{
				if (marked[x*5 + y] == 0)
				{
					goto cnt_b;
				}
			}
			return true;
			cnt_b:;
		}
	}
	return false;
}

int field::sum_of_all_unmarked_numbers()
{
	int sum = 0;
	for (int x = 0; x < 5; ++x)
	{
		for (int y = 0; y < 5; ++y)
		{
			if (marked[x*5 + y] == 0)
			{
				sum += numbers[x*5 + y];
			}
		}
	}
	return sum;
}

void field::print_field()
{
	for (int x = 0; x < 5; ++x)
	{
		for (int y = 0; y < 5; ++y)
		{
			std::cout<<numbers[x*5 + y]<<",";
		}
		std::cout<<"\n";
	}
}

void field::print_marked()
{
	for (int x = 0; x < 5; ++x)
	{
		for (int y = 0; y < 5; ++y)
		{
			std::cout<<marked[x*5 + y]<<",";
		}
		std::cout<<"\n";
	}
}

void field::toggle_has_won()
{
	has_won = !has_won;
}

bool field::get_has_won()
{
	return has_won;
}