#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<string> v = { "Das", "Der", "Die", "Dem ","Dann","Doch" };

	vector<string>::iterator i = v.begin();
	string last = *i;
	while (i != v.end())
	{
		if (*i > last)
			last = *i;
		else
			++i;
	}
	cout << last;
	char cc; cin >> cc;
}