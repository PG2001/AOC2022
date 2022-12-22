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

enum robots { ORE, CLAY, OB, GEODE };

typedef struct Costs {
	int oreRobotCostOre, clayRobotCostOre, obsidianRobotCostOre, obsidianRobotCostClay, geodeRobotCostOre, geodeRobotCostObsidian;
} Costs;

int etc(int c1, int c2, int m1, int m2, int r1, int r2)
{
	if (m1 >= c1 && m2 >= c2)
		return 1;

	int time1 = 0, time2 = 0;
	if(r1)
		time1 = 1 + (c1 - m1 + r1 - 1) / r1;
	if(r2)
		time2 = 1 + (c2 - m2 + r2 - 1) / r2;

	return max(time1, time2);
}

int eval(Costs &cost, int min, int o, int c, int ob, int g, int robO, int robC, int robOb, int robG) {
	int ret = g + min * robG;

	// Try to make a ore robot
	if (robO < cost.clayRobotCostOre || robO < cost.obsidianRobotCostOre || robO < cost.geodeRobotCostOre)
	{
		int dt = etc(cost.oreRobotCostOre, 0, o, 0, robO, 0);
		if (min > dt)
			ret = max(ret, eval(cost, min - dt, o + robO * dt - cost.oreRobotCostOre, c + robC * dt, ob + robOb * dt, g + robG * dt, robO + 1, robC, robOb, robG));
	}

	// Try to make a clay robot
	if (robC < cost.obsidianRobotCostClay)
	{
		int dt = etc(cost.clayRobotCostOre, 0, o, 0, robO, 0);
		if (min > dt)
			ret = max(ret, eval(cost, min - dt, o + robO * dt - cost.clayRobotCostOre, c + robC * dt, ob + robOb * dt, g + robG * dt, robO, robC + 1, robOb, robG));
	}

	// try to make a ob robot
	if (robC && robOb < cost.geodeRobotCostObsidian)
	{
		int dt = etc(cost.obsidianRobotCostOre, cost.obsidianRobotCostClay, o, c, robO, robC);
		if (min >  dt)
			ret = max(ret, eval(cost, min - dt, o + robO * dt - cost.obsidianRobotCostOre, c + robC * dt - cost.obsidianRobotCostClay, ob + robOb * dt, g + robG * dt, robO, robC, robOb + 1, robG));
	}

	// try to make a geode robot
	if (robOb)
	{
		int dt = etc(cost.geodeRobotCostOre, cost.geodeRobotCostObsidian, o, ob, robO, robOb);
		if (min > dt)
			ret = max(ret, eval(cost, min - dt, o + robO * dt - cost.geodeRobotCostOre, c + robC * dt, ob + robOb * dt- cost.geodeRobotCostObsidian, g + robG * dt, robO, robC, robOb, robG + 1));
	}

	return ret;
}

int one_day19()
{
	fstream input;
	input.open("Day19.txt");

	int blueprint = 1;
	int ret = 0;

	while (!input.eof()) {
		string line;
		getline(input, line);

		char* c_str = new char[line.length() + 1];
		strcpy(c_str, line.c_str());
		char* tokens;
		tokens = strtok(c_str, " ");

		int count = 0;
		
		Costs costs;
		
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

		ret += blueprint++ * eval(costs, 24, 0, 0, 0, 0, 1, 0, 0, 0);

	}

	return ret;
}


int two_day19()
{
	fstream input;
	input.open("Day19.txt");

	int geode = 0;
	int blueprint = 1;
	int ret = 1;

	while (!input.eof()) {
		string line;
		getline(input, line);

		char* c_str = new char[line.length() + 1];
		strcpy(c_str, line.c_str());
		char* tokens;
		tokens = strtok(c_str, " ");

		int count = 0;

		Costs costs;

		while (tokens != NULL)
		{
			if (count == 6)
				costs.oreRobotCostOre = atoi(tokens);
			if (count == 12)
				costs.clayRobotCostOre = atoi(tokens);
			if (count == 18)
				costs.obsidianRobotCostOre = atoi(tokens);
			if (count == 21)
				costs.obsidianRobotCostClay = atoi(tokens);
			if (count == 27)
				costs.geodeRobotCostOre = atoi(tokens);
			if (count == 30)
				costs.geodeRobotCostObsidian = atoi(tokens);

			tokens = strtok(NULL, " ");
			count++;
		}

		

		ret *= eval(costs, 32, 0, 0, 0, 0, 1, 0, 0, 0);

		if (blueprint == 3)
			break;
		blueprint++;
	}

	return ret;
}


int main19()
{
	cout << one_day19() << "\n";
	cout << two_day19() << '\n';

	return 0;
}
