#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

string one_day5()
{
	fstream input;
	input.open("Day5.txt");

	string line, tops;
	int numStacks = 0;

	vector<vector<char>> stacks;

	getline(input, line);

	numStacks = (line.length() + 1) / 4;
	stacks.resize(numStacks);

	while (line.length() > 1)
	{				
		for (int i = 0; i < numStacks; i++)
		{
			if (line[1 + i * 4] != ' ')
			{
				stacks[i].push_back(line[1 + i * 4]);
			}
		}

		getline(input, line);
		if (line[1] == '1')
			break;
	}

	for (int i = 0; i < numStacks; i++)
	{
		reverse(stacks[i].begin(), stacks[i].end());
	}
	
	getline(input, line);

	while (!input.eof())
	{
		string temp;
		int m, f, t;

		getline(input, line);
		stringstream ss(line);

		ss >> temp >> m >> temp >> f >> temp >> t;

		for (int i = 0; i < m; i++)
		{
			char x = stacks[f-1][stacks[f-1].size() - 1];
			stacks[f-1].pop_back();
			stacks[t-1].push_back(x);
		}
	}
	for (int i = 0; i < numStacks; i++)
	{
		char tempc = stacks[i][stacks[i].size() - 1];
		tops.append(1, tempc);
	}
	

	return tops;

}

string two_day5()
{
	fstream input;
	input.open("Day5.txt");

	string line, tops;
	int numStacks = 0;

	vector<vector<char>> stacks;

	getline(input, line);

	numStacks = (line.length() + 1) / 4;
	stacks.resize(numStacks);

	while (line.length() > 1)
	{
		for (int i = 0; i < numStacks; i++)
		{
			if (line[1 + i * 4] != ' ')
			{
				stacks[i].push_back(line[1 + i * 4]);
			}
		}

		getline(input, line);
		if (line[1] == '1')
			break;
	}

	for (int i = 0; i < numStacks; i++)
	{
		reverse(stacks[i].begin(), stacks[i].end());
	}

	getline(input, line);

	while (!input.eof())
	{
		string temp;
		int m, f, t;

		getline(input, line);
		stringstream ss(line);

		ss >> temp >> m >> temp >> f >> temp >> t;

		for (int i = m; i > 0; i--)
		{
			char x = stacks[f - 1][stacks[f - 1].size() - i];
			stacks[t - 1].push_back(x);
		}

		for (int i = 0; i < m; i++)
			stacks[f - 1].pop_back();

	}
	for (int i = 0; i < numStacks; i++)
	{
		char tempc = stacks[i][stacks[i].size() - 1];
		tops.append(1, tempc);
	}


	return tops;

}


int main5()
{

	cout << one_day5() << '\n';
	cout << two_day5() << '\n';

	return 0;
}