#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <tuple>
#include <vector>


using namespace std;

#define Point tuple<int,int>

int one_day9()
{
	fstream input;
	input.open("Day9.txt");

	string line;

	set<tuple<int, int>> tailPath;

	tailPath.insert(Point(0, 0));

	int hx = 0, hy = 0, tx = 0, ty = 0;
	tailPath.insert(Point(0, 0));

	while (!input.eof())
	{
		getline(input, line);
		int dist = stoi(line.substr(2, line.size() - 2));
		
		switch (line[0]) {
		case 'U':
			for (int i = 0; i < dist; i++)
			{
				hy++;
				if (hx == tx)
				{
					if (ty + 1 < hy)
					{
						ty++;
						tailPath.insert(Point(tx, ty));
					}
				}
				else if (hx > tx) {
					if (ty + 1 < hy)
					{
						tx++;
						ty++;
						tailPath.insert(Point(tx, ty));
					}
				}
				else
				{
					if (ty + 1 < hy)
					{
						tx--;
						ty++;
						tailPath.insert(Point(tx, ty));
					}
				}
			}
			break;
		case 'D':
			for (int i = 0; i < dist; i++)
			{
				hy--;
				if (hx == tx)
				{
					if (ty - 1 > hy)
					{
						ty--;
						tailPath.insert(Point(tx, ty));
					}
				}
				else if (hx > tx) {
					if (ty - 1 > hy)
					{
						tx++;
						ty--;
						tailPath.insert(Point(tx, ty));
					}
				}
				else
				{
					if (ty - 1 > hy)
					{
						tx--;
						ty--;
						tailPath.insert(Point(tx, ty));
					}
				}
			}
			break;
		case 'L':
			for (int i = 0; i < dist; i++)
			{
				hx--;
				if (hy == ty)
				{
					if (tx - 1 > hx)
					{
						tx--;
						tailPath.insert(Point(tx, ty));
					}
				}
				else if (hy > ty) {
					if (tx - 1 > hx)
					{
						tx--;
						ty++;
						tailPath.insert(Point(tx, ty));
					}
				}
				else
				{
					if (tx - 1 > hx)
					{
						tx--;
						ty--;
						tailPath.insert(Point(tx, ty));
					}
				}
			}
			break;
		case 'R':
			for (int i = 0; i < dist; i++)
			{
				hx++;
				if (hy == ty)
				{
					if (tx + 1 < hx)
					{
						tx++;
						tailPath.insert(Point(tx, ty));
					}
				}
				else if (hy > ty) {
					if (tx + 1 < hx)
					{
						tx++;
						ty++;
						tailPath.insert(Point(tx, ty));
					}
				}
				else
				{
					if (tx + 1 < hx)
					{
						tx++;
						ty--;
						tailPath.insert(Point(tx, ty));
					}
				}
			}
			break;
		default:
			break;
		}
	}



	return tailPath.size();
}

Point move(char dir, int hx, int hy, int tx, int ty)
{
	int x = tx, y = ty;
	if (tx + 1 < hx)
	{
		x++;
		if (ty < hy)
			y++;
		if (ty > hy)
			y--;
	}
	else if (tx - 1 > hx)
	{
		x--;
		if (ty < hy)
			y++;
		if (ty > hy)
			y--;
	}
	else if (ty + 1 < hy)
	{
		y++;
		if (tx < hx)
			x++;
		if (tx > hx)
			x--;
	}
	else if (ty - 1 > hy)
	{
		y--;
		if (tx < hx)
			x++;
		if (tx > hx)
			x--;
	}
	return Point(x, y);
}

void draw(vector<int> x, vector<int> y)
{
	set<Point> temp;
	for (int i = 0; i < x.size(); i++)
	{
		temp.insert(Point(x[i], y[i]));
	}

	for (int yy = 15; yy > -6; yy--)
	{
		for (int xx = -11; xx < 15; xx++)
		{
			if (temp.find(Point(xx, yy)) != temp.end())
			{
				for (int i = 0; i < x.size(); i++)
				{
					if (xx == x[i] && yy == y[i])
					{
						cout << i;
						break;
					}
				}
			}
			else {
				cout << '.';
			}
		}
		cout << '\n';
	}

	cout << "\n\n\n-------------------------------------\n\n\n";
}

int two_day9()
{
	fstream input;
	input.open("Day9.txt");

	string line;

	set<tuple<int, int>> tailPath;
	tailPath.insert(Point(0, 0));

	vector<int> x(10,0), y(10, 0);

	while (!input.eof())
	{

		getline(input, line);
		int dist = stoi(line.substr(2, line.size() - 2));

		for (int i = 0; i < dist; i++)
		{
			switch (line[0]) {
			case 'U':
				y[0]++;
				break;
			case 'D':
				y[0]--;
				break;
			case 'L':
				x[0]--;
				break;
			case 'R':
				x[0]++;
				break;
			default:
				break;
			}
				
			for (int knot = 0; knot < 9; knot++)
			{
				Point temp = move(line[0], x[knot], y[knot], x[knot + 1], y[knot + 1]);
				x[knot + 1] = get<0>(temp);
				y[knot + 1] = get<1>(temp);
 			}

			tailPath.insert(Point(x[9], y[9]));

		}
	}

	return tailPath.size();
}

int main9()
{
	cout << one_day9();
	cout << "\n";
	cout << two_day9();

	return 0;
}