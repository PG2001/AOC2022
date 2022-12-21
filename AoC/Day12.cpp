#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <algorithm>
#include <tuple>

using namespace std;

int findIndex(vector<int> in, int val)
{
	for (int i = 0; i < in.size(); i++)
	{
		if (in[i] == val) return i;
	}

	return -1;
}

int SX, SY, EX, EY;

vector<vector<int>> read(int &width, int &height, vector<vector<int>> &dist)
{
	fstream input;
	input.open("Day12.txt");

	string line;
	vector<vector<int>> map;
	
	int count = 0;
	
	while (!input.eof()) {
		getline(input, line);

		vector<int> temp, distTemp;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == 'S')
			{
				SX = i;
				SY = count;
			}
			if (line[i] == 'E')
			{
				EX = i;
				EY = count;
			}
			temp.push_back(line[i]);
			distTemp.push_back(INT_MAX);			
		}

		count++;
		map.push_back(temp);
		dist.push_back(distTemp);
	}

	width = map[0].size();
	height = map.size();

	dist[SY][SX] = 0;

	return map;
}

void print(vector<vector<int>> in)
{
	for (int y = 0; y < in.size(); y++)
	{
		for (int x = 0; x < in[0].size(); x++)
		{

			cout << in[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int one_day12()
{
	int w, h;
	vector<vector<int>> dist;
	vector<vector<int>> map = read(w, h, dist);
	
	queue<tuple<int, int>> changed;
	changed.push(tuple<int, int>(SX, SY));

	map[SY][SX] = 'a';
	map[EY][EX] = 'z';

	//print(dist);
	//print(map);

	while (!changed.empty())
	{
		int cx, cy;

		cx = get<0>(changed.front());
		cy = get<1>(changed.front());

		changed.pop();

		for (int x = -1; x < 2; x++)
		{
			for (int y = -1; y < 2; y++)
			{
				if (cx + x >= 0 && cx + x < map[0].size() && cy + y >= 0 && cy + y < map.size())
				{
					if (abs(x) != abs(y))
					{
						if (map[cy][cx] + 1 >= map[cy + y][cx + x])
						{
							if (dist[cy + y][cx + x] > dist[cy][cx] + 1)
							{
								dist[cy + y][cx + x] = dist[cy][cx] + 1;

								changed.push(tuple<int, int>(cx + x, cy + y));
							}
						}
					}
				}
			}
		}
	}
	//print(dist);
	return dist[EY][EX];
}

long long two_day12()
{
	int w, h;
	vector<vector<int>> dist;
	vector<vector<int>> map = read(w, h, dist);

	queue<tuple<int, int>> changed;
	changed.push(tuple<int, int>(SX, SY));

	map[SY][SX] = 'a';
	map[EY][EX] = 'z';

	for (int y = 0; y < map.size(); y++)
	{
		for (int x = 0; x < map[0].size(); x++)
		{
			if (map[y][x] == 'a')
			{
				changed.push(tuple<int, int>(x, y));
				dist[y][x] = 0;
			}
			
		}
	}

	while (!changed.empty())
	{
		int cx, cy;

		cx = get<0>(changed.front());
		cy = get<1>(changed.front());

		changed.pop();

		for (int x = -1; x < 2; x++)
		{
			for (int y = -1; y < 2; y++)
			{
				if (cx + x >= 0 && cx + x < map[0].size() && cy + y >= 0 && cy + y < map.size())
				{
					if (abs(x) != abs(y))
					{
						if (map[cy][cx] + 1 >= map[cy + y][cx + x])
						{
							if (dist[cy + y][cx + x] > dist[cy][cx] + 1)
							{
								dist[cy + y][cx + x] = dist[cy][cx] + 1;

								changed.push(tuple<int, int>(cx + x, cy + y));
							}
						}
					}
				}
			}
		}
	}

	return dist[EY][EX];
}

int main12()
{
	cout << one_day12() << "\n";
	cout << two_day12() << '\n';

	return 0;
}