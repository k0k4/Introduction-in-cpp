#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
//proof if char is vokal
bool isVokal(char c)
{
	switch (c)
	{
	case 'a': case 'e': case 'i': case 'o': case 'u': case 'ö': case 'ä': case 'ü':
		return true;
		break;
	default:
		return false;
		break;
	}
}
//delete vokals from string and return new string without vokals
string del_vokal_string(string s)
{
	string newstring;

	for (int i = 0; i < s.size(); i++)
	{
		if (isVokal(s[i]))
			continue;
		else
			newstring += s[i];
	}

	return newstring;
}

//delete vokals from file
void del_vokals_file(string file)
{
	
	ifstream is(file.c_str());
	string read, out;
	vector<string>wiVokals;

	while (getline(is, read))
	{
		out = del_vokal_string(read);
		wiVokals.push_back(out);
	}
	
	ofstream os(file.c_str());
	for (int i = 0; i < wiVokals.size(); i++)
		os << wiVokals[i] << '\n';
}



int main()
{
	string file = ".\\Test.txt";

	del_vokals_file(file);

	char cc; cin >> cc;
}