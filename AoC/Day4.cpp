#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int one_day4()
{
	fstream input;
	input.open("Day4.txt");

	string line;
	long score = 0;

	while (!input.eof())
	{
		getline(input, line);
		int ll, lr, rl, rr;

		line[line.find(',')] = ' ';
		line[line.find('-')] = ' ';
		line[line.find('-')] = ' ';

		stringstream ss(line);

		ss >> ll >> lr >> rl >> rr;

		if ((ll <= rl && lr >= rr) || (rl <= ll && rr >= lr))
			score++;

	}

	return score;

}


int two_day4()
{
	fstream input;
	input.open("Day4.txt");

	string line;
	long score = 0;

	while (!input.eof())
	{
		getline(input, line);
		int ll, lr, rl, rr;

		line[line.find(',')] = ' ';
		line[line.find('-')] = ' ';
		line[line.find('-')] = ' ';

		stringstream ss(line);

		ss >> ll >> lr >> rl >> rr;

		if ((ll <= rl && rl <= lr) ||
			(ll <= rr && rr <= lr) ||
			(rl <= ll && ll <= rr) ||
			(rl <= lr && lr <= rr)) 
			score++;

	}

	return score;

}


int main()
{

	cout << one_day4() << '\n';
	cout << two_day4() << '\n';

	return 0;
}