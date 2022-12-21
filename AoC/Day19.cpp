#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <map>
#include <string>

using namespace std;

#pragma warning(disable : 4996)

typedef struct Costs {
	int oreRobotCostOre, clayRobotCostOre, obsidianRobotCostOre, obsidianRobotCostClay, geodeRobotCostOre, geodeRobotCostObsidian;
} Costs;

typedef struct State {
	int ore, clay, obsidian, geode, robO, robC, robOb, robG, min;
};

bool operator<(const State& t1, const State& t2)
{
	if (t1.ore != t2.ore)
	{
		return t1.ore < t2.ore;
	}
	else if (t1.clay != t2.clay)
	{
		return t1.clay < t2.clay;
	}
	else if (t1.obsidian != t2.obsidian)
	{
		return t1.obsidian < t2.obsidian;
	}
	else if (t1.geode != t2.geode)
	{
		return t1.geode < t2.geode;
	}
	else if (t1.robO != t2.robO)
	{
		return t1.robO < t2.robO;
	}
	else if (t1.robC != t2.robC)
	{
		return t1.robC < t2.robC;
	}
	else if (t1.robOb != t2.robOb)
	{
		return t1.robOb < t2.robOb;
	}
	else if (t1.robG != t2.robG)
	{
		return t1.robG < t2.robG;
	}
	else
	{
		return t1.min < t2.min;
	}

}


map<State, int> memo;

int evaluate(Costs &c, State &m) {

	if (m.min >= 24)
		return m.geode;

	map<State, int>::iterator it = memo.find(m);

	if (memo.find(m) != memo.end())
		return it->second;

	int ret, temp;

	ret = m.geode;

	if (m.ore >= c.oreRobotCostOre && m.robO < max(c.clayRobotCostOre, max(c.geodeRobotCostOre, c.obsidianRobotCostOre)))
	{
		m.ore -= c.oreRobotCostOre;
		m.ore += m.robO;
		m.clay += m.robC;
		m.obsidian += m.robOb;
		m.geode += m.robG;
		m.robO += 1;
		m.min += 1;
		temp = evaluate(c, m);
		//memo.insert(pair<State, int>(m, temp));
		if (temp > ret)
		{
			ret = temp;
		}
		m.min -= 1;
		m.robO -= 1;
		m.ore -= m.robO;
		m.clay -= m.robC;
		m.obsidian -= m.robOb;
		m.geode -= m.robG;
		m.ore += c.oreRobotCostOre;		
	}

	if (m.ore >= c.clayRobotCostOre && m.robC < c.obsidianRobotCostClay)
	{
		m.ore -= c.clayRobotCostOre;
		m.ore += m.robO;
		m.clay += m.robC;
		m.obsidian += m.robOb;
		m.geode += m.robG;
		m.robC += 1;
		m.min += 1;
		temp = evaluate(c, m);
		//memo.insert(pair<State, int>(m, temp));
		if (temp > ret)
		{
			ret = temp;
		}
		m.min -= 1;
		m.robC -= 1;
		m.ore -= m.robO;
		m.clay -= m.robC;
		m.obsidian -= m.robOb;
		m.geode -= m.robG;
		m.ore += c.clayRobotCostOre;
	}

	if (m.ore >= c.obsidianRobotCostOre && m.clay >= c.obsidianRobotCostClay && m.robOb < c.geodeRobotCostObsidian)
	{
		m.ore -= c.obsidianRobotCostOre;
		m.clay -= c.obsidianRobotCostClay;
		m.ore += m.robO;
		m.clay += m.robC;
		m.obsidian += m.robOb;
		m.geode += m.robG;
		m.robOb += 1;
		m.min += 1;
		temp = evaluate(c, m);
		//memo.insert(pair<State, int>(m, temp));
		if (temp > ret)
		{
			ret = temp;
		}
		m.min -= 1;
		m.robOb -= 1;
		m.ore -= m.robO;
		m.clay -= m.robC;
		m.obsidian -= m.robOb;
		m.geode -= m.robG;
		m.clay += c.obsidianRobotCostClay;
		m.ore += c.obsidianRobotCostOre;
	}

	if (m.ore >= c.geodeRobotCostOre && m.obsidian >= c.geodeRobotCostObsidian)
	{
		m.ore -= c.geodeRobotCostOre;
		m.obsidian -= c.geodeRobotCostObsidian;
		m.ore += m.robO;
		m.clay += m.robC;
		m.obsidian += m.robOb;
		m.geode += m.robG;
		m.robG += 1;
		m.min += 1;
		temp = evaluate(c, m);
		//memo.insert(pair<State, int>(m, temp));
		if (temp > ret)
		{
			ret = temp;
		}
		m.min -= 1;
		m.robG -= 1;
		m.ore -= m.robO;
		m.clay -= m.robC;
		m.obsidian -= m.robOb;
		m.geode -= m.robG;
		m.obsidian += c.geodeRobotCostObsidian;
		m.ore += c.geodeRobotCostOre;
	}
	if (true) {
		m.ore += m.robO;
		m.clay += m.robC;
		m.obsidian += m.robOb;
		m.geode += m.robG;
		m.min += 1;
		temp = evaluate(c, m);
		//memo.insert(pair<State, int>(m, temp));
		if (temp > ret)
		{
			ret = temp;
		}
		m.min -= 1;
		m.ore -= m.robO;
		m.clay -= m.robC;
		m.obsidian -= m.robOb;
		m.geode -= m.robG;
	}

	return ret;
}

int one_day19()
{
	fstream input;
	input.open("Day19.txt");

	int geode = 0;

	while (!input.eof()) {
		string line;
		getline(input, line);

		char* c_str = new char[line.length() + 1];
		strcpy(c_str, line.c_str());
		char* tokens;
		tokens = strtok(c_str, " ");

		int count = 0;
		
		Costs costs;
		State collected;

		
		collected.ore = 0;
		collected.clay = 0;
		collected.geode= 0;
		collected.obsidian = 0;
		collected.robO = 1;
		collected.robC = 0;
		collected.robOb = 0;
		collected.robG = 0;
		collected.min = 0;

		while (tokens != NULL)
		{
			if (count == 6)
				costs.oreRobotCostOre = atoi(tokens);
			if (count == 12)
				costs.clayRobotCostOre = atoi(tokens);
			if (count == 18)
				costs.obsidianRobotCostOre = atoi(tokens);
			if(count == 21) 
				costs.obsidianRobotCostClay = atoi(tokens);
			if (count == 27)
				costs.geodeRobotCostOre = atoi(tokens);
			if (count == 30)
				costs.geodeRobotCostObsidian = atoi(tokens);
			
			tokens = strtok(NULL, " ");
			count++;
		}

		int temp = evaluate(costs, collected);
		if (temp > geode)
			geode = temp;

	}

	return geode;
}


int two_day19()
{
	fstream input;
	input.open("Day19.txt");
	

	while (!input.eof()) {
		string line;
		getline(input, line);

		char *c_str = new char[line.length() + 1];
		strcpy(c_str, line.c_str());
		char* tokens;
		tokens = strtok(c_str, " ");
	}

	return 1;
}


int main()
{
	cout << one_day19() << "\n";
	//cout << two_day19() << '\n';

	return 0;
}