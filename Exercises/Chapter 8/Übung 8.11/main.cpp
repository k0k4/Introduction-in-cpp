#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

struct v_werte
{
	double max, min, zentralwert, mittelwert;
};

v_werte maxv(const vector<double>& v)
{
	v_werte ergebnis ;
	ergebnis.max = v[0], ergebnis.min = v[0], ergebnis.zentralwert = 0, ergebnis.mittelwert = 0;

	//berechne max
	for (int i = 1; i < v.size(); i++)
		if (v[i] > ergebnis.max)
			ergebnis.max = v[i];

	//berechne min
	for (int i = 0; i < v.size(); i++)
		if (v[i] < ergebnis.min)
			ergebnis.min = v[i];
	//berechne mittelwert
	for (int i = 0; i < v.size(); i++)
	{
		ergebnis.mittelwert = ergebnis.mittelwert + v[i];
	}
	ergebnis.mittelwert = ergebnis.mittelwert / v.size();
	//berechne zentralwert
	if (v.size() % 2 == 0)
	{
		ergebnis.zentralwert = (v[v.size() / 2] + v[v.size() + 1]) / 2;
	}

	else
		ergebnis.zentralwert = v[(v.size() ) / 2];

	return ergebnis;
}

int main()
{
	vector<double> test;

	test.push_back(4);
	test.push_back(6);
	test.push_back(10);
	test.push_back(2);
	test.push_back(4);

	v_werte testV = maxv(test);

	cout << "Max: " << testV.max << "\n" << "Min: " << testV.min << "\n" << "Mittelwert: " << testV.mittelwert << "\n" << "Zentralwert: " << testV.zentralwert << "\n" << test.size();

	char cc; cin >> cc;
}