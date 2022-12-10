#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
#include <set>

using namespace std;

int one_day6()
{
	fstream input;
	input.open("Day6.txt");

	string line;

	getline(input, line);

	queue<char> q;
	set<char> code;

	int start = 0;

	
	for (int i = 3; i < line.length(); i++)
	{
		set<char> code;
		for (int j = i - 3; j <= i; j++)
			code.insert(line[j]);

		if (code.size() == 4)
			return i + 1;
	}

	return -1;
}


int two_day6()
{
	fstream input;
	input.open("Day6.txt");

	string line;

	getline(input, line);

	queue<char> q;
	set<char> code;

	int start = 0;

	for (int i = 13; i < line.length(); i++)
	{
		set<char> code;
		for (int j = i - 13; j <= i; j++)
			code.insert(line[j]);

		if (code.size() == 14)
			return i + 1;
	}

	return -1;
}


int main6()
{
	cout << one_day6() << "\n";
	cout << two_day6() << '\n';

	return 0;
}