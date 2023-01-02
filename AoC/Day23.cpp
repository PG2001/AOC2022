#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>


using namespace std;
#define Point pair<int,int>

bool stay(map<Point, Point>& n, int x, int y)
{
	for (int xx = -1; xx < 2; xx++)
	{
		for (int yy = -1; yy < 2; yy++)
		{
			if (xx == 0 && yy == 0) continue;

			if (n.find(Point(x + xx, y + yy)) != n.end())
				return false;
		}
	}
	return true;
}

bool north(map<Point, Point> &n, int x, int y)
{
	for (int xx = -1; xx < 2; xx++)
	{
		if (n.find(Point(x + xx, y - 1)) != n.end())
			return false;
	}

	return true;
}

bool south(map<Point, Point>& n, int x, int y)
{
	for (int xx = -1; xx < 2; xx++)
	{
		if (n.find(Point(x + xx, y + 1)) != n.end())
			return false;
	}

	return true;
}

bool west(map<Point, Point>& n, int x, int y)
{
	for (int xx = -1; xx < 2; xx++)
	{
		if (n.find(Point(x - 1, y + xx)) != n.end())
			return false;
	}

	return true;
}

bool east(map<Point, Point>& n, int x, int y)
{
	for (int xx = -1; xx < 2; xx++)
	{
		if (n.find(Point(x + 1, y + xx)) != n.end())
			return false;
	}

	return true;
}


void draw(map<Point, Point>& n)
{
	int minx, miny, maxx, maxy;

	maxx = maxy = INT_MIN;
	minx = miny = INT_MAX;

	for (map<Point, Point>::iterator it = n.begin(); it != n.end(); it++)
	{
		int curx = get<0>(it->first), cury = get<1>(it->first);
		if (curx < minx) minx = curx;
		if (curx > maxx) maxx = curx;
		if (cury < miny) miny = cury;
		if (cury > maxy) maxy = cury;
	}

	for (int y = miny; y <= maxy; y++)
	{
		for (int x = minx; x <= maxx; x++)
		{
			if (n.find(Point(x, y)) != n.end())
			{
				cout << '#';
			}
			else {
				cout << '.';
			}
		}
		cout << '\n';
	}
	cout << "\n-----------\n";
}

int one_day23()
{
	fstream input;
	input.open("Day23.txt");

	string line;
	map<Point, Point> curr, dest, temp;
	multiset<Point> destSet;

	int minx, miny, maxx, maxy;
	
	maxx = maxy = INT_MIN;
	minx = miny = INT_MAX;

	int y = 0;

	while (!input.eof())
	{
		getline(input, line);
		for (int x = 0; x < line.length(); x++)
		{
			if (line[x] == '#')
				curr.insert(pair<Point, Point>(Point(x, y), Point(-1, -1)));
		}
		y++;		
	}

	int dir = 0;
	
	for (int i = 0; i < 10; i++)
	{
		for(map<Point, Point>::iterator it = curr.begin(); it != curr.end(); it++)
		{
			int curx = get<0>(it->first), cury = get<1>(it->first);
			switch (dir)
			{
			case 0:
				if (stay(curr, curx, cury))
				{
					dest.insert(pair<Point,Point>(Point(curx, cury), Point(curx, cury)));
					destSet.insert(Point(curx, cury));
				}
				else if (north(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury - 1)));
					destSet.insert(Point(curx, cury - 1));
				}
				else if (south(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury + 1)));
					destSet.insert(Point(curx, cury + 1));
				}
				else if (west(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx - 1, cury)));
					destSet.insert(Point(curx - 1, cury));
				}
				else if (east(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx + 1, cury)));
					destSet.insert(Point(curx + 1, cury));
				}
				else {
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury)));
					destSet.insert(Point(curx, cury));
				}
				break;
			case 1:
				if (stay(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury)));
					destSet.insert(Point(curx, cury));
				}
				else if (south(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury + 1)));
					destSet.insert(Point(curx, cury + 1));
				}
				else if (west(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx - 1, cury)));
					destSet.insert(Point(curx - 1, cury));
				}
				else if (east(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx + 1, cury)));
					destSet.insert(Point(curx + 1, cury));
				}
				else if (north(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury - 1)));
					destSet.insert(Point(curx, cury - 1));
				}
				else {
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury)));
					destSet.insert(Point(curx, cury));
				}
				break;
			case 2:
				if (stay(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury)));
					destSet.insert(Point(curx, cury));
				}
				else if (west(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx - 1, cury)));
					destSet.insert(Point(curx - 1, cury));
				}
				else if (east(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx + 1, cury)));
					destSet.insert(Point(curx + 1, cury));
				}
				else if (north(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury - 1)));
					destSet.insert(Point(curx, cury - 1));
				}
				else if (south(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury + 1)));
					destSet.insert(Point(curx, cury + 1));
				}
				else {
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury)));
					destSet.insert(Point(curx, cury));
				}
				break;
			case 3:
				if (stay(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury)));
					destSet.insert(Point(curx, cury));
				}
				else if (east(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx + 1, cury)));
					destSet.insert(Point(curx + 1, cury));
				}
				else if (north(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury - 1)));
					destSet.insert(Point(curx, cury - 1));
				}
				else if (south(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury + 1)));
					destSet.insert(Point(curx, cury + 1));
				}
				else if (west(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx - 1, cury)));
					destSet.insert(Point(curx - 1, cury));
				}
				else {
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury)));
					destSet.insert(Point(curx, cury));
				}
				break;
			default:
				break;
			}
		}

		for(map<Point, Point>::iterator it = curr.begin(); it != curr.end(); it++)
		{
			map<Point, Point>::iterator itd = dest.find(it->first);
			if (destSet.count(itd->second) == 1)
			{
				temp.insert(pair<Point, Point>(itd->second, Point(-1, -1)));
			}
			else {
				temp.insert(pair<Point, Point>(itd->first, Point(-1, -1)));
			}
		}

		

		curr.swap(temp);
		temp.clear();
		destSet.clear();
		dest.clear();

		dir = (dir + 1) % 4;
	}

	for(map<Point, Point>::iterator it = curr.begin(); it != curr.end(); it++)
	{
		int curx = get<0>(it->first), cury = get<1>(it->first);
		if (curx < minx) minx = curx;
		if (curx > maxx) maxx = curx;
		if (cury < miny) miny = cury;
		if (cury > maxy) maxy = cury;
	}

	return (maxx - minx + 1) * (maxy - miny + 1) - curr.size();
}

int two_day23()
{
	fstream input;
	input.open("Day23.txt");

	string line;
	map<Point, Point> curr, dest, temp;
	multiset<Point> destSet;

	int minx, miny, maxx, maxy;

	maxx = maxy = INT_MIN;
	minx = miny = INT_MAX;

	int y = 0;

	while (!input.eof())
	{
		getline(input, line);
		for (int x = 0; x < line.length(); x++)
		{
			if (line[x] == '#')
				curr.insert(pair<Point, Point>(Point(x, y), Point(-1, -1)));
		}
		y++;
	}

	int dir = 0;
	int rounds = 0;
	bool movement = true;

	while (movement)
	{
		movement = false;
		for (map<Point, Point>::iterator it = curr.begin(); it != curr.end(); it++)
		{
			int curx = get<0>(it->first), cury = get<1>(it->first);
			switch (dir)
			{
			case 0:
				if (stay(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury)));
					destSet.insert(Point(curx, cury));
				}
				else if (north(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury - 1)));
					destSet.insert(Point(curx, cury - 1));
					movement = true;
				}
				else if (south(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury + 1)));
					destSet.insert(Point(curx, cury + 1));
					movement = true;
				}
				else if (west(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx - 1, cury)));
					destSet.insert(Point(curx - 1, cury));
					movement = true;
				}
				else if (east(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx + 1, cury)));
					destSet.insert(Point(curx + 1, cury));
					movement = true;
				}
				else {
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury)));
					destSet.insert(Point(curx, cury));
				}
				break;
			case 1:
				if (stay(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury)));
					destSet.insert(Point(curx, cury));
				}
				else if (south(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury + 1)));
					destSet.insert(Point(curx, cury + 1));
					movement = true;
				}
				else if (west(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx - 1, cury)));
					destSet.insert(Point(curx - 1, cury));
					movement = true;
				}
				else if (east(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx + 1, cury)));
					destSet.insert(Point(curx + 1, cury));
					movement = true;
				}
				else if (north(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury - 1)));
					destSet.insert(Point(curx, cury - 1));
					movement = true;
				}
				else {
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury)));
					destSet.insert(Point(curx, cury));
				}
				break;
			case 2:
				if (stay(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury)));
					destSet.insert(Point(curx, cury));
				}
				else if (west(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx - 1, cury)));
					destSet.insert(Point(curx - 1, cury));
					movement = true;
				}
				else if (east(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx + 1, cury)));
					destSet.insert(Point(curx + 1, cury));
					movement = true;
				}
				else if (north(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury - 1)));
					destSet.insert(Point(curx, cury - 1));
					movement = true;
				}
				else if (south(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury + 1)));
					destSet.insert(Point(curx, cury + 1));
					movement = true;
				}
				else {
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury)));
					destSet.insert(Point(curx, cury));
				}
				break;
			case 3:
				if (stay(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury)));
					destSet.insert(Point(curx, cury));
				}
				else if (east(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx + 1, cury)));
					destSet.insert(Point(curx + 1, cury));
					movement = true;
				}
				else if (north(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury - 1)));
					destSet.insert(Point(curx, cury - 1));
					movement = true;
				}
				else if (south(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury + 1)));
					destSet.insert(Point(curx, cury + 1));
					movement = true;
				}
				else if (west(curr, curx, cury))
				{
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx - 1, cury)));
					destSet.insert(Point(curx - 1, cury));
					movement = true;
				}
				else {
					dest.insert(pair<Point, Point>(Point(curx, cury), Point(curx, cury)));
					destSet.insert(Point(curx, cury));
				}
				break;
			default:
				break;
			}
		}

		for (map<Point, Point>::iterator it = curr.begin(); it != curr.end(); it++)
		{
			map<Point, Point>::iterator itd = dest.find(it->first);
			if (destSet.count(itd->second) == 1)
			{
				temp.insert(pair<Point, Point>(itd->second, Point(-1, -1)));
			}
			else {
				temp.insert(pair<Point, Point>(itd->first, Point(-1, -1)));
			}
		}



		curr.swap(temp);
		temp.clear();
		destSet.clear();
		dest.clear();

		dir = (dir + 1) % 4;
		rounds += 1;
	}

	return rounds;
}

int main23()
{
	cout << one_day23();
	cout << "\n";
	cout << two_day23();

	return 0;
}