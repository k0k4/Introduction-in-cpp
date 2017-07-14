#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

//class to write temperature data into a .txt file
struct Writing
{
	int temperature; // temperature in fahrenheit
	char unit;
	Writing(char c, int t) :unit(c), temperature(t) {}
	Writing() :unit('x'), temperature(0){}
};

ostream& operator<<(ostream& os, Writing& w)
{
	return os << w.unit << " " << w.temperature;
}

void fill_file(ostream& os)
{
	Writing w;

	for (int i = 0; i < 50; i++)
	{
		if (i % 2 == 0)
		{
			w.unit = 'f';
			w.temperature = rand() % 100;
		}
		else
		{
			w.unit = 'c';
			w.temperature = rand() % 30;
		}
		
		os << w << "\n";
	}
}

void main()
{
	string fileName = ".//raw_temps.txt";
	ofstream ostr(fileName.c_str());
	if (!ostr) cout << "Error reading file";
	fill_file(ostr);
	
	
	char cc; cin >> cc;
}