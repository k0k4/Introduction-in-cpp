#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Store temps for processing
void store_temps(ifstream& is, vector<double>& v)
{
	double temp;
	char c;
	while (is >> c)
	{
		
		if (c == 'c')
		{
			is >> temp;
			temp = (9 / 5) * (temp + 32);
		}
		else
			is >> temp;
			
		v.push_back(temp);
		
	}
		

}

//Calculate average number of vector
double cal_average(const vector<double>& v)
{
	double av = 0;
	for (int i = 0; i < v.size(); i++)
		av += v[i];

	av /= v.size();

	return av;
}

void main()
{
	//Open file for reading
	string fileName = "C:\\Users\\Koka\\Documents\\Visual Studio 2015\\Projects\\Aufgabe10.2\\Aufgabe10.2\\raw_temps.txt";
	ifstream istr(fileName.c_str());
	if (!istr) cout << "Could not read file";

	vector<double>temps;
	store_temps(istr, temps);
	double av = cal_average(temps);
	
	cout << "Average = " << av;

	

	char cc; cin >> cc;
}