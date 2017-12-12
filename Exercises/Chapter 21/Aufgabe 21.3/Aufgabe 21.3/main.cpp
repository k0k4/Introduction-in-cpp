#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <string>
using namespace std;

void makemap(map<string, int>& m)
{
	m["Peter"] = 23;
	m["Lori"] = 25;
	m["Hans"] = 30;
	m["Jana"] = 10;
	m["Tim"] = 5;
	m["Simone"] = 8;
	m["Samson"] = 70;
	m["Rita"] = 40;
	m["Joerg"] = 35;
	m["Greta"] = 53;
	m["Dieter"] = 39;
}
template<class T1, class T2>
void print_map(const map<T1, T2>& m)
{
	typedef map<T1,T2>::const_iterator map_iter;
	for (map_iter p = m.begin(); p != m.end(); ++p)
		cout << p->first << "\t" << p->second << "\n";
}

void del_map(map<string, int>& m)
{
	m.erase(m.begin(), m.end());
}

void read_map(map<string, int>& m, int n)
{
	ifstream is("Data.txt");
	string name;
	int age;
	for (int i = 0; i < n; i++)
	{
		is >> name >> age;
		m[name] = age;
	}
}

int sum_map(const map<string, int>& m)
{
	int sum = 0;
	for (map<string, int>::const_iterator p = m.begin(); p != m.end(); ++p)
		sum += p->second;

	return sum;
}

void copy_reverse(const map<string,int>& m1, map<int,string>& m2)
{
	map<string, int>::const_iterator p = m1.begin();
	while (p != m1.end())
	{
		m2[p->second] = p->first;
		++p;
	}
}

int main()
{
	map<string, int> mymap;
	makemap(mymap);
	del_map(mymap);
	read_map(mymap, 10);
	print_map(mymap);
	cout << "age sum = " << sum_map(mymap) << "\n";
	map<int, string> pamym;
	copy_reverse(mymap, pamym);
	print_map(pamym);

	char cc; cin >> cc;
}