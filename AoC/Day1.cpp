#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
int one()
{	
	fstream input;
	input.open("input.txt");

	string line;


	int current = 0;
	int max = 0;


	//input >> noskipws;

	while (!input.eof())
	{
		getline(input, line);
		while (line.size() > 0)
		{
			stringstream ss(line);
			int temp;
			ss >> temp;
			current += temp;
			getline(input, line);
		}

		if (current > max)
			max = current;

		line.clear();
		current = 0;
	}

	return max;
}

int two()
{
	fstream input;
	input.open("input.txt");

	string line;


	int current = 0;
	int max0, max1, max2;
	max0 = max1 = max2 = 0;


	//input >> noskipws;

	while (!input.eof())
	{
		getline(input, line);
		while (line.size() > 0)
		{
			stringstream ss(line);
			int temp;
			ss >> temp;
			current += temp;
			getline(input, line);
		}

		if (current > max0)
		{
			max2 = max1;
			max1 = max0;
			max0 = current;
		}
		else if (current > max1)
		{
			max2 = max1;
			max1 = current;
		}
		else if (current > max2)
		{
			max2 = current;
		}

		line.clear();
		current = 0;
	}

	return max0 + max1 + max2;
}

int main()
{
	cout << two();

	return 0;
}