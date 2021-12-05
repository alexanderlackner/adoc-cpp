#include <string>
#include <fstream>
#include <iostream>

//check on how many points 2 lines overlap
int solve_diagram(int diagram [1000][1000])
{
	int total = 0;

	for(int x = 0; x < 1000; ++x)
	{
		for(int y = 0; y < 1000; ++y)
		{
			if (diagram[x][y] > 1)
			{
				total++;
			}
		}
	}
	return total;
}

void check_and_add_line(int (&diagram)[1000][1000], int x1, int y1, int x2, int y2)
{
	int smaller, bigger;

	//vertical line
	if (x1 == x2)
	{
		if (y1 < y2)
		{
			smaller = y1;
			bigger = y2;
		} else
		{
			smaller = y2;
			bigger = y1;
		}
		for (int i = smaller; i <= bigger; ++i)
		{
			diagram[x1][i] = diagram[x1][i] + 1;
		}
	//horizontal line
	} else if (y1 == y2)
	{
		if (x1 < x2)
		{
			smaller = x1;
			bigger = x2;
		} else
		{
			smaller = x2;
			bigger = x1;
		}
		for (int i = smaller; i <= bigger; ++i)
		{
			diagram[i][y1] = diagram[i][y1] + 1;
		}
	//part 2
	//diagonal line
	} else
	{	//case 1: bottom left to top right
		if (x1 < x2 && y1 < y2)
		{
			for (int x = x1, y = y1; x <= x2; x++, y++)
			{
				diagram[x][y] = diagram[x][y] + 1;
			}
		//case 2: bottom right to top left
		} else if (x1 < x2 && y1 > y2)
		{
			for (int x = x1, y = y1; x <= x2; x++, y--)
			{
				diagram[x][y] = diagram[x][y] + 1;
			}
		//case 3: top left to bottom right
		}  else if (x1 > x2 && y1 < y2)
		{
			for (int x = x1, y = y1; x >= x2; x--, y++)
			{
				diagram[x][y] = diagram[x][y] + 1;
			}
		//case 4: top right to bottom left
		}  else if (x1 > x2 && y1 > y2)
		{
			for (int x = x1, y = y1; x >= x2; x--, y--)
			{
				diagram[x][y] = diagram[x][y] + 1;
			}
		}
	}
}

//part 1
int main(void)
{
	std::ifstream infile("input.txt");
	std::string line;

	int x1, y1, x2, y2;
	char a, b, c, d;

	int diagram [1000][1000] = {};

	//expecting lines as defined in input
	//example: 0,9 -> 5,9
	while (infile >> x1 >> a >> y1 >> b >> c >> x2 >> d >> y2)
	{
		check_and_add_line(diagram, x1, y1, x2, y2);
	}

	std::cout<<solve_diagram(diagram);

	return 0;
}