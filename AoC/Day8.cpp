#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

bool checkVis(vector<vector<int>>& f, int r, int c)
{
	bool left, right, up, down;
	left = right = up = down = true;

	for (int rr = r-1; rr >= 0; rr--)
	{
		if (f[c][rr] >= f[c][r])
			left = false;
	}
	for (int rr = r + 1; rr < f[c].size(); rr++)
	{
		if (f[c][rr] >= f[c][r])
			right = false;
	}
	for (int cc = c - 1; cc >= 0; cc--)
	{
		if (f[cc][r] >= f[c][r])
			up = false;
	}
	for (int cc = c + 1; cc < f.size(); cc++)
	{
		if (f[cc][r] >= f[c][r])
			down = false;
	}

	return left || up || right || down;
}

int one_day8()
{
	fstream input;
	input.open("Day8.txt");

	string line;

	vector<vector<int>> f;


	while (!input.eof())
	{
		getline(input, line);
		vector<int> t;
		for (int i = 0; i < line.size(); i++)
		{
			t.push_back(line[i] - '0');
		}

		f.push_back(t);
	}


	int vis = f.size() * 2 + (f[0].size() - 2) * 2;

	for (int c = 1; c < f.size() - 1; c++)
		for (int r = 1; r < f[0].size() - 1; r++)
			if (checkVis(f, r, c))
				vis++;


	return vis;
}

int countTrees(vector<vector<int>>& f, int r, int c)
{
	int left, right, up, down;
	left = right = up = down = 0;

	for (int rr = r - 1; rr >= 0; rr--)
	{

			up++;
		if(f[rr][c] >= f[r][c])
			break;
	}
	for (int rr = r + 1; rr < f[c].size(); rr++)
	{

			down++;
		if (f[rr][c] >= f[r][c])
			break;
	}
	for (int cc = c - 1; cc >= 0; cc--)
	{
			left++;
		if (f[r][cc] >= f[r][c])
			break;
	}
	for (int cc = c + 1; cc < f.size(); cc++)
	{

			right++;
		if (f[r][cc] >= f[r][c])
			break;
	}

	return left * right * up * down;
}

int two_day8()
{
	fstream input;
	input.open("Day8.txt");

	string line;

	vector<vector<int>> f;

	int max = 0;

	while (!input.eof())
	{
		getline(input, line);
		vector<int> t;
		for (int i = 0; i < line.size(); i++)
		{
			t.push_back(line[i] - '0');
		}

		f.push_back(t);
	}

	for (int r = 1; r < f.size() - 1; r++)
		for (int c = 1; c < f[0].size() - 1; c++)
		{
			int temp = countTrees(f, r, c);
			if (temp > max)
				max = temp;
		}


	return max;
}
int main8()
{
	//cout << one_day8();
	cout << "\n";
	cout << two_day8();

	return 0;
}