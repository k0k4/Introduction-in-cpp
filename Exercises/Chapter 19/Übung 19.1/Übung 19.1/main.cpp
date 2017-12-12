#include <vector>
#include <iostream>

using namespace std;

template<class T> void f(vector<T>& t, const vector<T>& t2)
{
	if (t.size() != t2.size())
		cout << "Error, different size\n";
	else
		for (int i = 0; i < t.size(); i++)
			t[i] += t2[i];

	for (int i = 0; i < t.size(); i++)
	{
		cout << t[i] << "\n";
	}
}

template<class T> void squareV(const vector<T>& vt, const vector<T>& vu)
{
	if (vt.size() != vu.size())
		cout << "Error, different size\n";
	else
		for (int i = 0; i < vt.size(); i++)
			cout << vt[i]*vu[i] << "\n";
	
}


int main()
{
	vector<int> a{ 1,2,3,4,5 };
	vector<int> b{ 1,2,3,4,5 };

	vector<double> c{ 1.1,2.2,3.3,4.4,5.5 };
	vector<double> d{ 1.1,2.2,3.3,4.4,5.5 };

	f(a, b);
	f(c, d);
	squareV(a, b);
	
	char cc; cin >> cc;
}