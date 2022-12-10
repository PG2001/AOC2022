#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int one_day10()
{
	fstream input;
	input.open("Day10.txt");

	string line;
	int x = 1, cycle = 0, ret = 1;

	while (!input.eof())
	{
		getline(input, line);
		if (line[0] == 'n')
		{
			cycle++;
			if (cycle == 20 || (cycle + 20) % 40 == 0)
			{
				ret += cycle * x;
			}

			continue;			
		}
		else {
			cycle++;
			if (cycle == 20 || (cycle + 20) % 40 == 0)
			{
				ret += cycle * x;
			}

			cycle++;
			if (cycle == 20 || (cycle + 20) % 40 == 0)
			{
				ret += cycle * x;
			}

			stringstream ss(line);
			string temps;
			int temp;

			ss >> temps >> temp;
			x += temp;
		}
	}

	return ret;
}

void draw(int x, int cycle)
{
	int pixelPosition = (cycle - 1) % 40;
	if (pixelPosition - 1 <= x && x <= pixelPosition + 1)
		cout << '#';
	else
		cout << '.';

	if (cycle % 40 == 0)
		cout << '\n';
}

int two_day10()
{
	fstream input;
	input.open("Day10.txt");

	string line;
	int x = 1, cycle = 1;

	while (!input.eof())
	{

		getline(input, line);
		if (line[0] == 'n')
		{
			draw(x, cycle);
			cycle++;

			continue;
		}
		else {
			
			draw(x, cycle);
			cycle++;

			draw(x, cycle);
			cycle++;

			stringstream ss(line);
			string temps;
			int temp;

			ss >> temps >> temp;
			x += temp;
		}
	}

	return 0;
}


int main10()
{
	cout << one_day10() << "\n\n\n\n";
	cout << "\n\n\n\n" << two_day10() << '\n';

	return 0;
}