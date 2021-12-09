#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

//check if all surrounding values are lower
bool is_local_minima(int (&map)[100][100], int x, int y)
{
	if(x > 0 && map[x-1][y] <= map[x][y])
	{
		return false;
	}
	if(y > 0 && map[x][y-1] <= map[x][y])
	{
		return false;
	}
	if(x < 99 && map[x+1][y] <= map[x][y])
	{
		return false;
	}
	if(y < 99 && map[x][y+1] <= map[x][y])
	{
		return false;
	}

	return true;
}

//recursively check the basin size and mark values that have been accounted for
int check_basin_size(int (&map)[100][100], int (&marked)[100][100], int x, int y)
{
	int total = 1;
	marked[x][y] = 1;
	if(x > 0 && map[x-1][y] > map[x][y] && map[x-1][y] != 9 && marked[x-1][y] != 1)
	{
		total+= check_basin_size(map, marked, x-1, y);
	}
	if(y > 0 && map[x][y-1] > map[x][y] && map[x][y-1] != 9 && marked[x][y-1] != 1)
	{
		total+= check_basin_size(map, marked, x, y-1);
	}
	if(x < 99 && map[x+1][y] > map[x][y] && map[x+1][y] != 9 && marked[x+1][y] != 1)
	{
		total+= check_basin_size(map, marked, x+1, y);
	}
	if(y < 99 && map[x][y+1] > map[x][y] && map[x][y+1] != 9 && marked[x][y+1] != 1)
	{
		total+= check_basin_size(map, marked, x, y+1);
	}
	return total;
}

//multiply the three largest basins found
int multiply_three_largest_basins(int (&map)[100][100])
{
	int current;
	//scores are sorted by such that highest score -> highest index
	int highest[3] = {};
	for (int x = 0; x < 100; ++x)
	{
		for (int y = 0; y < 100; ++y)
		{
			if (is_local_minima(map, x, y))
			{
				//array of the same size which helps us keep track of which basins have been accounted for
				int marked[100][100] = {};
				current = check_basin_size(map, marked, x, y);
				if (highest[0] < current)
				{
					if(highest[1] < current)
					{
						if(highest[2] < current)
						{
							highest[0] = highest[1];
							highest[1] = highest[2];
							highest[2] = current;
						} else
						{
							highest[0] = highest[1];
							highest[1] = current;
						}
					} else
					{
						highest[0] = current;
					}
				}
			}
		}
	}
	std::cout<<highest[0]<<","<<highest[1]<<","<<highest[2]<<"\n";
	return highest[0]*highest[1]*highest[2];
}

//part 1
int calculate_sum_of_local_minima(int (&map)[100][100])
{
	int total = 0;
	for (int x = 0; x < 100; ++x)
	{
		for (int y = 0; y < 100; ++y)
		{
			if (is_local_minima(map, x, y))
			{
				total += map[x][y] + 1;
			}
		}
	}
	return total;
}

int main(void)
{
	std::ifstream infile("input.txt");
	std::string line;

	int x=0, y;
	int map[100][100];

	while(getline(infile,line))
	{
		y = 0;
		for (char const &c: line)
		{
			map[x][y] = c-'0';
			y++;
		}
		x++;
	}

	//part 1
	//std::cout<<calculate_sum_of_local_minima(map);

	std::cout<<multiply_three_largest_basins(map);

	return 0;
}