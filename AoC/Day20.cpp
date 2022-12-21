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

class Node {
public:
	long long value;
	bool notMoved = true;
	Node* next;
	Node* prev;
};

void print(Node* in)
{
	Node* temp = in;
	while (temp->next != in)
	{
		cout << temp->value << ' ';
		temp = temp->next;
	}
	cout << temp->value << "\n\n\n";
}

void Move(Node* l, Node* r)
{
	l->prev->next = l->next;
	l->next->prev = l->prev;
	l->prev = r;
	l->next = r->next;
	r->next->prev = l;
	r->next = l;
}

long long one_day20()
{
	fstream input;
	input.open("Day20.txt");

	
	Node* head = new Node();
	Node* next = head;

	vector<Node> list;

	int zero;

	while (!input.eof()) {
		string line;
		getline(input, line);

		next->value = stoll(line);	

		Node t;
		t.value = next->value;
		t.next = next;
		list.push_back(t);

		if (next->value == 0)
		{
			zero = list.size() - 1;
		}

		if (input.eof())
		{
			head->prev = next;
			next->next = head;
			continue;
		}
		next->next = new Node();
		next->next->prev = next;
		next = next->next;		
	}


	for (int i = 0; i < list.size(); i++)
	{
		Node* temp = list[i].next;
		long long count = temp->value;		
		if (count == 0) continue;
		if (count > 0)
		{
			count = count % (list.size() - 1);	
			if (count == 0) continue;
			Node* z = temp;
			for (long long c = 0; c < count; c++)
			{
				z = z->next;
			}
			Move(temp, z);
		}
		else {
			count = -count;
			count = count % (list.size() - 1);
			if (count == 0) continue;
			Node* z = temp;
			for (long long c = 0; c < count + 1; c++)
			{
				z = z->prev;
			}
			Move(temp, z);
		}
		/*save(list[zero].next, "File" + to_string(i) + ".txt");
		if (i > 4654)
			int asdlkfaj = 7;*/
	}

	Node* curr = list[zero].next;
	long long result = 0;

	for (int i = zero + 1; i < zero + 3001; i++)
	{
		curr = curr->next;
		if (zero + 1000 == i)
			result += curr->value;
		if (zero + 2000 == i)
			result += curr->value;
		if (zero + 3000 == i)
			result += curr->value;
	}



	return result;
}

long long two_day20()
{
	fstream input;
	input.open("Day20.txt");


	Node* head = new Node();
	Node* next = head;
	
	vector<Node> list;

	int zero;

	while (!input.eof()) {
		string line;
		getline(input, line);

		next->value = stoll (line) * 811589153;

		Node t;
		t.value = next->value;
		t.next = next;
		list.push_back(t);

		if (next->value == 0)
		{
			zero = list.size() - 1;
		}

		if (input.eof())
		{
			head->prev = next;
			next->next = head;
			continue;
		}
		next->next = new Node();
		next->next->prev = next;
		next = next->next;
	}


	for (int h = 0; h < 10; h++)
	{
		for (int i = 0; i < list.size(); i++)
		{
			Node* temp = list[i].next;
			long long count = temp->value;
			if (count == 0) continue;
			if (count > 0)
			{
				count = count % (list.size() - 1);
				if (count == 0) continue;
				Node* z = temp;
				for (long long c = 0; c < count; c++)
				{
					z = z->next;
				}
				Move(temp, z);
			}
			else {
				count = -count;
				count = count % (list.size() - 1);
				if (count == 0) continue;
				Node* z = temp;
				for (long long c = 0; c < count + 1; c++)
				{

					z = z->prev;
				}
				Move(temp, z);
			}
		}
	}


	Node* curr = list[zero].next;
	long long result = 0;
	for (int i = zero + 1; i < zero + 3001; i++)
	{
		curr = curr->next;
		if (zero + 1000 == i)
			result += curr->value;
		if (zero + 2000 == i)
			result += curr->value;
		if (zero + 3000 == i)
			result += curr->value;
	}

	return result;
}


int main20()
{
	cout << one_day20() << "\n";
	cout << two_day20() << '\n';

	return 0;
}