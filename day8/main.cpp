#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

//part 1
/*
int main(void)
{
	std::ifstream infile("input.txt");
	std::string line;
	int total = 0;

	while (getline(infile, line))
	{
		std::stringstream stream(line.replace(0, 61, ""));
		while (stream.good())
		{
			std::string num_segs;
			getline(stream, num_segs, ' ');
			if (num_segs.size() == 2 || num_segs.size() == 4 || num_segs.size() == 3 || num_segs.size() == 7)
			{
				total++;
			}
		}
	}

	std::cout<<total;

	return 0;
}*/

//part 2
/* 	2 segments: 1
	3 segments: 7
	4 segments: 4
	5 segments: 2,3,5
	6 segments: 0,6,9
	7 segments: 8
*/
// upper left/bottom left -> dif 3 to 2,5 -> compare to 4: in 4 = upper left, other bottom right.
//this allows us to identify everything but 6 and 0
//compare 6 and 0 to 1 -> if both match 0

//check if all the segments in a appear in b
bool a_is_in_b(std::string a, std::string b)
{
	for (int i = 0; i < a.size(); ++i)
	{
		if (b.find(a[i]) == std::string::npos)
		{
			return false;
		}
	}
	return true;
}

//identify if all the segments in a do not appear in b
bool a_isnt_b(std::string a, std::string b)
{
	for (int i = 0; i < a.size(); ++i)
	{
		if (b.find(a[i]) == std::string::npos)
		{
			return true;
		}
	}
	return false;
}

//check if a and b are the same segments
bool a_matches_b(std::string a, std::string b)
{
	if (a.size() == b.size())
	{
		for (int i = 0; i < a.size(); ++i)
		{
			if (b.find(a[i]) == std::string::npos)
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

//identifying three by comparing all five segment numbers to see if they contain the same segments as 1
std::string identify_three(std::string five_segments[], std::string one)
{
	for (int i = 0; i < 3; ++i)
	{
		if (a_is_in_b(one, five_segments[i]))
		{
			return five_segments[i];
		}
	}
	return "";
}

//identifying nine by comparing all six segment numbers to see if they contain the same segments as 4
std::string identify_nine(std::string six_segments[], std::string four)
{
	for (int i = 0; i < 3; ++i)
	{
		if(a_is_in_b(four, six_segments[i]))
		{
			return six_segments[i];
		}
	}
	return "";
}

//identifying five by comparing all five segment numbers to see if they contain the same segments as 6
std::string identify_five(std::string five_segments[], std::string six)
{
	for (int i = 0; i < 3; ++i)
	{
		if(a_is_in_b(five_segments[i], six))
		{
			return five_segments[i];
		}
	}
	return "";
}

//identifying zero by comparing all six segment numbers to 1 and additionally making sure to not identify 9 by accident
std::string identify_zero(std::string six_segments[], std::string one, std::string nine)
{
	for (int i = 0; i < 3; ++i)
	{
		if(a_is_in_b(one, six_segments[i]) && a_isnt_b(six_segments[i], nine))
		{
			return six_segments[i];
		}
	}
	return "";
}

//identifying six by comparing all six segment numbers to 0 and 9, if its neither its 6
std::string identify_six(std::string six_segments[], std::string zero, std::string nine)
{
	for (int i = 0; i < 3; ++i)
	{
		if(a_isnt_b(six_segments[i], zero) && a_isnt_b(six_segments[i], nine))
		{
			return six_segments[i];
		}
	}
	return "";
}

//identifying 2 by comparing all five segment numbers to 5 and 3, if its neither its 2
std::string identify_two(std::string five_segments[], std::string five, std::string three)
{
	for (int i = 0; i < 3; ++i)
	{
		if(a_isnt_b(five_segments[i], five) && a_isnt_b(five_segments[i], three))
		{
			return five_segments[i];
		}
	}
	return "";
}

//check which number the string corresponds to
int identify_number(std::string key_array[10], std::string input)
{
	for (int i = 0; i < 10; ++i)
	{
		if(a_matches_b(input, key_array[i])){
			return i;
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		std::cout<<"["<<i<<"]"<<": "<<key_array[i]<<"\n";
	}
	std::cout<<"input: " <<input<<"|\n";
	throw std::invalid_argument( "received value that is not a key!" );
}

//part 2
int main(void)
{
	std::ifstream infile("input.txt");
	std::string line, input;
	int total = 0;

	std::string key_array[10];

	std::string five_segments[3];
	std::string six_segments[3];

	while (getline(infile, line))
	{
		std::stringstream stream(line);
		getline(stream, input, '|');

		std::stringstream substream1(input);
		int i = 0, j = 0;
		while(substream1.good())
		{
			getline(substream1, input, ' ');
			switch (input.size())
			{
				case 2:
					key_array[1] = input;
					break;
				case 3:
					key_array[7] = input;
					break;
				case 4:
					key_array[4] = input;
					break;
				case 5:
					five_segments[i] = input;
					i++;
					break;
				case 6:
					six_segments[j] = input;
					j++;
					break;
				case 7:
					key_array[8] = input;
					break;
				default:
					continue;
			}
		}

		key_array[3] = identify_three(five_segments, key_array[1]);
		key_array[9] = identify_nine(six_segments, key_array[4]);
		key_array[0] = identify_zero(six_segments, key_array[1], key_array[9]);
		key_array[6] = identify_six(six_segments, key_array[0], key_array[9]);
		key_array[5] = identify_five(five_segments, key_array[6]);
		key_array[2] = identify_two(five_segments, key_array[5], key_array[3]);

		getline(stream, input, '|');

		std::stringstream substream2(input);
		int x = 1000;
		while(substream2.good())
		{
			getline(substream2, input, ' ');
			if (input.empty())
			{
				continue;
			}
			try{
				total += identify_number(key_array, input) * x;
				x = x/10;
			} catch( const std::invalid_argument& e ) {
				std::cout<<e.what();
				return 0;
			}
		}
	}

	std::cout<<total;

	return 0;
}