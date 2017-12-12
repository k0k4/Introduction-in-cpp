#include "Pair.h"
#include <vector>
#include <iostream>

using namespace std;



void put_asci()
{
	vector<Pair<char, int>> v;

	for (int i = 0; i < 128; i++)
	{
		char c = i;
		Pair<char, int> temp(c, i);
		v.push_back(temp);
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i].getP() << " -> " << v[i].getT() << "\n";
}

int main()
{
	put_asci();

	char cc; cin >> cc;
}