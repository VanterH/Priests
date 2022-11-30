#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	ifstream in("in.txt");
	string s;
	getline(in, s);

	int gr = stoi(s);
	int num;

	cout << gr << endl;
	int a, b;
	int* spisok = new int[gr];

	getline(in, s);

	char* chars = &s[0];

	int c1 = 0, temp = 0, c2 = 0;

	while (chars[c1] != NULL)
	{
		temp = temp * 10 + ((int)chars[c1] - 48);
		if (chars[c1 + 1] == ' ')
		{
			spisok[c2] = temp;
			temp = 0;
			c2++;
			c1++;
		}
		if (chars[c1 + 1] == NULL)
		{
			spisok[c2] = temp;
			break;
		}
		c1++;
	}

	for (int i = 0; i < gr; i++)
	{
		cout << spisok[i] << " ";
	}

	cout << endl;
	getline(in, s);
	
	while (in >> a >> b)
	{
		cout << a << " " << b << endl;
		for (int i = 0; i < gr; i++)
		{
			if (spisok[i] == a)
			{
				spisok[i] = b + 1000;
			}
		}
	}
	for (int i = 0; i < gr; i++)
	{
		if (spisok[i] > 1000)
		{
			spisok[i] -= 1000;
		}
	}	
	
	cout << "Res: ";
	
	for (int i = 0; i < gr; i++)
	{
		cout << spisok[i] << " ";
	}
	
	delete[] spisok;
}

