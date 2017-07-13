#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(const vector<int>& v, string s)
{
	
	cout << s << ":" << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
}

void fibonacci(int x, int y, vector<int>& v, int n)
{
	v.push_back(x);
	v.push_back(y);

	int a = x, b = y;

	while (v.size() < n)
	{
		int temp = a + b;
		v.push_back(temp);
		a = b;
		b = temp;
	}
}

int main()
{
	vector<int>v;
	fibonacci(10, 11, v, 10);
	print(v,"Ausgabe");

	char cc; cin >> cc;
}