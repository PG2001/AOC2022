#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define oROCK 'A'
#define oPAPER 'B'
#define oSCISSOR 'C'

#define ROCK 'X'
#define PAPER 'Y'
#define SCISSOR 'Z'

int one_day2()
{
	fstream input;
	input.open("Day2.txt");

	string line;
	long score = 0;

	while (!input.eof())
	{
		getline(input, line);
		
		if (line[2] == ROCK)
		{
			score += 1;

			if (line[0] == oROCK)
				score += 3;

			if (line[0] == oPAPER)
				score += 0;

			if (line[0] == oSCISSOR)
				score += 6;
		}

		if (line[2] == PAPER)
		{
			score += 2;
			if (line[0] == oROCK)
				score += 6;

			if (line[0] == oPAPER)
				score += 3;

			if (line[0] == oSCISSOR)
				score += 0;

		}
		
		if (line[2] == SCISSOR)
		{
			score += 3;
			if (line[0] == oROCK)
				score += 0;

			if (line[0] == oPAPER)
				score += 6;

			if (line[0] == oSCISSOR)
				score += 3;
		}
	}

	return score;

}

#define LOSE 'X'
#define DRAW 'Y'
#define WIN 'Z'

int two_day2()
{
	fstream input;
	input.open("Day2.txt");

	string line;
	long score = 0;

	while (!input.eof())
	{
		getline(input, line);

		if (line[2] == LOSE)
		{
			score += 0;

			if (line[0] == oROCK)
				score += 3;

			if (line[0] == oPAPER)
				score += 1;

			if (line[0] == oSCISSOR)
				score += 2;
		}

		if (line[2] == DRAW)
		{
			score += 3;
			if (line[0] == oROCK)
				score += 1;

			if (line[0] == oPAPER)
				score += 2;

			if (line[0] == oSCISSOR)
				score += 3;

		}

		if (line[2] == WIN)
		{
			score += 6;
			if (line[0] == oROCK)
				score += 2;

			if (line[0] == oPAPER)
				score += 3;

			if (line[0] == oSCISSOR)
				score += 1;
		}
	}

	return score;

}


int main2()
{

	cout << one_day2() << '\n';
	cout << two_day2() << '\n';

	return 0;
}