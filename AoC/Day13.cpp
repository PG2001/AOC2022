#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;


vector<vector<int>> parse(string in)
{
	int depth = 0, maxDepth = 0;

	vector<vector<int>> ret;

	for (int i = 0; i < in.length(); i++)
	{
		if (in[i] == '[')
		{
			depth++;
			if (depth > maxDepth)
				maxDepth = depth;
		}
		if (in[i] == ']')
		{
			depth--;
		}
		
	}

	for (int i = 0; i < maxDepth; i++)
	{
		vector<int> temp;
		ret.push_back(temp);
	}

	depth = 0;

	return ret;
}

int one_day13()
{
	fstream input;
	input.open("Day13.txt");

	string line1, line2;

	while (!input.eof())
	{
		getline(input, line1);
		getline(input, line2);

		vector<vector<int>> l = parse(line1);
		vector<vector<int>> r = parse(line2);

		getline(input, line1);

	}
	return 1;
}

int two_day13()
{
	fstream input;
	input.open("Day13.txt");

	string line;

	while (!input.eof())
	{
		getline(input, line);

	}

	return 0;
}

int main13()
{
	cout << one_day13();
	cout << "\n";
	cout << two_day13();

	return 0;
}