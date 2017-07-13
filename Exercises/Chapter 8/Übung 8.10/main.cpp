#include <vector>
#include <iostream>

using namespace std;

double cal_index(vector<double>& gewicht, vector<double>& preis)
{
	double index = 0;

	if (gewicht.size() > preis.size())
	{
		cout << "Error: gewicht vector zu groß \n";
		return -1;
	}
		
	for (int i = 0; i < preis.size(); i++)
	{
		index = index + (preis[i] * gewicht[i]);
	}

	return index;
}

int main()
{

}