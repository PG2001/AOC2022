#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int one_day3()
{
	fstream input;
	input.open("Day3.txt");

	string line;
	long score = 0;

	while (!input.eof())
	{
		getline(input, line);
		
		set<char> left;

		size_t size = line.length();

		for (size_t i = 0; i < size / 2; i++)
		{
			left.insert(line[i]);
		}

		for (size_t i = size / 2; i < size; i++)
		{
			if (left.count(line[i]) > 0)
			{
				if (isupper(line[i]))
				{
					score += line[i] - 'A' + 27;
				}
				else {
					score += line[i] - 'a' + 1;
				}
				break;
			}
		}

	}

	return score;

}


int two_day3()
{
	fstream input;
	input.open("Day3.txt");

	string line;
	long score = 0;

	while (!input.eof())
	{	

		set<char> one, two, three;

		getline(input, line);
		size_t size = line.length();

		for (size_t i = 0; i < size; i++)
		{
			one.insert(line[i]);
		}

		//sort(one.begin(), one.end());

		getline(input, line);
		size = line.length();

		for (size_t i = 0; i < size; i++)
		{
			two.insert(line[i]);
		}
		//sort(two.begin(), two.end());

		getline(input, line);
		size = line.length();

		for (size_t i = 0; i < size; i++)
		{
			three.insert(line[i]);
		}
		//sort(three.begin(), three.end());

		set<char> temp, v;
		set_intersection(one.begin(), one.end(), two.begin(), two.end(), inserter(temp, temp.begin()));
		set_intersection(three.begin(), three.end(), temp.begin(), temp.end(), inserter(v, v.begin()));

		char priority = *(v.begin());

		if (isupper(priority))
		{
			score += priority - 'A' + 27;
		}
		else {
			score += priority - 'a' + 1;
		}

	}

	return score;

}


int main3()
{

	cout << one_day3() << '\n';
	cout << two_day3() << '\n';

	return 0;
}