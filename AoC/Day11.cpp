#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <algorithm>
#include <math.h>
using namespace std;


class Monkey {
public:
	queue<long long> items;
	bool addOp;
	long long oppValue;
	long long test;
	long long trueResult;
	long long falseResult;
	long long numInspections = 0;
};

vector<Monkey> readfile()
{
	vector<Monkey> ret;

	fstream input;
	input.open("Day11.txt");

	while (!input.eof()) {
		Monkey m;
		string line, temp;

		getline(input, line);
		getline(input, line);

		line.erase(0, 17);
		stringstream ss(line);		
		while (getline(ss, temp, ','))
		{
			stringstream st(temp);
			long long x;
			st >> x;			
			m.items.push(x);			
		}

		getline(input, line);
		m.addOp = line[23] == '+';
		line.erase(0, 24);
		if (isdigit(line[1]))
		{
			m.oppValue = stoll(line);
		}
		else {
			m.oppValue = -1;
		}

		getline(input, line);
		line.erase(0, 21);
		m.test = stoll(line);

		getline(input, line);
		line.erase(0, 29);
		m.trueResult = stoll(line);

		getline(input, line);
		line.erase(0, 30);
		m.falseResult = stoll(line);

		ret.push_back(m);

		getline(input, line);
	}

	return ret;
}

long long one_day11()
{
	vector<Monkey> monkeys = readfile();

	for (int i = 0; i < 20; i++)
	{
		for (int m = 0; m < monkeys.size(); m++)
		{
			while(!monkeys[m].items.empty())
			{
				long long worry = monkeys[m].items.front();
				long long oppValue = monkeys[m].oppValue == -1 ? worry : monkeys[m].oppValue;
				long long testValue = monkeys[m].test;
				if (monkeys[m].addOp)
				{
					worry += oppValue;
				}
				else {
					worry *= oppValue;
				}

				worry /= 3;

				if (worry % testValue == 0)
				{
					int nextMonkey = monkeys[m].trueResult;
					monkeys[nextMonkey].items.push(worry);
				}
				else {
					int nextMonkey = monkeys[m].falseResult;
					monkeys[nextMonkey].items.push(worry);
				}
				monkeys[m].numInspections += 1;
				monkeys[m].items.pop();
			}
		}
	}

	vector<long long> results;

	for (int m = 0; m < monkeys.size(); m++)
	{
		results.push_back(monkeys[m].numInspections);
	}

	sort(results.begin(), results.end());

	return results[results.size() - 1] * results[results.size() - 2];
}

void print(int r, vector<Monkey> in)
{
	cout << "After round " << r << "\n";
	for (int m = 0; m < in.size(); m++)
	{
		cout << "Monkey " << m << " inspected items " << in[m].numInspections << "\n";
	}
	cout << "\n";
	
}

long long two_day11()
{
	vector<Monkey> monkeys = readfile();

	long long modValue = 1;

	for (int m = 0; m < monkeys.size(); m++)
	{
		modValue *= monkeys[m].test;
	}

	for (int i = 0; i < 10000; i++)
	{
		for (int m = 0; m < monkeys.size(); m++)
		{
			while (!monkeys[m].items.empty())
			{
				long long worry = monkeys[m].items.front();
				long long oppValue = monkeys[m].oppValue == -1 ? worry : monkeys[m].oppValue;
				long long testValue = monkeys[m].test;
				if (monkeys[m].addOp)
				{
					worry += oppValue;
				}
				else {
					worry *= oppValue;
				}				

				worry = worry % modValue;

				if (worry % testValue == 0)
				{
					int nextMonkey = monkeys[m].trueResult;
					monkeys[nextMonkey].items.push(worry);
				}
				else {
					int nextMonkey = monkeys[m].falseResult;
					monkeys[nextMonkey].items.push(worry);
				}
				monkeys[m].numInspections += 1;
				monkeys[m].items.pop();
			}
		}

		if (i == 0)
			print(i, monkeys);
		if (i == 19)
			print(i, monkeys);
		if (i % 1000 == 999 && i > 1)
			print(i, monkeys);		
	}

	vector<long long> results;

	for (int m = 0; m < monkeys.size(); m++)
	{
		results.push_back(monkeys[m].numInspections);
	}

	sort(results.begin(), results.end());

	unsigned long long l = results[results.size() - 1], r = results[results.size() - 2];

	return l * r;
}

int main()
{
	cout << one_day11() << "\n";
	cout << two_day11() << '\n';

	return 0;
}