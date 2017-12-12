#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;

void read_data(vector<double>& v)
{
	ifstream is("Data.txt");
	double input = 0.0;
	while (is >> input)
		v.push_back(input);
}
template<class T>
void print_data(vector<T>& v)
{
	ostream_iterator<T> oo(cout);
	for (int i = 0; i < v.size(); i++)
	{
		*oo = v[i];
		++oo;
		cout << "\n";
	}
}

double dsum(vector<double>& vd)
{
	return accumulate(vd.begin(), vd.end(), 0.0);
}

int isum(vector<int>& vd)
{
	return accumulate(vd.begin(), vd.end(), 0);
}
int main()
{
	vector<double> vd;
	read_data(vd);
	print_data(vd);
	vector<int> vi(vd.size());
	copy(vd.begin(), vd.end(), vi.begin());
	print_data(vi);
	cout << "vd summe = "<< dsum(vd) << "\n";
	cout << "vd summe - vi summe = " << dsum(vd) - isum(vi) << "\n";
	reverse(vd.begin(), vd.end());
	print_data(vd);

	char cc; cin >> cc;
}