#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void copy_list(list<int>& l, vector<double>& v)
{
	list<int>::iterator p = l.begin();
	while (p != l.end())
	{
		v.push_back(*p);
		++p;
	}
	sort(v.begin(), v.end());
}

int main()
{
	vector<double> v = vector<double>();
	list<int> l = { 1,6,8,4,5 };
	copy_list(l, v);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ", ";

	char cc; cin >> cc;
}