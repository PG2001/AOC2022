#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class Tree {
	public:
		vector<Tree*> children;
		Tree *parent;
		string name;
		bool isDir;
		int size;

		Tree() {
			size = 0;
			parent = 0;
			isDir = false;
		}

		int CalcSize()
		{
			if (size > 0)
				return size;

			for (int i = 0; i < children.size(); i++)
			{
				size += children[i]->CalcSize();
			}

			return size;
		}

		int SizeLT100k()
		{
			if (!isDir)
				return 0;

			int temp = 0;

			if (size <= 100000)
				temp = size;
			
			for (int i = 0; i < children.size(); i++)
				if (children[i]->isDir)
					temp += children[i]->SizeLT100k();

			return temp;
		}

		int findDirClosetToButGTX(int x, int currX)
		{
			if (!isDir)
				return currX;

			if (size < x)
				return currX;

			currX = size;

			for (int i = 0; i < children.size(); i++)
			{
				if (children[i]->isDir)
				{
					int temp = children[i]->findDirClosetToButGTX(x, currX);
					if (temp < currX) {
						currX = temp;
					}
				}
			}
			return currX;
		}
};


int one_day7()
{
	fstream input;
	input.open("Day7.txt");

	Tree *topDir;
	topDir = new Tree();
	topDir->isDir = true;

	Tree *curDir = topDir;

	while (!input.eof()) {
		string line;
		getline(input, line);

		if (line[0] == '$')
		{			
			if (line[2] == 'l')
			{
				continue;
			}
			else if (line[2] == 'c')
			{
				stringstream ss(line);
				string d, command, dir;
				ss >> d >> command >> dir;

				if (dir[0] == '/')
				{
					curDir = topDir;
				}
				else if (dir[0] == '.') {
					curDir = curDir->parent;
				}
				else {
					for (int i = 0; i < curDir->children.size(); i++)
					{
						if (curDir->children[i]->name == dir)
						{
							curDir = curDir->children[i];
							break;
						}
					}
				}
			}
		}
			
		if (line[0] == 'd')
		{
			Tree *temp = new Tree();

			stringstream ss(line);
			string dir, name;
			ss >> dir >> name;

			temp->name = name;
			temp->parent = curDir;
			temp->isDir = true;

			curDir->children.push_back(temp);
		}

		if (isdigit(line[0]))
		{
			Tree* temp = new Tree();

			stringstream ss(line);
			string name;
			int size;

			ss >> size >> name;

			temp->name = name;
			temp->parent = curDir;
			temp->size = size;

			curDir->children.push_back(temp);
		}

	}

	topDir->CalcSize();

	int x = topDir->SizeLT100k();

	return x;
}


int two_day7()
{
	fstream input;
	input.open("Day7.txt");

	Tree* topDir;
	topDir = new Tree();
	topDir->isDir = true;

	Tree* curDir = topDir;

	while (!input.eof()) {
		string line;
		getline(input, line);

		if (line[0] == '$')
		{
			if (line[2] == 'l')
			{
				continue;
			}
			else if (line[2] == 'c')
			{
				stringstream ss(line);
				string d, command, dir;
				ss >> d >> command >> dir;

				if (dir[0] == '/')
				{
					curDir = topDir;
				}
				else if (dir[0] == '.') {
					curDir = curDir->parent;
				}
				else {
					for (int i = 0; i < curDir->children.size(); i++)
					{
						if (curDir->children[i]->name == dir)
						{
							curDir = curDir->children[i];
							break;
						}
					}
				}
			}
		}

		if (line[0] == 'd')
		{
			Tree* temp = new Tree();

			stringstream ss(line);
			string dir, name;
			ss >> dir >> name;

			temp->name = name;
			temp->parent = curDir;
			temp->isDir = true;

			curDir->children.push_back(temp);
		}

		if (isdigit(line[0]))
		{
			Tree* temp = new Tree();

			stringstream ss(line);
			string name;
			int size;

			ss >> size >> name;

			temp->name = name;
			temp->parent = curDir;
			temp->size = size;

			curDir->children.push_back(temp);
		}

	}

	topDir->CalcSize();

	int totalSpace = 70000000, spaceNeeded = 30000000, currSpace = topDir->size;
	int unusedSpace = totalSpace - currSpace;
	int needToDelete = spaceNeeded - unusedSpace;

	return topDir->findDirClosetToButGTX(needToDelete, topDir->size);
}


int main7()
{
	cout << one_day7() << "\n";
	cout << two_day7() << '\n';

	return 0;
}