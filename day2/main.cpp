#include <fstream>
#include <iostream>
#include <string>

//part 1
/*
int main(void)
{
	std::ifstream infile("input.txt");

	int x = 0, move;
	double y = 0;
	std::string line;

	while (std::getline(infile, line))
	{
		move = line.back() - '0';
		
		if(line.find("forward") != std::string::npos)
		{
			x = x + move;

		} else if(line.find("up") != std::string::npos)
		{
			y = y - move;

		} else if(line.find("down") != std::string::npos)
		{
			y = y + move;
		}
	}
	std::cout<<y*x;

	return 0;
}
*/

//part 2
int main(void)
{
	std::ifstream infile("input.txt");

	int x = 0, move;
	double y = 0, aim = 0;
	std::string line;

	while (std::getline(infile, line))
	{
		move = line.back() - '0';
		
		if(line.find("forward") != std::string::npos)
		{
			x = x + move;
			y = y + move*aim;

		} else if(line.find("up") != std::string::npos)
		{
			aim = aim - move;

		} else if(line.find("down") != std::string::npos)
		{
			aim = aim + move;
		}
	}
	std::cout<<y*x;

	return 0;
}