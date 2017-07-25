#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Big to small alpha
void swatch(string& s)
{
	for (int i = 0; i < s.size(); i++)
		s[i] = tolower(s[i]);
}

// Read file and change big to small alpha and save in antoher file
void read_and_switch(string file, string savefile)
{
	ifstream is(file.c_str());
	ofstream os(savefile.c_str());
	string read;

	while (getline(is, read))
	{
		swatch(read);
		os << read << '\n' ;
	}
		
}


int main()
{
	string file = ".\\Test.txt";

	read_and_switch(file, ".\\output.txt");

	char cc; cin >> cc;
}